#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>


#include <gd.h>
#include <dfonts.h>
#include "comun.h"
#include "utils.h"


using namespace std;

typedef char 	StringN[40];
typedef char 	StringF[20];
typedef char 	str_linea[255];
#define 	MAXLINEA 	225

typedef struct Retail
{
	StringN	sNombre;
	StringF sFecha;
	float Monto;
};

void graficar(StringN nombre,float monto) {

    gdImagePtr imagen;
    FILE *archivo;
    char titulo[513];
    int blanco, negro, color;
    gdFontPtr fuente = gdFontGetSmall();

    imagen = gdImageCreateTrueColor(IMG_WIDTH, IMG_HEIGHT);

    int y = 0;
    int mes = 0;
    int alto = 50;
    int ancho = 70;
    long maximo = 0;
    long paso = 0;
    double porcentaje = 0.0;

    if (imagen) {
        blanco = gdImageColorAllocate(imagen, 255, 255, 255);
        negro = gdImageColorAllocate(imagen, 0, 0, 0);


        // Pintamos el fondo Blanco
        gdImageFill(imagen, 0, 0, blanco);

        // Coloco el título
        memset(titulo, 0, 513);
        snprintf(titulo, 512, "Ventas tienda %s", nombre);
        gdImageString(imagen, fuente, (int) IMG_WIDTH * 0.4, 25, (unsigned char *) titulo, negro);

        
           

            // El alto máximo serán 500px que será el 100%
            alto = (int) (450 * porcentaje);


            // Monto
            gdImageString(imagen, fuente, ancho, IMG_HEIGHT - (BORDE_ALTO + alto + 20), (unsigned char *) longStr(monto), color);
            ancho += 55;



        // Pintamos Borde
        gdImageLine(imagen, BORDE_ANCHO, BORDE_ALTO, (IMG_WIDTH - BORDE_ANCHO), BORDE_ALTO, negro);
        gdImageLine(imagen, BORDE_ANCHO, (IMG_HEIGHT - BORDE_ALTO), (IMG_WIDTH - BORDE_ANCHO), (IMG_HEIGHT - BORDE_ALTO), negro);
        gdImageLine(imagen, BORDE_ANCHO, BORDE_ALTO, BORDE_ANCHO, (IMG_HEIGHT - BORDE_ALTO), negro);
        gdImageLine(imagen, (IMG_WIDTH - BORDE_ANCHO), BORDE_ALTO, (IMG_WIDTH - BORDE_ANCHO), (IMG_HEIGHT - BORDE_ALTO), negro);


        // Guardar imagen
        archivo = fopen("grafico.jpg", "wb");
        if (archivo != NULL) {
            gdImageJpeg(imagen, archivo, 100);
            fclose(archivo);
        }
        gdImageDestroy(imagen);
    }
}



void calcularM (StringN Nombre,StringF FechaI, StringF FechaT)
{
    int i=0;
    long  acum=0; 
    FILE		*pArchivo;
    str_linea   linea;
    char 		*token;
    int x=0;
    Retail 	vNombre[9999];
    StringF  fecha;
    pArchivo=fopen("ventas.csv","rt");
    
    while (!feof(pArchivo) && x==0)
	{
		fgets(linea,MAXLINEA,pArchivo);
        token = strtok(linea,"\"\";"); //primer avance    		
		if(strcmp(Nombre,token)==0)
		{
            strcpy(vNombre[i].sNombre,token);//compara nombre
            token = strtok(NULL,"; \"");//segundo avance valor mes
            
	        if(strcmp(FechaI,token)==0) //compara fecha de inicio
	        {
                token = strtok(NULL,"\";");//tercer avance valor hora 
                token = strtok(NULL,"\";");//cuarto avance monto
                
	        	acum=acum+atof(token); //monto inicial, se reinicia en caso de encontrar la fecha de inicio		          
            } 
            else //si no son iguales
            {                  
                
                if(strcmp(FechaT,token)==0)//pregunta si es el termino final por lo que avanza y guardara el ultimo monto y lo mostrara por pantalla
		        {     
                    token = strtok(NULL,"\";");//tercer avance valor hora 
                    token = strtok(NULL,"\";");//cuarto avance correspondiente al monto
                     x=1; 
                     cout<<"\nMONTO ACUMULADO: "<<acum<<endl; 
                                   
                } 
                
                
                token = strtok(NULL,"\";");//tercer avance valor hora 
                token = strtok(NULL,"\";");//cuarto avance correspondiente al monto    
                acum=acum+atof(token); //monto acumulado 
            }
             
        }  
        else // si los nombres no son iguales
        {
            token = strtok(NULL,"\";");//permiten que avance la lista
            token = strtok(NULL,"\";");
        }
   }
   
}

int main()
{
    StringN nombre;
    StringF fechai;
    StringF fechat;
    int op;
    while(op!=4)
    {  
		system("cls");
		cout << "\n\t\t MENU\n";
		cout << "\nGENERAR SUMA DE VENTAS DE LA TIENDA:\n";
		cout << "\t 1. CencoSux \n";
		cout << "\t 2. Falaferia \n";
		cout << "\t 3. Porahi \n";
		cout << "\t 4. Replay \n";
		cout << "\t 5. Salir                          \n";
		cout << "\t Ingrese opcion: ";
		cin>>op;
		if(op==1 || op==2 || op ==3 || op==4 || op==5)
		{
			if(op==1)
			{
				cout<<"Ingrese fecha inicio"<<endl;
				fgets(fechai,20,stdin);
				cin>>fechai;
				cout<<"la fecha de inicio es:"<<fechai<<endl;
				cout<<"ingrese fecha de termino "<<endl;
				cin>>fechat;
				cout<<"la fecha de termino es:"<<fechat<<endl;
				calcularM("CencoSux",fechai,fechat);
			}
			if(op==2)
			{
				/*cout<<"Ingrese fecha inicio"<<endl;
				cin>>fechai;
				cout<<"la fecha de inicio es:"<<fechai<<endl;
				cout<<"ingrese fecha de termino "<<endl;
				cin>>fechat;
				cout<<"la fecha de termino es:"<<fechat<<endl;
				calcularM("Falaferia",fechai,fechat);*/
				//calcularM("Falaferia","2013-01-01 00:12:33","2013-01-01 00:49:02");
				calcularM("Falaferia","2013-01-01","2013-01-04");
			}
			if(op==3)
			{
				cout<<"Ingrese fecha inicio"<<endl;
				cin>>fechai;
				cout<<"la fecha de inicio es:"<<fechai<<endl;
				cout<<"ingrese fecha de termino "<<endl;
				cin>>fechat;
				cout<<"la fecha de termino es:"<<fechat<<endl;
				calcularM("Porahi",fechai,fechat);         
			}
			if(op==4)
            {
				cout<<"Ingrese fecha inicio"<<endl;
				cin>>fechai;
				cout<<"la fecha de inicio es:"<<fechai<<endl;
				cout<<"ingrese fecha de termino "<<endl;
				cin>>fechat;
				cout<<"la fecha de termino es:"<<fechat<<endl;
				calcularM("Replay",fechai,fechat); 
			}
			if(op==5)
            {
				exit(0);
			}
			system("pause");
		}
		else
        {
			cout<<"\n\tOpcion Incorrecta \n";
			system("pause");
	    }
	}
    system("pause");
}
