/*
Registrar
Loggear
Ingresar dinero
Retirarlo
Agregar contactos
Hacer transferencias
Ver historial de transferencias
*/
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//LIBRERIAS
#include <stdio.h>
#include <conio.h>
#include<locale.h>
#include<stdbool.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//ESTRUCTURAS

typedef struct{
	int iNumCuenta;
}regContacto;

typedef struct{
	int iCuentaRemitente;
	int iCuentaDestino;
	float fImporte;
}regTransaccion;

typedef struct{
	int iNumCuenta;
	char *cNombre;
	char *cPassword;
	float fDinero;
	int iNumAmigos;
	int iNumTranferencias;
	regContacto *vtrAmigos;
	regTransaccion *vtrHistorial;
}regUsuario;
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//DECLARACION DE LAS FUNCIONES Y VARIABLES GLOBALES
void vMenu();
void vRegistro();
void vRegistrar(char *, char*, int);
void vVerUsuarios();
void vMenuUsuario();

void vHacerTransferencia();
void vTransferir(int, int, float);
void vVerTransferencias();

void vIngresarDinero();
void vIngresar(float);
void vRetirarDinero();
void vRetirar(float);

char *cObtenerTexto(char *, int);
int iObtenerNumero(char *);
float fObtenerNumero(char *);

int iGenerarNumCuenta();

void vAgregarContacto();
bool bContactoExiste(int, regUsuario *);
void vVerContactos();

bool bLoggin();

regUsuario *vtrBaseUsuarios;
int iNumeroUsuarios=0;
int iSesionNumUsuario;

/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
int main()
{    
    setlocale(LC_ALL, "");

	vtrBaseUsuarios=(regUsuario *)malloc(sizeof(regUsuario));
	vRegistrar("Fernando", "contrasena", 1);
	
	vMenu();




    return 0;
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void vMenu(){
    
    bool bSalir =false;
    char cOpcion[2];
    int iOpcion;



   do{
        system ("CLS");
        printf("\tBienvenido a Banco Unipam\n");
        printf("Elija una opción:\n");
        printf("1. Registrarse.\n2. Iniciar sesion.\n3. Ver usuarios.\n4. Salir.\n");
        
        //VALIDAR ENTRADA DE USUARIO
        scanf("%s", cOpcion);
        iOpcion=atoi(cOpcion);
        switch(iOpcion)
        {
            case 1:
                //REGISTRARSE
                vRegistro();
                break;
            case 2:{
            	//INICIAR SESION
            	if(bLoggin()==true){
            	vMenuUsuario();}
			}
				break;
            case 3:
                //VER USUARIOS
                vVerUsuarios();
                break;
            case 4:
                //SALIR
                bSalir=true;
                break;
            default: printf("Parámetro Inválido.\n");
        }
    } while (bSalir==false);
    system("PAUSE");
    
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void vRegistro(){
        char *cNombre=cObtenerTexto("Ingrese su nombre", 0);
        printf("%s", cNombre);
        char *cPassword=cObtenerTexto("Ingrese su contraseña (Minimo 8 Caracteres)",8);
        int iNumeroCuenta=iGenerarNumCuenta();
        
        vRegistrar(cNombre, cPassword, iNumeroCuenta);
        
        printf("Su numero de cuenta es: %d\n", iNumeroCuenta);
        
        system("PAUSE");
        
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void vRegistrar(char *cNombre, char *cPassword, int iNumCuenta)
{
	
	vtrBaseUsuarios[iNumCuenta-1].cNombre=(char*)malloc(sizeof(char));
	vtrBaseUsuarios[iNumCuenta-1].cPassword=(char*)malloc(sizeof(char));
	
	regUsuario *vtrUsuario;
	vtrUsuario=&vtrBaseUsuarios[iNumCuenta-1];
	
	strcpy(vtrUsuario->cNombre, cNombre);
	strcpy(vtrUsuario->cPassword, cPassword);
	
	vtrUsuario->iNumCuenta=iNumCuenta;
	vtrUsuario->fDinero=0;
	vtrUsuario->iNumAmigos=0;
	vtrUsuario->iNumTranferencias=0;
	iNumeroUsuarios++;
	
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void vMenuUsuario()
{
	bool bSalir=false;
	int iOpcion;
	char cOpcion[2];
	do
	{
		system("CLS");
		printf("Bienvenido %s, Dinero disponible: $%.2f\nElija una opcion:\n", vtrBaseUsuarios[iSesionNumUsuario-1].cNombre, vtrBaseUsuarios[iSesionNumUsuario-1].fDinero);
		printf("1.Hacer una trasnferencia.\n2.Ver contactos.\n3.Agregar contactos.\n4.Historial de trasnferencias.\n5.Ingresar dinero.\n6.Retirar dinero.\n7.Cerrar sesion.\n");
		scanf("%s", cOpcion);
		iOpcion=atoi(cOpcion);
		
		switch(iOpcion)
		{
			case 1:
				{
				//HACER TRASNFERENCIAS
				
				vHacerTransferencia();
				}break;

				
			case 2:
				{//VER CONTACTOS
				
				vVerContactos();
				}break;
			case 3:
				{
				//AGREGAR CONTACTOS
				
				vAgregarContacto();
				} break;
			case 4:
				{
				//HISTORIAL DE TRANSDERENCIAS
				
				vVerTransferencias();
				}break;
			case 5:
				{
				//INGRESAR DINERO
				
				vIngresarDinero();
				}break;
			case 6:
				{
				//RETIRAR DINERO
				
				vRetirarDinero();
				}break;
			case 7:
				{
				//SALIR
				
				bSalir=true;
				}break;
				
			default: {
				printf("Parámetros inválidos\n");
				system("PAUSE");
			}
		}
		
	}while(bSalir==false);
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void vAgregarContacto()
{
	int iNumCuenta=iObtenerNumero("Ingrese el numero de cuenta");
	if(iNumCuenta<=iNumeroUsuarios && iNumCuenta!=iSesionNumUsuario)
	{
		regUsuario *vtrUsuario;
		vtrUsuario=&vtrBaseUsuarios[iSesionNumUsuario-1];
		if (vtrUsuario->iNumAmigos==0)
		{
			vtrUsuario->vtrAmigos=(regContacto *)malloc(sizeof(regContacto));
			vtrUsuario->vtrAmigos[0].iNumCuenta==iNumCuenta;
			vtrUsuario->iNumAmigos=1;
			printf("Se ha añadido a %s a tu lista de contactos \n", vtrBaseUsuarios[iNumCuenta-1].cNombre);
		}
		else if(bContactoExiste(iNumCuenta, vtrUsuario)==false)
		{
			int iUltimoIndice=vtrUsuario->iNumAmigos;
			vtrUsuario->vtrAmigos=(regContacto *)realloc(vtrUsuario, sizeof(regContacto)*(iUltimoIndice+1));
			vtrUsuario->vtrAmigos[iUltimoIndice].iNumCuenta=iNumCuenta;
			vtrUsuario->iNumAmigos++;
			printf("Se ha añadido a %s a tu lista de contactos \n", vtrBaseUsuarios[iNumCuenta-1].cNombre);

		}
		else
		{
			printf("El usaurio %s ya es tu contacto\n", vtrBaseUsuarios[iNumCuenta-1].cNombre);
		}
	}
	else{
		printf("Cuenta inválida\n");
	}
	system("PAUSE");
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void vVerContactos()
{
	int i;
	int iNumCuenta;
	regUsuario *vtrUsuario;
	vtrUsuario=&vtrBaseUsuarios[iSesionNumUsuario-1];
	if(vtrUsuario->iNumAmigos>0)
	{
		for(i=0;i<vtrUsuario->iNumAmigos; i++)
		{
			iNumCuenta=vtrUsuario->vtrAmigos[i].iNumCuenta;
			printf("Nombre: %s \t Número de cuenta: %d\n", vtrBaseUsuarios[iNumCuenta].cNombre, iNumCuenta);
			//printf("Nombre: %s \t Número de cuenta: %d\n", vtrBaseUsuarios[iNumCuenta-1].cNombre, iNumCuenta);

		}
	}
	else
	{
		printf("Aun no tienes  ningun contacto :(\n");	
	}
	system("PAUSE");
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
bool bContactoExiste(int iNumCuenta, regUsuario *vtrUsuario)
{
	int i;
	for(i=0;i<vtrUsuario->iNumAmigos; i++)
	{
		if(vtrUsuario->vtrAmigos[i].iNumCuenta==iNumCuenta)
		{
			return true;
		}
	}
	return false;
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void vIngresarDinero()
{
	float fCantidad=fObtenerNumero("Ingrese la cantidad que desea depositar a su cuenta");
	vIngresar(fCantidad);
	system("PAUSE");
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void vIngresar(float fCantidad)
{
	vTransferir(iSesionNumUsuario, iSesionNumUsuario, fCantidad);
	vtrBaseUsuarios[iSesionNumUsuario-1].fDinero+=fCantidad;
	printf("Se ha ingresado $%.2f a su cuenta\n", fCantidad);
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void vRetirarDinero()
{
	float fCantidad=fObtenerNumero("Ingrese la cantidad que desea retirar de su cuenta");
	if(fCantidad<=vtrBaseUsuarios[iSesionNumUsuario-1].fDinero)
	{
		vRetirar(fCantidad);	
	}
	else
	{
		printf("No cuentas con los fondos suficientes paa este retiro\n");
	}
	system("PAUSE");
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void vRetirar(float fCantidad)
{
	vTransferir(iSesionNumUsuario, iSesionNumUsuario, fCantidad*-1);
	vtrBaseUsuarios[iSesionNumUsuario-1].fDinero-=fCantidad;
	printf("Se ha retirado $%.2f de su cuenta\n", fCantidad);
	
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void vHacerTransferencia()
{
	regTransaccion vtrNuevaTransanccion;
	int iCuentaDestino=iObtenerNumero("Ingrese el numero de cuenta de destino");
	int iCuentaRemitente=iSesionNumUsuario;
	float fImporte=fObtenerNumero("Ingrese la cantidad a transferir");
	
	if(iCuentaDestino<=iNumeroUsuarios)
	{
		if(fImporte<=vtrBaseUsuarios[iSesionNumUsuario-1].fDinero)
		{
			vTransferir(iCuentaDestino, iCuentaRemitente, fImporte);
		}
		else
		{
			printf("No cuenta con los fondos suficientes para realizar esa transacción\n");
		}
	}else{
		printf("Cuenta inválida\n");
	}
	
	system("PAUSE");
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void vTransferir(int iDestino, int iRemitente, float fCantidad)
{
	bool bDest;
	regUsuario *vtrUsuario, *vtrDestino;
	vtrUsuario=&vtrBaseUsuarios[iSesionNumUsuario-1];
	bDest=(iDestino<=iNumeroUsuarios && iDestino!=iRemitente)?true:false;
	if(bDest)
	{
		regTransaccion vtrTransaccion;
		vtrTransaccion.iCuentaDestino=iDestino;
		vtrTransaccion.iCuentaRemitente=iRemitente;
		vtrTransaccion.fImporte=fCantidad;
		
		vtrDestino=&vtrBaseUsuarios[iDestino-1];
		vtrUsuario->fDinero-=fCantidad;
		vtrDestino->fDinero+=fCantidad;
		
		vtrUsuario->vtrHistorial=(vtrUsuario->iNumTranferencias==0)?(regTransaccion *)malloc(sizeof(regTransaccion)):vtrUsuario->vtrHistorial;
		vtrDestino->vtrHistorial=(vtrDestino->iNumTranferencias==0)?(regTransaccion *)malloc(sizeof(regTransaccion)):vtrDestino->vtrHistorial;
		
		vtrUsuario->iNumTranferencias++;
		vtrDestino->iNumTranferencias++;
		
		vtrUsuario->vtrHistorial=(regTransaccion *)realloc(vtrUsuario->vtrHistorial, sizeof(regTransaccion)*(vtrUsuario->iNumTranferencias+1));
		vtrUsuario->vtrHistorial[vtrUsuario->iNumTranferencias-1]=vtrTransaccion;
		
		vtrDestino->vtrHistorial=(regTransaccion *)realloc(vtrDestino->vtrHistorial, sizeof(regTransaccion)*(vtrDestino->iNumTranferencias+1));
		vtrDestino->vtrHistorial[vtrUsuario->iNumTranferencias-1]=vtrTransaccion;
		
	}
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void vVerTransferencias()
{
	int i, iIndiceDestino, iIndiceRemitente;
	regUsuario *vtrUsuario;
	vtrUsuario=&vtrBaseUsuarios[iSesionNumUsuario-1];
	if(vtrUsuario->iNumTranferencias>0)
	{
		float fCantidad;
		for (i=0;i<vtrUsuario->iNumTranferencias;i++)
		{
			iIndiceDestino=vtrUsuario->vtrHistorial[i].iCuentaDestino-1;
			iIndiceRemitente=vtrUsuario->vtrHistorial[i].iCuentaRemitente-1;
			fCantidad=vtrUsuario->vtrHistorial[i].fImporte;
			printf("De %s para %s : $%.2f\n", vtrBaseUsuarios[iIndiceRemitente].cNombre, vtrBaseUsuarios[iIndiceDestino].cNombre, fCantidad);
			
		}
	}
	else{
		printf("Aun no haces ninguna transferencia\n");
	}
	system("PAUSE");
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
bool bLoggin()
{
	bool logged=false;
	int iNumCuenta=iObtenerNumero("Ingrese su número de cuenta");
	if(iNumCuenta<=iNumeroUsuarios)
	{
		char *cPassword=cObtenerTexto("Ingrese su contraseña", 0);
		logged=(strcmp(cPassword, vtrBaseUsuarios[iNumCuenta-1].cPassword)==0)?true:false;
		if(logged==true)
		{
			printf("Las contraseñas coinciden\n");
			iSesionNumUsuario=iNumCuenta;
		}
		else 
		{
			printf("Las contraseñas no coinciden\n");
		}

	}
	else{
		printf("Número de cuenta inexistente\n");
	}
	system("PAUSE");
	return logged;
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void vVerUsuarios()
{
	int i;
	
	if(iNumeroUsuarios>0)
	{
		for (i=0; i<iNumeroUsuarios; i++)
		{
			printf("Nombre: %s\tNumero de cuenta: %d\n ", vtrBaseUsuarios[i].cNombre, vtrBaseUsuarios[i].iNumCuenta);	
		}	
	}
	else{
		printf("Aún no hay usaurios registrado.s\n");
	}
	system("PAUSE");
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
char *cObtenerTexto(char *cPeticion, int iLongitud)
{
    char *cTexto;
    bool bValido=false;
    cTexto=(char *)malloc(sizeof(char));
    do{
        fflush(stdin);    
        system("CLS");
        printf("%s: ", cPeticion);    
        scanf("%[^\n]", cTexto);
        
        if(strcmp(cTexto, ""))
        {
            bValido=(iLongitud<=0)?true:false;
            if(bValido==false)
            {
                bValido=(strlen(cTexto)>=iLongitud)?true:false;    
            }
        }
    }while (!bValido);
    return cTexto;
    
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
int iObtenerNumero(char *peticion)
{
	char *cNumero;
	int iNumero;
	cNumero=(char *)malloc(sizeof(char));
	do
	{
		fflush(stdin);
		printf("%s: ", peticion);
		scanf("%s", cNumero);
		iNumero=atoi(cNumero);
	}while (iNumero<=0);
	return iNumero;
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
float fObtenerNumero(char *peticion)
{
	char *cNumero;
	float fNumero;
	cNumero=(char*)malloc(sizeof(char));
	do {
		fflush(stdin);
		printf("%s:", peticion);
		scanf("%s", cNumero);
		fNumero=atof(cNumero);
	}while(fNumero<=0);
	return fNumero;
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
int iGenerarNumCuenta(){
	
	if(iNumeroUsuarios==0)
	{
		vtrBaseUsuarios=(regUsuario *)malloc(sizeof(regUsuario));
		return iNumeroUsuarios+1;
	}
	else{
		vtrBaseUsuarios=(regUsuario *)realloc(vtrBaseUsuarios, sizeof(regUsuario)*(iNumeroUsuarios+1));
		return iNumeroUsuarios+1;
	}
}

