#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <math.h>

// x is raised to the power and n is the number of terms
float approx(double x, int n) {
	float sum = 1.0f;
	double sum2;
	//CALCULATES approximation 
	for(int i = n -1; i >0; --i) {
		sum = 1+x * sum/i;
	}	
	//CALCULATES real exp
	sum2 = exp(x);
	//CHECK difference
	double diff = sum-sum2;
	diff = abs(diff);
	//ERROR if diff is greater than 1
	if(diff>=1) {
		printf("Child: The aprroximation is not good\n");
		return -1;
	}
	return sum;
}
//CALCULATE real exp 
double expapprox(double x) {
	double sum = exp(x);
	return sum;
}
int main( int argc, char *argv[] )  {
	double arg1 = atof(argv[1]);
	int arg2 = atoi(argv[2]);
	if(approx(arg1,arg2) == -1) {
		return -1;
	} else {
		printf("Child: Child (PID= %d): For x = %f the real exp = %1.6f\n", getpid(),arg1,expapprox(arg1)); 
		printf("Child: The approximation of Exp: For x = %f the first %i terms yeild %1.7f\n", arg1,arg2,approx(arg1,arg2));
	}
	return 0;
}
