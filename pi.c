#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define N 100000

static long num_steps;
double step;

int main(int argc, char *argv[])
{ 
	int i; 
	double x, pi, sum = 0.0;
        if(argc < 2) {
                num_steps = N;
        } else {
                num_steps = atoi(argv[1]);
        }

	step = 1.0/(double) num_steps;

	for (i=0;i<= num_steps; i++){
		x = (i+0.5)*step;
		sum = sum + 4.0/(1.0+x*x);
	}

	pi = step * sum;
	printf("pi:%8.15lf\n", pi);
}
