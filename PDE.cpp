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
int N = 100;
int w = 0;
double t = 0;
double vertical1=0;
double horizontal1=0;
double average=0;
double c=(n*dx)/2;
int steps=50000;
int tvarilla = 100;
int tcalcita = 10;

//Comienzo main
int main (){
//Se guarda pasado, futuro y los avances
	double past[N][N];
        double future[N][N];
	double promedio[steps];
//Se marca la condicion inicial con las constantes declaradas
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			Dx=(i*dx-c)*(i*dx-c);
			Dy=(j*dy-c)*(j*dy-c);
			if(sqrt(Dx+Dy)<5){
				past[i][j]= tvarilla;
			}
			else{
				past[i][j]= tcalcita;
			}
		}
	}
//Se empieza el proceso para los extremos fijos.
//Se crea el archivo txt de la condicion inicial.
	ofstream datosini;
//Se abre el archivo  y se recorren los valores
	datosini.open("datosini.txt");
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			datosini<<past[i][j]<<",";
			if(j==(N-1)){
				datosini<<past[i][j]<<endl;
			}
		}
	}
//Se cierra el archivo
	datosini.close();
//Se dan pasos en el tiempo
	while(t<(steps*dt)){
	double average = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			Dx=(i*dx-c)*(i*dx-c);
			Dy=(j*dy-c)*(j*dy-c);
			if(i==0||i==(N-1)||j==0||j==(N-1)){
				past[i][j]=tcalcita;
				future[i][j]=past[i][j];
			}
			else if(sqrt(Dx+Dy)<5){
				past[i][j]= tvarilla;
				future[i][j]=past[i][j];
			}
			else{
				horizontal1=(past[i+1][j]+past[i-1][j]-2*past[i][j]);
				vertical1=(past[i][j+1]+past[i][j-1]-2*past[i][j]);
				future[i][j]=past[i][j]+nu*(horizontal1+vertical1);
			}
		}
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){	
			average=average+past[i][j];
			past[i][j]=future[i][j];
		}
	}
	
	promedio[w]=(average/(pow(n,2)));
	t=t+dt;
	w=w+1;
// Se crea el archivo txt para la primera grafica
	if (w==2500){
//Se abre el archivo  y se recorren los valores
		ofstream intermedias1;
		intermedias1.open("intermedias1.txt");
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				intermedias1<<past[i][j]<<", ";
				if(j==(N-1)){
					intermedias1<<past[i][j]<<endl;
				}
			}
		}
//Se cierra el archivo
		intermedias1.close();
	}
// Se creal el archivo txt para la segunda grafica	
	if (w==(5000)){
//Se abre el archivo y se recorren los valores
		ofstream intermedias2;
		intermedias2.open("intermedias2.txt");
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				intermedias2<<past[i][j]<<", ";
				if(j==(N-1)){
					intermedias2<<past[i][j]<<endl;
				}
			}
		}
//Se cierra el archivo
		intermedias2.close();
	}
// Se creal el archivo txt para la tercera grafica
	if (w==(steps-3)){
//Se abre el archivo y se recorren los valores
		ofstream intermedias3;
		intermedias3.open("intermedias3.txt");
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				intermedias3<<past[i][j]<<", ";
				if(j==(N-1)){
					intermedias3<<past[i][j]<<endl;
				}
			}
		}
//Se cierra el archivo
		intermedias3.close();
	}
}
//Se crea el arciho txt que guarda el promedio de los extremos fijos
	ofstream PromediosFijos;
	PromediosFijos.open("PromediosFijos.txt");
		for(int i=0;i<steps;i++){
			PromediosFijos<<promedio[i]<<endl;
		}
//Se cierra el archivo
		PromediosFijos.close();

//Se empeiza a trabajar con los extremos libres, retordando todo a los valores originales
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			Dx=(i*dx-c)*(i*dx-c);
			Dy=(j*dy-c)*(j*dy-c);
			if(sqrt(Dx+Dy)<5){
				past[i][j]=tvarilla;
			}
			else{
				past[i][j]=tcalcita;
			}
		}
	}
////Se crea el arciho txt que guarda los valores del caso 1 de extremos libres.
	ofstream Libres1;
	Libres1.open("Libres1.txt");
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			Libres1<<past[i][j]<<",";
			if(j==(N-1)){
				Libres1<<past[i][j]<<endl;
			}
		}
	}
//Se cierra el archivo
	Libres1.close();
//Se inicializan las variables para dar pasos en el tiempo
	t=0;
	w=0;
	while(t<(steps*dt)){
	double aveerage = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			Dx=(i*dx-c)*(i*dx-c);
			Dy=(j*dy-c)*(j*dy-c);
			if(i==0){
				past[i][j]=past[i+1][j];
				future[i][j]=past[i][j];
			}
			else if(i==(N-1)){
				past[i][j]=past[i-1][j];
				future[i][j]=past[i][j];
			}
			else if(j==0){
				past[i][j]=past[i][j+1];
				future[i][j]=past[i][j];
			}
			else if(j==(N-1)){
				past[i][j]=past[i][j-1];
				future[i][j]=past[i][j];
			}
			else if(sqrt(Dx+Dy)<5){
				past[i][j]=tvarilla;
				future[i][j]=past[i][j];
			}
			else{
				horizontal1=(past[i+1][j]+past[i-1][j]-2*past[i][j]);
				vertical1=(past[i][j+1]+past[i][j-1]-2*past[i][j]);
				future[i][j]=past[i][j]+nu*(horizontal1+vertical1);
			}
		}
	}
//Se dan saltos en el tiempo y se calcula el promedio de la variable inicializada.
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			average=average+past[i][j];
			past[i][j]=future[i][j];
		}
	}
	promedio[w]=average/(pow(n,2));
	t=t+dt;
	w=w+1;
//Se crea el archivo que guarda los datos de extremos libres para el caso 1.
	if (w==8000){
		ofstream primerolibres;
		primerolibres.open("primerolibres.txt");
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				primerolibres<<past[i][j]<<", ";
				if(j==(N-1)){
					primerolibres<<past[i][j]<<endl;
				}
			}
		}
		primerolibres.close();
	}
//Se crea el archivo que guarda los datos de extremos libres para el caso 2.
	if (w==(steps/2)){
		ofstream segundolibres;
		segundolibres.open("segundolibres.txt");
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				segundolibres<<past[i][j]<<", ";
				if(j==(N-1)){
					segundolibres<<past[i][j]<<endl;
				}
			}
		}
		segundolibres.close();
	}
//Se crea el archivo que guarda los datos de extremos libres para el caso 3.
	if (w==(steps-3)){
		ofstream tercerolibres;
		tercerolibres.open("tercerolibres.txt");
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				tercerolibres<<past[i][j]<<", ";
				if(j==(N-1)){
					tercerolibres<<past[i][j]<<endl;
				}
			}
		}
		tercerolibres.close();
	}
}
//Se crea el archivo que guarda el archivo de promedio de extremos libres.
	ofstream promediolibres;
		promediolibres.open("promediolibres.txt");
		for(int i=0;i<steps;i++){
			promediolibres<<promedio[i]<<endl;
		}
		promediolibres.close();

//Se pasa a la situacion de la p periodica, reiniciando todos los valores al momento original.
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			Dx=(i*dx-c)*(i*dx-c);
			Dy=(j*dy-c)*(j*dy-c);
			if(sqrt(Dx+Dy)<5){
				past[i][j]=tvarilla;
			}
			else{
				past[i][j]=tcalcita;
			}
		}
	}
//Se crea el archivo que guardara los datos para la grafica de condiciones inciales de p. periodica.
	ofstream PeriodicasIniciales;
	PeriodicasIniciales.open("PeriodicasIniciales.txt");
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			PeriodicasIniciales<<past[i][j]<<",";
			if(j==(N-1)){
				PeriodicasIniciales<<past[i][j]<<endl;
			}
		}
	}
	PeriodicasIniciales.close();

// Se avanza en el tiempo y se inicializan las variables en 0, se mueve una posicion en la placa.
	t=0;
	w=0;
	while(t<(steps*dt)){
	double average=0;
	for(int i=0;i<N;i++){	
		for(int j=0;j<N;j++){
			Dx=(i*dx-c)*(i*dx-c);
			Dy=(j*dy-c)*(j*dy-c);
			if(i==0){
				past[i][j]=past[i+N-2][j];
				future[i][j]=past[i][j];
			}
			else if(i==(N-1)){
				past[i][j]=past[i-N+2][j];
				future[i][j]=past[i][j];
			}
			else if(j==0){
				past[i][j]=past[i][j+N-2];
				future[i][j]=past[i][j];
			}
			else if(j==(N-1)){
				past[i][j]=past[i][j-N+2];
				future[i][j]=past[i][j];
			}
			else if(sqrt(Dx+Dy)<5){
				past[i][j]=tvarilla;
				future[i][j]=past[i][j];
			}
			else{
				horizontal1=(past[i+1][j]+past[i-1][j]-2*past[i][j]);
				vertical1=(past[i][j+1]+past[i][j-1]-2*past[i][j]);
				future[i][j]=past[i][j]+nu*(horizontal1+vertical1);
			}
		}
	}
	
//Se mueve en el tiempo y se guarda el promedio de la variable.
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){	
			average=average+past[i][j];
			past[i][j]=future[i][j];
		}
	}
	promedio[w]=average/(pow(n,2));
	t=t+dt;
	w=w+1;
//Se crea el archivo txt para el primer caso de p periodica.
	if (w==8000){
		ofstream primeroperiodica;
		primeroperiodica.open("primeroperiodica.txt");
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				primeroperiodica<<past[i][j]<<", ";
				if(j==(N-1)){
					primeroperiodica<<past[i][j]<<endl;
				}
			}
		}
//Se cierra el archivo
		primeroperiodica.close();
	}
//Se crea el archivo txt para el segundo caso de p periodica.
	if (w==(steps/2)){
		ofstream segundoperiodica;
		segundoperiodica.open("segundoperiodica.txt");
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				segundoperiodica<<past[i][j]<<", ";
				if(j==(N-1)){
					segundoperiodica<<past[i][j]<<endl;
				}
			}
		}
//Se cierra el archivo
		segundoperiodica.close();
	}
	
//Se crea el archivo txt para el tercer caso de p periodica. 
	if (w==(steps-3)){
		ofstream terceraperiodica;
		terceraperiodica.open("terceraperiodica.txt");
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				terceraperiodica<<past[i][j]<<", ";
				if(j==(N-1)){
					terceraperiodica<<past[i][j]<<endl;
				}
			}
		}
//Se cierra el archivo
		terceraperiodica.close();
	}
}
//Se crea el archivo txt que guarda los promeddios para la situacion periodica. 
	ofstream promedioperiodica;
		promedioperiodica.open("promedioperiodica.txt");
		for(int i=0;i<steps;i++){
			promedioperiodica<<promedio[i]<<endl;
		}
		promedioperiodica.close();

return 0;
}
