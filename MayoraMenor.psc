Algoritmo OrdenarNumeros
	//Ejercicio 6
	Escribir "Ingrese los tres numeros a ordenar"
	Leer Num1, Num2, Num3
	Si (Num1 > Num2) Entonces
		Si (Num1 > Num3) Entonces
			Si (Num2 > Num3) Entonces
				Escribir "Los Numeros de mayor a menor: " Num1 " ," Num2 " ," Num3
				EScribir "Los Numeros de menor a mayor: " Num3 " ," Num2 " ," Num1
			SiNo
				p <- Num3
				Num3 <- Num2 
				Num2 <- p
				Escribir "Los Numeros de mayor a menor: " Num1 " ," Num2 " ," Num3
				EScribir "Los Numeros de menor a mayor: " Num3 " ," Num2 " ," Num1
 			FinSi
		SiNo
			p <- Num2
			Num2 <- Num1
			Num1 <- Num3
			Num3 <- p
			Escribir "Los Numeros de mayor a menor: " Num1 " ," Num2 " ," Num3
			EScribir "Los Numeros de menor a mayor: " Num3 " ," Num2 " ," Num1
		FinSi
	SiNo
		p <- Num2
		Num2 <- Num1
		Num1 <- p
		Escribir "Los Numeros de mayor a menor: " Num1 " ," Num2 " ," Num3
		EScribir "Los Numeros de menor a mayor: " Num3 " ," Num2 " ," Num1
	FinSi
FinAlgoritmo
