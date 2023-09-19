Algoritmo SistemaAprovacion
	//Ejercicio 3
	Escribir "Ingrese las tres notas"
	Leer Nota1, Nota2, Nota3
	Promedio <- (Nota1 + Nota2 + Nota3) / 3
	Si (Promedio >= 10.5) Entonces
		Escribir "El estudiante esta aprobado con un promedio de " Promedio
	SiNo
		Escribir "El estudiante esta reprovado con un promedio de " Promedio
	FinSi
FinAlgoritmo
