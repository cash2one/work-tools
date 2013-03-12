#ifndef GATE_STATS_H
#define GATE_STATS_H

#include "timer_manager.h"
#include <assert.h>
#include <map>
#include "../public/message.h"

class GateStats
{
public:
	GateStats();

	void set_interval(int interval)
	{
		interval_ = interval;
	}

	void Start();

	void on_every_second_timer(kingnet::timer_manager* manager);
	void LogTraffic();
	void AddWanTraffic(int traffic, bool out_flag = false)
	{
		//assert(traffic >= 0);
		if (!out_flag)
			wan_traffic_per_second_ += traffic;
		else
			wan_out_traffic_per_second_ += traffic;
		
	}

	void do_query_traffic(const ss_traffic_stats_request& req, ss_traffic_stats_response* rep);

private:
	enum {traffic_stats_log_size = 60 };
	int wan_traffic_per_second_;
	int wan_out_traffic_per_second_;
	// sec tick, <in_traffic, out_traffic>
	typedef std::map<int, std::pair<double, double> > TrafficStatsLog;
	TrafficStatsLog traffic_stats_log_;
	
	kingnet::template_timer<GateStats,&GateStats::on_every_second_timer> m_second_timer ;
	int interval_;  // unit ms



};


#endif //GATE_STATS_H
