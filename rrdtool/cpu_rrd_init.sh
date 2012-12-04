#!/bin/bash
#
# cpu_rrd_init.sh
# desc: create .rrd file
# Created on: 2012-3-5
#  Author: lixingyi(lxyfirt@gmail.com)
#


cd $(dirname $0)

#network
awk -F':' '{if($1~/eth[0123456]$/ || $1~/lo/) print $1,$2;}' /proc/net/dev | awk '{if($2>0) print $1}' | while read if_name
do
    if_name=${if_name// }
    echo "creating ${if_name}.rrd  ..."
    /usr/bin/rrdtool create ${if_name}.rrd -s 60 DS:rx:COUNTER:120:U:U DS:rp:COUNTER:120:U:U DS:tx:COUNTER:120:U:U DS:tp:COUNTER:120:U:U RRA:AVERAGE:0.5:1:1440
done

#disk io
awk '{if($3~/[sh]d[abcdefgh]$/ && $4 > 0 ) print $3;}' /proc/diskstats | while read disk_name
do
    disk_name=${disk_name// }
    echo "creating ${disk_name}.rrd  ..."
    /usr/bin/rrdtool create ${disk_name}.rrd -s 60 DS:rio:COUNTER:120:U:U DS:wio:COUNTER:120:U:U RRA:AVERAGE:0.5:1:1440
done


#cpu
awk '{if($1~/^cpu/) print $1;}' /proc/stat | while  read cpu_name 
do
    cpu_name=${cpu_name// }
    echo "creating ${cpu_name}.rrd  ..."
    /usr/bin/rrdtool create ${cpu_name}.rrd -s 60 DS:idle:COUNTER:120:U:U DS:user:COUNTER:120:U:U DS:iowait:COUNTER:120:U:U DS:intr:COUNTER:120:U:U DS:total:COUNTER:120:U:U RRA:AVERAGE:0.5:1:1440
    
done  

#memory

/usr/bin/rrdtool create memory.rrd -s 60 DS:TotalMemory:GAUGE:120:U:U DS:FreeMemory:GAUGE:120:U:U DS:TotalSwap:GAUGE:120:U:U DS:FreeSwap:GAUGE:120:U:U RRA:AVERAGE:0.5:1:1440


