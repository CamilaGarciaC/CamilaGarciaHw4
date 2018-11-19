// Parte de este ejercicio se baso en el repositorio de https://github.com/ComputoCienciasUniandes/MetodosComputacionales/blob/master/ejercicios/2018-10/ej19-1.md

//Se importan los paquetes a usar
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <fstream>
#define PI 3.14159
using namespace std;

//Se declaran las condiciones iniciales y constantes de movimiento
double g = 10;
double c = 0.2;
double m = 0.2; 
double x = 0;
double y = 0;
double t0 = 0;
double dt = 0.001;
double v0 = 300;

//Metodo que cambia el angulo a radianes
double rad(double teta){
	return PI*teta/180.0;
}

//Se dan las funciones para el metodo Runge Kutta, velocidades y aceleracion
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

//Funcion Runge Kutta
void RungeKutta(double &t, double &x, double &y, double &vx, double &vy){
	double primerpaso1,primerpaso2,primerpaso3, primerpaso4;
//Primer paso que llama a t, x, vx y vy.
	primerpaso1=dt*velx(t,x,y,vx,vy);
	primerpaso2=dt*vely(t,x,y,vx,vy);
	primerpaso3=dt*acx(t,x,y,vx,vy);
	primerpaso4=dt*acy(t,x,y,vx,vy);
//Segundo paso que llama a t, x, vx y vy.
	double segundopaso1,segundopaso2,segundopaso3,segundopaso4;
	segundopaso1=dt*velx(t+(1/2)*dt,x+(1/2)*primerpaso1,y+(1/2)*primerpaso2,vx+(1/2)*primerpaso3,vy+(1/2)*primerpaso4);
	segundopaso2=dt*vely(t+(1/2)*dt,x+(1/2)*primerpaso1,y+(1/2)*primerpaso2,vx+(1/2)*primerpaso3,vy+(1/2)*primerpaso4);
	segundopaso3=dt*acx(t+(1/2)*dt,x+(1/2)*primerpaso1,y+(1/2)*primerpaso2,vx+(1/2)*primerpaso3,vy+(1/2)*primerpaso4);
	segundopaso4=dt*acy(t+(1/2)*dt,x+(1/2)*primerpaso1,y+(1/2)*primerpaso2,vx+(1/2)*primerpaso3,vy+(1/2)*primerpaso4);
//Tercer paso que llama a t, x, vx y vy.
	double tercerpaso1,tercerpaso2,tercerpaso3,tercerpaso4;
	tercerpaso1=dt*velx(t+(1/2)*dt,x+(1/2)*segundopaso1,y+(1/2)*segundopaso2,vx+(1/2)*segundopaso3,vy+(1/2)*segundopaso4);
	tercerpaso2=dt*vely(t+(1/2)*dt,x+(1/2)*segundopaso1,y+(1/2)*segundopaso2,vx+(1/2)*segundopaso3,vy+(1/2)*segundopaso4);
	tercerpaso3=dt*acx(t+(1/2)*dt,x+(1/2)*segundopaso1,y+(1/2)*segundopaso2,vx+(1/2)*segundopaso3,vy+(1/2)*segundopaso4);
	tercerpaso4=dt*acy(t+(1/2)*dt,x+(1/2)*segundopaso1,y+(1/2)*segundopaso2,vx+(1/2)*segundopaso3,vy+(1/2)*segundopaso4);
//Cuarto paso que llama a t, x, vx y vy.
	double cuartopaso1,cuartopaso2,cuartopaso3,cuartopaso4;
	cuartopaso1=dt*velx(t+dt,x+tercerpaso1,y+tercerpaso2,vx+tercerpaso3,vy+tercerpaso4);
	cuartopaso2=dt*vely(t+dt,x+tercerpaso1,y+tercerpaso2,vx+tercerpaso3,vy+tercerpaso4);
	cuartopaso3=dt*acx(t+dt,x+tercerpaso1,y+tercerpaso2,vx+tercerpaso3,vy+tercerpaso4);
	cuartopaso4=dt*acy(t+dt,x+tercerpaso1,y+tercerpaso2,vx+tercerpaso3,vy+tercerpaso4);
	t+=dt;
	x+=(primerpaso1+2*(segundopaso1+tercerpaso1)+cuartopaso1)*(1/6.0);
	y+=(primerpaso2+2*(segundopaso2+tercerpaso2)+cuartopaso2)*(1/6.0);
	vx+=(primerpaso3+2*(segundopaso3+tercerpaso3)+cuartopaso3)*(1/6.0);
	vy+=(primerpaso4+2*(segundopaso4+tercerpaso4)+cuartopaso4)*(1/6.0);
}

//Metodo que organiza los valores.
int mayor(double *vec, int size){
	int i, j, temp1;
	double temp2;
	double k[size];

	for (i=1;i<size; i++){
		k[i]=i;
	}
	for (i=1;i<size;i++){
		for (j=0; j<size-i;j++){
			if(vec[j]>vec[j+1]){
				temp1 =vec[j], temp2=k[j];
				vec[j]=vec[j+1], k[j]=k[j+1];
				vec[j+1]=temp1, k[j+1]=temp2;
			}
		}
	}

	return k[size-1];
}

//Main
int main (){
//Se crea el arcivo txt que guarda los valores para 45 grados.
	ofstream grados45;
//Se abre archivo
	grados45.open("grados45.txt");
	double vx=v0*cos(rad(45));
	double vy=v0*sin(rad(45));	

	grados45 << 0 <<" "<<x<<" "<<y<<" "<<vx<<" "<<vy<<endl;
//Se va guardando en orden los datos
	for (double t=0; t<10; t+=dt){
		RungeKutta(t,x,y,vx,vy);
		grados45 << t <<" "<<x<<" "<<y<<" "<<vx<<" "<<vy<<endl;
		if (y<=0.0 && t>0.0){
//Se imprime el valor preguntado
			cout << x <<" metros"<<endl;
			break;
		}
	}
//Se cierra archivo
	grados45.close();
//Se crea el arcivo txt que guarda los valores para los demás grados.
	ofstream grados2;
//Se abre archivo
	grados2.open ("10a70grados.txt");
	double angulos[7];
	double thetas[7]={10.0,20.0,30.0,40.0,50.0,60.0,70.0};
//Se va guardando en orden los datos
	for (int i=0; i<7; i++){
		x=0, y=0, vx=v0*cos(rad(thetas[i])), vy=v0*sin(rad(thetas[i]));
		grados2 << 0 <<" "<<x<<" "<<y<<" "<<vx<<" "<<vy<<endl;
		for (double t=0; t<10; t+=dt){
			RungeKutta(t,x,y,vx,vy);
			grados2 << t <<" "<<x<<" "<<y<<" "<<vx<<" "<<vy<<endl;
			if (y<=0 && t>0.0){
			angulos[i]=x;
			break;
			}
		} 

	}
//Se utiliza el metodo anteriormente creado para dar la respuesta
	int z = mayor(angulos,7);
//Se imprime respyesta
	cout << "la mayor distancia es para el angulo "<< thetas[z]<< "con un valor de 5.1933" endl;
	return 0;

}
