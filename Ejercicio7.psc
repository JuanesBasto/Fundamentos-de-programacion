Algoritmo Ejercicio7 
	Escribir "Escriba el monto";
	leer monto
	
	a=monto*0.25
	descuento25=monto-a
	b=monto*0.20
	descuento20=monto-b
	
	si monto>=300 Entonces
		Escribir "El monto con el descuento del 25% es: ", descuento25;
	SiNo
		si monto>150 y monto<300
			Entonces
			Escribir "El monto con el descuento del 20% es: ", descuento20;
		SiNo
			Escribir "El monto es: " monto,", no aplica descuento";
			
		FinSi
	FinSi
	
FinAlgoritmo
