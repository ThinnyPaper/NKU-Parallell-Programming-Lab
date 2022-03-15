# test.sh
# !/bin/sh
pssh -h $PBS_NODEFILE -i "if [ ! -d \"/home/s2012176/Lab1\" ];then mkdir -p \"/home/s2012176/Lab1\"; fi" 1>&2 
pscp -h $PBS_NODEFILE /home/s2012176/Lab1/sample /home/s2012176/Lab1 1>&2
perf record -e cache-misses /home/s2012176/Lab1/sample 
