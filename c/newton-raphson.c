#include <stdio.h>
#include <math.h>

#define ERROR 0.0001

double Func(double x){
	return x*x*x - x*x +2;
}

double derivativeFunc(double x){
	return 3*x*x - 2*x;
}

double newtonRaphson(double x){
	double h = Func(x)/derivativeFunc(x);

	while(fabs(h) >= ERROR){
		h = Func(x)/derivativeFunc(x);
		x = x - h;
	}

	return x;
}

int main(){
	double x0 = 0;
	double root = newtonRaphson(x0);

	printf("Root: %lf\n", root);
	return 0;
}
