
//Se importan los paquetes a usar
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <fstream>
#define PI 3.14159
using namespace std

//Se declaran las condiciones iniciales y constantes de movimiento
double g = 10;
double c = 0.2;
double m = 0.2; 
double x0 = 0;
double y0 = 0;
double t0 = 0;
double dt = 0.001;
double v0 = 300;
double vx0 = v0*cos(teta);
double vy0 = v0*sin(teta);

//Metodo que cambia el angulo a radianes
double rad(double teta){
	r = PI*angulo/180.0;
	return r
}

//Se dan las funciones para el metodo Runge Kutta
double velx(double t,double x, double y, double vx, double vy){
	return vx;
}

double vely(double t,double x, double y, double vx, double vy){
	return vy;
}

double acx(double t,double x, double y, double vx, double vy){
	return -c*(pow(vx,2)+pow(vy,2))/m*vx/sqrt(pow(vx,2)+pow(vy,2));
}

double acy(double t,double x, double y, double vx, double vy){
	return -g-c*(pow(vx,2)+pow(vy,2))/m*vy/sqrt(pow(vx,2)+pow(vy,2));
}

void RungeKutta(){



}
