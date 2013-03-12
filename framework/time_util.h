/*
 * time_util.h
 *
 *  Created on: 2011-10-14
 *      Author: lxyfirst@yahoo.com.cn
 */

#ifndef TIME_UTIL_H_
#define TIME_UTIL_H_

#include <stdint.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

enum { SECONDS_HALF_HOUR = 1800, SECONDS_OF_HOUR = 3600, };
enum { SECONDS_OF_DAY = 24 * 3600, SECONDS_OF_WEEK = SECONDS_OF_DAY * 7, };  // ÿ�������
enum { LOCAL_TIME_ZONE = 8 * 3600 }; // ����ʱ��

extern long timezone;  // ����ʱ��ƫ��

namespace kingnet
{


//CPU's timestamp counter.
inline uint64_t rdtsc()
{
    uint32_t low, high;
    __asm__ volatile ("rdtsc" : "=a" (low), "=d" (high));
    return (uint64_t) high << 32 | low;
}

// millisecond
inline int64_t time_ms()
{
    struct timeval tv = {0} ;
    gettimeofday(&tv,NULL) ;
    return tv.tv_sec * 1000 + tv.tv_usec/1000 ;

}



// microsecond by gettimeofday
inline int64_t time_us()
{
    struct timeval tv = {0} ;
    gettimeofday(&tv,NULL) ;
    return tv.tv_sec * 1000000 + tv.tv_usec ;

}

// microsecond by clock , require librt
inline int64_t clock_us()
{
    struct timespec tv = {0} ;
    clock_gettime(CLOCK_MONOTONIC,&tv) ;
    return tv.tv_sec * 1000000 + tv.tv_nsec/1000 ;
}

// get tick counter per microsecond , may block 100 milliseconds
inline int64_t get_tsc_us()
{
    int64_t begin_tsc = rdtsc() ;
    int64_t begin_us = time_us() ;
    int64_t tsc_interval = 0 ;
    int64_t us_interval = 0 ;
    do
    {
        usleep(100000) ;
        tsc_interval = rdtsc() - begin_tsc  ;
        us_interval = time_us() - begin_us ;

    } while(us_interval < 1 || us_interval > (100000 << 3) ) ;

    return tsc_interval/us_interval ;
}

inline time_t str2time(const char* buf,const char* fmt)
{
    struct tm tmp_tm = {0} ;

    if ( strptime(buf,fmt,&tmp_tm) == NULL ) return 0 ;
    return mktime(&tmp_tm) ;
}

inline int time2str(char* buf,int maxlen ,const char* fmt,time_t t)
{
    struct tm tmp_tm;
    localtime_r(&t,&tmp_tm) ;
    return strftime(buf,maxlen,fmt,&tmp_tm) ;
}

// ��ȡ�����Ѿ���ȥ������
inline time_t get_seconds_elapsed_of_the_day(time_t cur_time = 0)
{
	time_t  zero_time ;
	if (cur_time == 0)
	{
		time(&cur_time);
	}
	
	struct tm  tmp_tm_time;
	localtime_r(&cur_time,&tmp_tm_time);
	tmp_tm_time.tm_hour = 0;
	tmp_tm_time.tm_min = 0;
	tmp_tm_time.tm_sec = 0;

	zero_time = mktime(&tmp_tm_time);

	return cur_time - zero_time ;
}

// ��ȡ��ǰ��tmʱ��
inline struct tm* get_current_tm_time(struct tm*  user_tm_time)
{
	time_t  cur_t;
	time(&cur_t);

	return localtime_r(&cur_t, user_tm_time);
}

// �ж����������Ƿ���ͬһ��
inline bool is_same_day(struct tm* first_tm, struct tm* second_tm)
{
	return (first_tm->tm_year == second_tm->tm_year
		&& first_tm->tm_mon == second_tm->tm_mon
		&& first_tm->tm_mday == second_tm->tm_mday);
}

inline void init_timezone()
{
	time_t  now;
	time(&now);

	struct tm local_time;
	localtime_r(&now, &local_time);

	// fprintf(stderr, "local time zone is %ld", timezone);
	// now extern long timezone is set to -28800
}

// �����������������ã��������
// should init_timezone() first
inline bool is_same_day(time_t first_t, time_t second_t, int default_day_seconds = SECONDS_OF_DAY)
{
	if (timezone == 0)
	{
		init_timezone();
	}
	return (first_t - timezone) / default_day_seconds == (second_t - timezone )/ default_day_seconds;
}

// ���Ƚ�ʱ����
inline int time_cmp(struct tm time_a, int hour, int min, int sec)
{
	if (time_a.tm_hour > hour)
	{
		return 1;
	}
	else if (time_a.tm_hour < hour)
	{
		return -1;
	}
	else
	{
		if (time_a.tm_min > min)
		{
			return 1;
		}
		else if (time_a.tm_min < min)
		{
			return -1;
		}
		else
		{
			if (time_a.tm_sec > sec)
			{
				return 1;
			}
			else if (time_a.tm_sec < sec)
			{
				return -1;
			}
			else
			{
				return 0;
			}
		}
	}
}

// �������ָ��ʱ�仹ʣ������
// hour [0-23] min[0-59] sec[0-59]
inline int32_t seconds_to_nearest_time(int hour, int min, int sec)
{
	struct tm  now;
	get_current_tm_time(&now);

	int32_t  sec_needs = 0;
	int cmp = time_cmp(now, hour, min, sec) ;
	if (cmp > 0) // ��ǰʱ�����ָ����ʱ��
	{
		sec_needs = SECONDS_OF_DAY - get_seconds_elapsed_of_the_day();
		sec_needs += hour * 3600 + min * 60 + sec;
		return sec_needs;
	}
	else if (cmp == 0)
	{
		return 0;
	}
	else // ��ǰʱ��С��ָ��ʱ��
	{
		sec_needs = (hour - now.tm_hour) * 3600 + (min - now.tm_min) * 60 - now.tm_sec + sec ;
		return sec_needs;
	}
}

// ��ȡ�����Ѿ���ȥ������
inline time_t get_seconds_elapsed_of_the_week(time_t now_sec = 0)
{
	if (now_sec == 0)
	{
		time(&now_sec);
	}

	struct tm  now_tm_time;
	localtime_r(&now_sec, &now_tm_time);

	return now_tm_time.tm_wday * SECONDS_OF_DAY + get_seconds_elapsed_of_the_day(now_sec);
}


// �Ƿ�Ϊͬһ�ܣ�Ĭ������Ϊһ�ܵĵ�һ��
inline bool is_same_week(time_t first_t, time_t second_t)
{
	if (first_t == 0 || second_t == 0)
	{
		return false;
	}

	if (abs(first_t - second_t) > SECONDS_OF_WEEK)
	{
		return false;
	}

	if (is_same_day(first_t, second_t))
	{
		return true;
	}

	// ��firstΪ��׼
	// �����Ѿ���ȥ��ʱ��
	int  elapsed_secs_of_week = get_seconds_elapsed_of_the_week(first_t);

	// ���ܻ�ʣ��ʱ��
	int  left_secs_of_week = SECONDS_OF_WEEK - elapsed_secs_of_week;

	if (second_t < first_t)
	{
		if (first_t - second_t > elapsed_secs_of_week)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		if (second_t - first_t > left_secs_of_week)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}


}


#endif /* TIME_UTIL_H_ */