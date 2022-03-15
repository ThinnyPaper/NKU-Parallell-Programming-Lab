# test.sh
# !/bin/sh
pssh -h $PBS_NODEFILE -i "if [ ! -d \"/home/s2012176/Lab1-2\" ];then mkdir -p \"/home/s2012176/Lab1\"; fi" 1>&2 
pscp -h $PBS_NODEFILE /home/s2012176/Lab1-2/a.out /home/s2012176/Lab1-2 1>&2
perf stat -e instructions,cycles /home/s2012176/Lab1-2/a.out 1
perf stat -e instructions,cycles /home/s2012176/Lab1-2/a.out 2
perf stat -e instructions,cycles /home/s2012176/Lab1-2/a.out 3
perf stat -e instructions,cycles /home/s2012176/Lab1-2/a.out 4
