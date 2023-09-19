Algoritmo sin_titulo
	Escribir "Ingrese la duracion de la llamada en minutos"
	Leer llamada
	si llamada<=5 Entonces
		costo<- llamada*0.18
		Escribir "El costo de la llamada es de ",costo;
	SiNo
		adicional<-llamada-5
		costo<- (5*0.18)+(adicional*0.2)
		Escribir "El costo de la llamada es de ", costo
	FinSi
FinAlgoritmo
