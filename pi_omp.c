#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define N 100000
#define NUM_THREADS 4

static long num_steps;
double step;

int main(int argc, char *argv[])
{ 
	int i; 
	double x, pi, sum[NUM_THREADS] = {0.0};
        if(argc < 2) {
                num_steps = N;
        } else {
                num_steps = atoi(argv[1]);
        }

	step = 1.0/(double) num_steps;
	omp_set_num_threads(NUM_THREADS);
	#pragma omp parallel
	{	double x; int i, id;
		id = omp_get_thread_num();
	#pragma omp for
		for (i=0;i<= num_steps; i++){
			x = (i+0.5)*step;
			sum[id] += 4.0/(1.0+x*x);
		}
	}
	/* pi = step * sum; */
	for(i=0, pi=0.0; i<NUM_THREADS;i++) {
		pi += sum[i]*step;
	}
	printf("pi:%8.15lf\n", pi);
}
