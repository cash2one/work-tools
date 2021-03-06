#ifndef PUBLIC_UTIL_H
#define PUBLIC_UTIL_H

#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

std::vector<std::string> str_split(const std::string& src, std::string delimit, std::string null_subst = "");

int random(int min_num, int max_num);

class CBase64
{
public:
	CBase64();
	~CBase64();

	/*********************************************************
	* 函数说明：将输入数据进行base64编码
	* 参数说明：[in]pIn		需要进行编码的数据
				[in]uInLen  输入参数的字节数
				[out]strOut 输出的进行base64编码之后的字符串
	* 返回值  ：true处理成功,false失败
	* 作  者  ：ChenLi
	* 编写时间：2009-02-17
	**********************************************************/
	bool static Encode(const unsigned char *pIn, unsigned long uInLen, std::string& strOut);

	/*********************************************************
	* 函数说明：将输入数据进行base64编码
	* 参数说明：[in]pIn			需要进行编码的数据
				[in]uInLen		输入参数的字节数
				[out]pOut		输出的进行base64编码之后的字符串
				[out]uOutLen	输出的进行base64编码之后的字符串长度
	* 返回值  ：true处理成功,false失败
	* 作  者  ：ChenLi
	* 编写时间：2009-02-17
	**********************************************************/
	bool static Encode(const unsigned char *pIn, unsigned long uInLen, unsigned char *pOut, unsigned long *uOutLen);
	
	/*********************************************************
	* 函数说明：将输入数据进行base64解码
	* 参数说明：[in]strIn		需要进行解码的数据
				[out]pOut		输出解码之后的节数数据
				[out]uOutLen	输出的解码之后的字节数长度
	* 返回值  ：true处理成功,false失败
	* 作  者  ：ChenLi
	* 编写时间：2009-02-17
	**********************************************************/
	bool static Decode(const std::string& strIn, unsigned char *pOut, unsigned long *uOutLen) ;

	/*********************************************************
	* 函数说明：将输入数据进行base64解码
	* 参数说明：[in]strIn		需要进行解码的数据
				[out]pOut		输出解码之后的节数数据
				[out]uOutLen	输出的解码之后的字节数长度
	* 返回值  ：true处理成功,false失败
	* 作  者  ：ChenLi
	* 编写时间：2009-02-17
	**********************************************************/
	bool static Decode(const unsigned char *pIn, unsigned long uInLen, unsigned char *pOut, unsigned long *uOutLen) ;
};

static inline int bit_count_32(unsigned int i)
{
	i = i - ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	return (((i + (i >> 4)) & 0xF0F0F0F) * 0x1010101) >> 24;
}



namespace HttpUtility
{
	using namespace std;
	
	typedef unsigned char BYTE;

	inline BYTE toHex(const BYTE &x)
	{
		return x > 9 ? x -10 + 'A': x + '0';
	}

	inline BYTE fromHex(const BYTE &x)
	{
		return isdigit(x) ? x-'0' : x-'A'+10;
	}

	inline string RawUrlEncode(const string &sIn)
	{
		string sOut;
		for( size_t ix = 0; ix < sIn.size(); ix++ )
		{      
			BYTE buf[4];
			memset( buf, 0, 4 );
			if( isalnum( (BYTE)sIn[ix] ) )
			{      
				buf[0] = sIn[ix];
			}
			//else if ( isspace( (BYTE)sIn[ix] ) ) //貌似把空格编码成%20或者+都可以
			//{
			//    buf[0] = '+';
			//}
			else
			{
				buf[0] = '%';
				buf[1] = toHex( (BYTE)sIn[ix] >> 4 );
				buf[2] = toHex( (BYTE)sIn[ix] % 16);
			}
			sOut += (char *)buf;
		}
		return sOut;
	};

	inline string RawUrlDecode(const string &sIn)
	{
		string sOut;
		for( size_t ix = 0; ix < sIn.size(); ix++ )
		{
			BYTE ch = 0;
			if(sIn[ix]=='%')
			{
				ch = (fromHex(sIn[ix+1])<<4);
				ch |= fromHex(sIn[ix+2]);
				ix += 2;
			}
			else if(sIn[ix] == '+')
			{
				ch = ' ';
			}
			else
			{
				ch = sIn[ix];
			}
			sOut += (char)ch;
		}
		return sOut;
	}
}

time_t convert_string_to_time_t(const std::string & time_string);

#endif //PUBLIC_UTIL_H

