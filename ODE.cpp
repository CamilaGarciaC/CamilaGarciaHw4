//Se importan los paquetes a usar
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std

//Se declaran las condiciones iniciales
double g = 10;
double c = 0.2;
double m = 0.2; 
double x0 = 0;
double y0 = 0
double v = 300;
double teta = 45;
double d = c*v
int N = 10000;


double f1(double v, double x, double t);
double f2(double v, double x, double t);

double fun()
{
	return -g-c*(abs(v)/m)*v
}
	
int main()
{
	double x1[N];
	double y1[N];
	double v1[N];

	x1[0] = x0;
	y1[0] = y0;
	v1[0] = v0;
 
return 0;
}
