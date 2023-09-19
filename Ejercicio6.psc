Algoritmo sin_titulo
	Escribir "Digite 3 numeros"
	Leer a,b,c
	si (a>b) y (a>c) Entonces
		si b>c Entonces
			escribir "Orden de mayor a menor es ",a," ",b," ",c
			escribir "Orden de menor a mayor es ",c," ",b," ",a
		SiNo
			Escribir "Orden de mayor a menor es ",a," ",c," ",b
			escribir "Orden de menor a mayor es ",b," ",c," ",a
		FinSi
	sino 
		Si (b>a) y (b>c) Entonces
			si a>c Entonces
				escribir "Orden de mayor a menor es ",b," ",a," ",c
				escribir "Orden de menor a mayor es ",c," ",a," ",b
			SiNo
				Escribir "Orden de mayor a menor es ",b," ",c," ",a
				escribir "Orden de menor a mayor es ",a," ",c," ",b
			FinSi
		SiNo
			Si (c>a y c>b) entonces
				si a>b entonces
					escribir "Orden de mayor a menor es ",c," ",a," ",b
					escribir "Orden de menor a mayor es ",b," ",a," ",c
				sino
					escribir "Orden de mayor a menor es ",c," ",b," ",a
					escribir "Orden de menor a mayor es ",a," ",b," ",c
				FinSi
			FinSi
		FinSi
	FinSi
FinAlgoritmo
