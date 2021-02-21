Argorithm:

MPI Root: Distribute N value for each rank.

The following will be explained with rank size = 3 and N size = 12.

rank | start | end | skip
rank0 |


```
$ cat machines_openmpi.txt 
pi00 slots=1
pi01 slots=4
pi02 slots=4
pi03 slots=4
pi04 slots=4
pi05 slots=4

$ mpirun.openmpi -n 1 -hostfile machines_openmpi.txt python ./pi.py
--------------- PI ---------------
N: 100000000
starting task-1 on pi01 
starting task-5 on pi02 
starting task-8 on pi03 
starting task-6 on pi02 
starting task-2 on pi01 
starting task-9 on pi03 
starting task-7 on pi02 
starting task-0 on pi01 
starting task-10 on pi03 
starting task-4 on pi02 
starting task-11 on pi03 
starting task-12 on pi04 
starting task-3 on pi01 
starting task-13 on pi04 
starting task-14 on pi04 
starting task-15 on pi04 
starting task-19 on pi05 
starting task-16 on pi05 
starting task-17 on pi05 
starting task-18 on pi05 
c-pi (task 6 on pi02,n=5000000): 0.157080
c-pi (task 9 on pi03,n=5000000): 0.157080
c-pi (task 10 on pi03,n=5000000): 0.157080
c-pi (task 13 on pi04,n=5000000): 0.157080
c-pi (task 4 on pi02,n=5000000): 0.157080
c-pi (task 14 on pi04,n=5000000): 0.157080
c-pi (task 15 on pi04,n=5000000): 0.157080
c-pi (task 8 on pi03,n=5000000): 0.157080
c-pi (task 7 on pi02,n=5000000): 0.157080
c-pi (task 11 on pi03,n=5000000): 0.157080
c-pi (task 5 on pi02,n=5000000): 0.157080
c-pi (task 12 on pi04,n=5000000): 0.157080
c-pi (task 2 on pi01,n=5000000): 0.157080
c-pi (task 3 on pi01,n=5000000): 0.157080
c-pi (task 0 on pi01,n=5000000): 0.157080
c-pi (task 1 on pi01,n=5000000): 0.157080
c-pi (task 16 on pi05,n=5000000): 0.157080
c-pi (task 18 on pi05,n=5000000): 0.157080
c-pi (task 19 on pi05,n=5000000): 0.157080
c-pi (task 17 on pi05,n=5000000): 0.157080
PI = 3.14159265359
elasped time =  44.2550179958
----------------------------------

```
