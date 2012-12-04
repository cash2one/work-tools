#!/bin/bash
#
# cpu_rrd_img.sh
# desc: generate .png file from .rrd file
# Created on: 2012-3-5
#  Author: lixingyi(lxyfirt@gmail.com)
#


cd $(dirname $0)


awk -F':' '{if($1~/eth[0123456]$/ || $1~/lo/ ) print $1,$2;}' /proc/net/dev | awk '{if($2>0) print $1}' | while read if_name
do
#        -y 10:10 -u 100 -l 0                                             \
    if_name=${if_name// }
    echo "creating [${if_name}.png]  ..."
    /usr/bin/rrdtool graph "${if_name}.png"                    \
        -s -86400                                              \
        -w 500 -h 100                                          \
        -x MINUTE:30:HOUR:2:HOUR:2:0:%H:%M                     \
        -Y  -t "${if_name} traffic"                            \
        DEF:rx=${if_name}.rrd:rx:AVERAGE                       \
        DEF:tx=${if_name}.rrd:tx:AVERAGE                       \
        CDEF:rx_bps=rx,1,\/                                    \
        CDEF:tx_bps=tx,1,\/                                    \
        LINE1:rx_bps#FF0000:"rx(bytes)"                        \
	    LINE1:tx_bps#00FF00:"tx(bytes)"                        \

    /usr/bin/rrdtool graph "${if_name}_packet.png"             \
        -s -86400                                              \
        -w 500 -h 100                                          \
        -x MINUTE:30:HOUR:2:HOUR:2:0:%H:%M                     \
        -Y  -t "${if_name} packet"                             \
        DEF:rp=${if_name}.rrd:rp:AVERAGE                       \
        DEF:tp=${if_name}.rrd:tp:AVERAGE                       \
        CDEF:rp_bps=rp,1,\/                                    \
        CDEF:tp_bps=tp,1,\/                                    \
        LINE1:rp_bps#FF0000:"rp()"                             \
        LINE1:tp_bps#00FF00:"tp()"                                   


 
done

awk '{if($3~/[sh]d[abcdefgh]$/ && $4 > 0 ) print $3;}' /proc/diskstats | while read disk_name
do
    disk_name=${disk_name// }
    echo "creating [${disk_name}.png]  ..."
    /usr/bin/rrdtool graph "${disk_name}.png"    \
        -s -86400                                              \
        -w 500 -h 100                                          \
        -x MINUTE:30:HOUR:2:HOUR:2:0:%H:%M                \
        -Y -t "${disk_name} io"                         \
        DEF:rio=${disk_name}.rrd:rio:AVERAGE                       \
        DEF:wio=${disk_name}.rrd:wio:AVERAGE                       \
        CDEF:rio_sector=rio,1,\/                              \
        CDEF:wio_sector=wio,1,\/                              \
        LINE1:rio_sector#00FF00:"rio(sector)"                        \
	LINE1:wio_sector#FF0000:"wio(sector)"                                   

 
done



awk '{if($1~/^cpu/) print $1;}' /proc/stat | while  read cpu_name 
do
    cpu_name=${cpu_name// }
    echo "creating [${cpu_name}.png]  ..."
    /usr/bin/rrdtool graph "${cpu_name}.png"      \
        -s -86400                                               \
        -w 500 -h 100                                           \
        -x MINUTE:30:HOUR:2:HOUR:2:0:%H:%M                \
        -Y  -t "${cpu_name} usage"                          \
        DEF:idle=${cpu_name}.rrd:idle:AVERAGE                   \
        DEF:user=${cpu_name}.rrd:user:AVERAGE                   \
        DEF:iowait=${cpu_name}.rrd:iowait:AVERAGE                   \
        DEF:intr=${cpu_name}.rrd:intr:AVERAGE                   \
        DEF:total=${cpu_name}.rrd:total:AVERAGE                 \
        CDEF:idle_persent=idle,total,\/,100,\*                         \
        CDEF:user_persent=user,total,\/,100,\*                         \
        CDEF:iowait_persent=iowait,total,\/,100,\*                         \
        CDEF:intr_persent=intr,total,\/,100,\*                         \
        LINE1:idle_persent#00FF00:"idle(%)"                        \
        LINE1:user_persent#0000FF:"user(%)"                        \
        LINE1:iowait_persent#FF0000:"iowait(%)"                    \
        LINE1:intr_persent#FF00FF:"intr(%)"                        
    
done  

   rrd_name="memory"
    echo "creating [${rrd_name}.png]  ..."
    /usr/bin/rrdtool graph "${rrd_name}.png"      \
        -s -86400                                               \
        -w 500 -h 100                                           \
        -x MINUTE:30:HOUR:2:HOUR:2:0:%H:%M                \
        -Y  -t "${rrd_name} usage"                          \
        DEF:TotalMemory=${rrd_name}.rrd:TotalMemory:AVERAGE                   \
        DEF:FreeMemory=${rrd_name}.rrd:FreeMemory:AVERAGE                   \
        DEF:TotalSwap=${rrd_name}.rrd:TotalSwap:AVERAGE                   \
        DEF:FreeSwap=${rrd_name}.rrd:FreeSwap:AVERAGE                   \
        CDEF:TotalMemoryM=TotalMemory,1024,\*                         \
        CDEF:FreeMemoryM=FreeMemory,1024,\*                         \
        CDEF:TotalSwapM=TotalSwap,1024,\*                         \
        CDEF:FreeSwapM=FreeSwap,1024,\*                         \
        LINE1:TotalMemoryM#00FF00:"TotalMemory()"                        \
        LINE1:FreeMemoryM#FF0000:"FreeMemory()"                        \
        LINE1:TotalSwapM#0000FF:"TotalSwap()"                    \
        LINE1:FreeSwapM#FF00FF:"FreeSwap()"                        
 

