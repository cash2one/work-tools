#!/bin/bash
#
# cpu_rrd_stat.sh
# desc: save data to .rrd file every minute
# Created on: 2012-3-5
#  Author: lixingyi(lxyfirt@gmail.com)
#

cd $(dirname $0)

#network
awk -F':' '{if($1~/eth[0123456]$/ || $1~/lo/ ) print $1,$2;}' /proc/net/dev | awk '{if($2 >0) print $1,$2,$3,$10,$11;}' | while read if_name if_rx if_rp if_tx if_tp
do
	if_name=${if_name// }
	/usr/bin/rrdtool update ${if_name}.rrd N:$if_rx:$if_rp:$if_tx:$if_tp
done

#disk io
awk '{if($3~/[sh]d[abcdefgh]$/ && $4 > 0 ) printf("%s %d %d\n",$3,$6,$10); }' /proc/diskstats | while  read disk_name disk_rio disk_wio
do
	disk_name=${disk_name// }
	/usr/bin/rrdtool update ${disk_name}.rrd N:$disk_rio:$disk_wio
    
done 

#cpu
awk '{if($1~/^cpu/) {user=$2+$3 ;intr=$7+$8; printf("%s %d %d %d %d %d\n",$1,$5,user,$6,intr,user+$4+$5+$6+intr);} }' /proc/stat | while  read cpu_name cpu_idle cpu_user cpu_iowait cpu_intr cpu_total
do
	cpu_name=${cpu_name// }
	/usr/bin/rrdtool update ${cpu_name}.rrd N:$cpu_idle:$cpu_user:$cpu_iowait:$cpu_intr:$cpu_total
    
done 


awk '{if($1~/^MemTotal/) mem_total=$2;else if($1~/^MemFree/) mem_free=$2;else if($1~/^SwapTotal/) swap_total=$2;else if($1~/^SwapFree/) swap_free=$2;} END{printf("%d %d %d %d\n",mem_total,mem_free,swap_total,swap_free);}' /proc/meminfo | while  read mem_total mem_free swap_total swap_free
do
    /usr/bin/rrdtool update memory.rrd N:$mem_total:$mem_free:$swap_total:$swap_free
done

