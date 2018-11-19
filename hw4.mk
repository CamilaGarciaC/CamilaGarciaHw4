Resultados_hw4.pdf : ODE2.pdf Resultados_hw4.tex

	pdflatex Resultados_hw4.tex


ODE2.pdf : 10a70grados.txt Plots_hw4.py
	python Plots_hw4.py

grados45.txt : a.outODE
	./a.outODE

a.outODE : ODE.cpp
	g++ -o a.outODE ODE.cpp

promedioperiodica.txt : a.out
	./a.out>>

a.out : PDE.cpp
	g++ PDE.cpp
