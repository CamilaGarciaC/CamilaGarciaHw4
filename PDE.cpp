//Parte de este ejercicio se baso en la teoria del libro Landau.

//Se importan los paquetes a usar
#include<iostream>
#include<math.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
using namespace std;

//Se declaran las constantes y condiciones iniciales 
double k = 1.62;
double cp = 820; 
double p = 2.71*0.000001; //Se convierte a kg y metros.
double n = 100;
double dx = 50/n;
double dy = dx;
double Dx = 0; 
double Dy = 0;
double dt=0.00003;
double nu=(k*dt)/(dx*dx*cp*p);
int N = 100
double past[N][N];
double future[N][N];
double vertical1=0;
double horizontal1=0;
double vertical2=0;
double horizontal2=0;
double average=0;
int steps=50000;
double average[steps];
double c=(n*dx)/2;

