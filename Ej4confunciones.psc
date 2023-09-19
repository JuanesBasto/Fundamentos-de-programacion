Funcion b<- paroimpar(a)
	Si (a=0) Entonces
		Escribir "El numero es cero"
	sino
		Si (a mod 2=0) entonces 
			Escribir "El numero es par"
		SiNo
			Escribir "EL numero es impar"
		FinSi
	FinSi
Fin Funcion

Algoritmo sin_titulo
	Escribir "Digite un numero"
	Leer a
	Escribir paroimpar(a)
FinAlgoritmo
