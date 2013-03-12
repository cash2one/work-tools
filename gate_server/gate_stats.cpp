#include "gate_stats.h"
#include "gate_application.h"


GateStats::GateStats()
	:wan_traffic_per_second_ (0)
	, interval_ (10000)
{
	m_second_timer.set_owner(this);
}


void GateStats::Start()
{
	on_every_second_timer(&get_app().timer_engine);
}

void GateStats::on_every_second_timer( kingnet::timer_manager* manager)
{
	m_second_timer.set_expired(get_app().get_run_ms()+ interval_);
	manager->add_timer(&m_second_timer);

	//LogTraffic();
}

void GateStats::LogTraffic()
{
	double in_traffic = (double)wan_traffic_per_second_ * 1000 / (1024*1024) / interval_;
	double out_traffic = (double)wan_out_traffic_per_second_ * 1000/ (1024*1024) / interval_;

	traffic_stats_log_.insert(std::make_pair(kingnet::time_ms() / 1000, std::make_pair(in_traffic, out_traffic)));
	if (traffic_stats_log_.size() > traffic_stats_log_size)
	{
		traffic_stats_log_.erase(traffic_stats_log_.begin());
	}

#define LOG_DEBUG(fmt, args...) debug_log_format(get_app().logger, fmt, ##args)
	LOG_DEBUG("Online players: %d, traffic in: %.4f MB/s, traffic out: %.4f MB/s\n",
		get_app().uid2conn.size(),
		in_traffic,
		out_traffic);

	//clear wan_traffic_per_second_
	wan_traffic_per_second_ = 0;
	wan_out_traffic_per_second_ = 0;
}

void GateStats::do_query_traffic( const ss_traffic_stats_request& req, ss_traffic_stats_response* rep )
{
	rep->key = req.key;
	rep->seq = req.seq;

	int count = 1, i = 0;
	for (TrafficStatsLog::reverse_iterator it = traffic_stats_log_.rbegin();
			it!=traffic_stats_log_.rend() && i<count; ++it, ++i)
	{
		 ::protocols::common::TrafficStats* stats = rep->body.add_data();
		 if (stats == NULL)
			 return;
		 stats->set_tick_s(it->first);
		 stats->set_in_traffic(it->second.first);
		 stats->set_out_traffic(it->second.second);
	}
}



