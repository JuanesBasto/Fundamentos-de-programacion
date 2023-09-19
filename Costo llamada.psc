Algoritmo CostoLlamada
	//Ejercicio 5
	Escribir "Ingrese la duracion de la llamada"
	Leer Min
	Costo <- 0.90
	Adicional <- 0.20
	Si (Min <= 5) Entonces
		Escribir "El costo es " Min * Costo
	SiNo
		CostoAdicional <- (Min - 5) * Adicional
		Escribir "El costo es " (Costo * 5) + CostoAdicional
	FinSi
FinAlgoritmo
