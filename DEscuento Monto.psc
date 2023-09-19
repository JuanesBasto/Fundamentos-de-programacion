Algoritmo DescuentoMonto
	//Ejercicio 7
	Escribir "Ingrese el monto"
	Leer Monto
	Si (Monto >= 300) Entonces
		Descuento <- Monto * 0.25
		Escribir  "El descuento es " Descuento
	SiNo
		Si (Monto < 150) Entonces
			Escribir "No hay descuento"
		SiNo
			Descuento <- Monto * 0.20
			Escribir "El descuento es " Descuento
		FinSi
	FinSi
FinAlgoritmo
