#Correr en python3
#Se importan los paquetes a usar
import numpy as np
import matplotlib.pylab as plt
import math
from matplotlib import cm
from mpl_toolkits.mplot3d import Axes3D

#ODE
#Se leen y guardan los datos generados
ODE1=np.genfromtxt("grados45.txt")

#Se separan las columnas de datos
t1=ODE1[:,0]
x=ODE1[:,1]
y=ODE1[:,2]
vx=ODE1[:,3]
vy=ODE1[:,4]

#Se grafica la figura y se guarda
plt.figure()
plt.plot(x,y,label="45")
plt.title('Trayectoria proyectil 45 grados')
plt.xlabel('x')
plt.ylabel('y')
plt.ylim(0,3)
plt.savefig("ODE1.pdf")
plt.close()

#Se leen y guardan los datos generados
ODE2=np.genfromtxt("10a70grados.txt")

#Se especifica la posicion en x y en y para cada uno de los angulos.
x1=ODE2[1:1800,1]
y1=ODE2[1:1800,2]
x2=ODE2[1801:3600,1]
y2=ODE2[1801:3600:,2]
x3=ODE2[3601:5400,1]
y3=ODE2[3601:5400,2]
x4=ODE2[5401:7200,1]
y4=ODE2[5401:7200,2]
x5=ODE2[7201:9000,1]
y5=ODE2[7201:9000,2]
x6=ODE2[9001:10800,1]
y6=ODE2[9001:10800,2]
x7=ODE2[10801:12600,1]
y7=ODE2[10801:12600,2]

#Se grafica la figura y se guarda
plt.figure()
plt.plot(abs(x1),(y1),label="10")
plt.plot(abs(x2),(y2),label="20")
plt.plot(abs(x3),(y3),label="30")
plt.plot(abs(x4),(y4),label="40")
plt.plot(abs(x),(y),label="45")
plt.plot(abs(x5),(y5),label="50")
plt.plot(abs(x6),(y6),label="60")
plt.plot(abs(x7),(y7),label="70")
plt.xlim(0,5)
plt.ylim(0,4)
plt.title('Trayectoria diferentes angulos')
plt.xlabel("$x$")
plt.ylabel("$y$")
plt.legend(loc="best")
plt.savefig("ODE2.pdf")
plt.close()


#PDE
#Grafica en 3D para las condiciones iniciales con extremos fijos
iniciales = np.genfromtxt("datosini.txt",delimiter=",")
d=np.shape(iniciales)
x0=np.linspace(0,50,d[1])
y0=np.linspace(0,50,d[0])
x0, y0=np.meshgrid(x0,y0)
figura=plt.figure()
axis=figura.add_subplot(1,1,1, projection='3d')
axis.plot_wireframe(x0,y0,iniciales)
plt.title("Grafica 3D para las condiciones iniciales")
axis.set_xlabel("x(m)")
axis.set_ylabel("y(m)")
axis.set_zlabel("T(c)")
axis.set_zlim(0,100)
plt.savefig("3DCondIni.pdf")
plt.close()

#Grafica 3D para extremos fijos caso 1.
intermedias1=np.genfromtxt("intermedias1.txt",delimiter=",")
x0=np.linspace(0,50,np.shape(intermedias1)[1])
y0=np.linspace(0,50,np.shape(intermedias1)[0])
x0, y0=np.meshgrid(x0,y0)
figura=plt.figure()
axis=figura.add_subplot(1,1,1, projection='3d')
axis.plot_wireframe(x0,y0,intermedias1)
plt.title("Grafica 3D caso 1 extremos fijos")
axis.set_xlabel("x(m)")
axis.set_ylabel("y(m)")
axis.set_zlabel("T(c)")
axis.set_zlim(0,100)
plt.savefig("3Dintermedios1.pdf")
plt.close()

#Grafica 3D para extremos fijos caso 2.
intermedias2=np.genfromtxt("intermedias2.txt",delimiter=",")
x0=np.linspace(0,50,np.shape(intermedias2)[1])
y0=np.linspace(0,50,np.shape(intermedias2)[0])
x0, y0=np.meshgrid(x0,y0)
figura=plt.figure()
axis=figura.add_subplot(1,1,1, projection='3d')
axis.plot_wireframe(x0,y0,intermedias2)
axis.set_zlim(0,100)
plt.title("Grafica 3D caso 2 extremos fijos")
axis.set_xlabel("x(m)")
axis.set_ylabel("y(m)")
axis.set_zlabel("T(c)")
plt.savefig("3Dintermedios2.pdf")
plt.close()

#Grafica 3D para extremos fijos caso final.
intermedias3=np.genfromtxt("intermedias3.txt",delimiter=",")
x0=np.linspace(0,50,np.shape(intermedias3)[1])
y0=np.linspace(0,50,np.shape(intermedias3)[0])
x0, y0=np.meshgrid(x0,y0)
figura=plt.figure()
axis=figura.add_subplot(1,1,1, projection='3d')
axis.plot_wireframe(x0,y0,intermedias3)
axis.set_zlim(0,100)
plt.title("Grafica 3D caso 3 extremos fijos")
axis.set_xlabel("x(m)")
axis.set_ylabel("y(m)")
axis.set_zlabel("T(c)")
plt.savefig("3Dintermerdios3.pdf")

#Grafica en 3D para los extremos libres, condiciones iniciales.
Libres1=np.genfromtxt("Libres1.txt",delimiter=",")
d=np.shape(Libres1)
x0=np.linspace(0,50,d[1])
y0=np.linspace(0,50,d[0])
x0, y0=np.meshgrid(x0,y0)
figura=plt.figure()
ax=figura.add_subplot(1,1,1, projection='3d')
axis.plot_wireframe(x0,y0,Libres1)
plt.title("Grafica 3D, condiciones iniciales con extremos libres")
axis.set_xlabel("x(m)")
axis.set_ylabel("y(m)")
axis.set_zlabel("T(c)")
axis.set_zlim(0,100)
plt.savefig("Libres13D.pdf")
plt.close()

#Grafica 3D, condiciones iniciales-periodicos.
PeriodicasIniciales=np.genfromtxt("PeriodicasIniciales.txt",delimiter=",")
d=np.shape(PeriodicasIniciales)
x0=np.linspace(0,50,d[1])
y0=np.linspace(0,50,d[0])
x0, y0=np.meshgrid(x0,y0)
figura=plt.figure()
axis=figura.add_subplot(1,1,1, projection='3d')
axis.plot_wireframe(x0,y0,PeriodicasIniciales)
plt.title("Grafica 3D, condiciones iniciales p.periodica")
axis.set_xlabel("x(m)")
axis.set_ylabel("y(m)")
axis.set_zlabel("T(c)")
axis.set_zlim(0,100)
plt.savefig("3DPeriodicasIniciales.pdf")
plt.close()

#Grafica 3D, caso 1 extremos libres
primerolibres=np.genfromtxt("primerolibres.txt",delimiter=",")
x0=np.linspace(0,50,np.shape(primerolibres)[1])
y0=np.linspace(0,50,np.shape(primerolibres)[0])
x0, y0=np.meshgrid(x0,y0)
figura=plt.figure()
axis=figura.add_subplot(1,1,1, projection='3d')
axis.plot_wireframe(x0,y0,primerolibres)
axis.set_zlim(0,100)
plt.title("Grafica 3D, caso 1 extremos libres")
axis.set_xlabel("x(m)")
axis.set_ylabel("y(m)")
axis.set_zlabel("T(c)")
plt.savefig("primerolibres.pdf")
plt.close()

#Grafica 3D, caso 2 extremos libres
segundolibres=np.genfromtxt("segundolibres.txt",delimiter=",")
x0=np.linspace(0,50,np.shape(segundolibres)[1])
y0=np.linspace(0,50,np.shape(segundolibres)[0])
x0, y0=np.meshgrid(x0,y0)
figura=plt.figure()
axis=figura.add_subplot(1,1,1, projection='3d')
axis.plot_wireframe(x0,y0,segundolibres)
axis.set_zlim(0,100)
plt.title("Grafica 3D, caso 2 extremos libres")
axis.set_xlabel("x(m)")
axis.set_ylabel("y(m)")
axis.set_zlabel("T(c)")
plt.savefig("segundolibres.pdf")
plt.close()

#Grafica 3D, caso 3 extremos libres
tercerolibres=np.genfromtxt("tercerolibres.txt",delimiter=",")
x0=np.linspace(0,50,np.shape(tercerolibres)[1])
y0=np.linspace(0,50,np.shape(tercerolibres)[0])
x0, y0=np.meshgrid(x0,y0)
figura=plt.figure()
axis=figura.add_subplot(1,1,1, projection='3d')
axis.plot_wireframe(x0,y0,tercerolibres)
axis.set_zlim(0,100)
plt.title("Grafica 3D, caso 3 extremos libres")
axis.set_xlabel("x(m)")
axis.set_ylabel("y(m)")
axis.set_zlabel("T(c)")
plt.savefig("tercerolibres.pdf")
plt.close()

#Grafica 3D, caso 1, periodica
primeroperiodica=np.genfromtxt("primeroperiodica.txt",delimiter=",")
x0=np.linspace(0,50,np.shape(primeroperiodica)[1])
y0=np.linspace(0,50,np.shape(primeroperiodica)[0])
x0, y0=np.meshgrid(x0,y0)
figura=plt.figure()
axis=figura.add_subplot(1,1,1, projection='3d')
axis.plot_wireframe(x0,y0,primeroperiodica)
plt.title("Grafica 3D, caso 1 p. periodica")
axis.set_zlim(0,100)
axis.set_xlabel("x(m)")
axis.set_ylabel("y(m)")
axis.set_zlabel("T(c)")
plt.savefig("primeroperiodica.pdf")
plt.close()

#Grafica 3D, caso 2, periodica
segundoperiodica=np.genfromtxt("segundoperiodica.txt",delimiter=",")
x0=np.linspace(0,50,np.shape(segundoperiodica)[1])
y0=np.linspace(0,50,np.shape(segundoperiodica)[0])
x0, y0=np.meshgrid(x0,y0)
figura=plt.figure()
axis=figura.add_subplot(1,1,1, projection='3d')
axis.plot_wireframe(x0,y0,segundoperiodica)
plt.title("Grafica 3D, caso 2 p.periodica")
axis.set_xlabel("x(m)")
axis.set_ylabel("y(m)")
axis.set_zlim(0,100)
axis.set_zlabel("T(c)")
plt.savefig("segundoperiodica.pdf")
plt.close()

#Grafica 3D, caso 3, periodica
terceraperiodica=np.genfromtxt("terceraperiodica.txt",delimiter=",")
x0=np.linspace(0,50,np.shape(terceraperiodica)[1])
y0=np.linspace(0,50,np.shape(terceraperiodica)[0])
x0, y0=np.meshgrid(x0,y0)
figura=plt.figure()
axis=figura.add_subplot(1,1,1, projection='3d')
axis.plot_wireframe(x0,y0,terceraperiodica)
plt.title("Grafica 3D, caso 3 p.periodica")
axis.set_xlabel("x(m)")
axis.set_ylabel("y(m)")
axis.set_zlim(0,100)
axis.set_zlabel("T(c)")
plt.savefig("terceraperiodica.pdf")
plt.close()

#No ha sido posible hacer la ultima grafica

