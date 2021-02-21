# Argorithm:

MPI Root: Distribute N value for each rank.

The following will be explained with rank size = 3 and N size = 12.
This means that each rank works 4 times iteratelly.
The trapezoid's high is 1/N (= 1/12).

- each x coordinate to start caluculation

| rank | 1st | 2nd | 3rd | 4th |
| --- | --- | --- | --- | --- |
| rank0 | 0/12 | 3/12 | 6/12 | 9/12 | 
| rank1 | 1/12 | 4/12 | 7/12 | 10/12 | 
| rank2 | 2/12 | 5/12 | 8/12 | 11/12 | 


```
- trapezoid of rank0's 1st iteration is: 
 f((0/12 + 1/12)/2) * (1/12) = f((0+0.5)*(1/12)) * (1/12)
- trapezoid of rank0's 2nd iteration is: 
 f((3/12 + 4/12)/2) * (1/12) = f((3+0.5)*(1/12)) * (1/12)
 ...
- trapezoid of rank2's 4th iteration is: 
 f((11/12 + 12/12)/2) * (1/12) = f((11+0.5)*(1/12)) * (1/12)
```

```
 trapezoid of rank0's task :  f((i + i+1)/2 *(1/12)) * (1/12) = f(i + 0.5)/12) * (1/12)  (i = 0,3,6,9)
 trapezoid of rank1's task :  f((i + i+1)/2 *(1/12)) * (1/12) = f(i + 0.5)/12) * (1/12)  (i = 1,4,7,10)
 trapezoid of rank2's task :  f((i + i+1)/2 *(1/12)) * (1/12) = f(i + 0.5)/12) * (1/12)  (i = 2,5,8,11)
```

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
