#include <stdio.h>
#include <iostream.h>
#include <string.h>

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

void calcularM (StringN Nombre,StringF FechaI, StringF FechaT)
{
    int i=0;
    long  acum=0; 
    FILE		*pArchivo;
    str_linea   linea;
    char 		*token;
    Retail 	vNombre[9999];
    pArchivo=fopen("ventas.csv","rt");
    while (!feof(pArchivo))
	{
		fgets(linea,MAXLINEA,pArchivo);
        token = strtok(linea,"\"\";"); //primer avance    		
		if(strcmp(Nombre,token)==0)
		{
            strcpy(vNombre[i].sNombre,token);//compara nombre
            token = strtok(NULL,"\";");//segundo avance       
	        if(strcmp(FechaI,token)==0) //compara fecha de inicio
	        {
	         	token = strtok(NULL,"\";");//tercer avance
	        	acum=acum+atof(token); //monto inicial, se reinicia en caso de encontrar la fecha de inicio		          
            } 
            else //si no son iguales
            {                  
                if(strcmp(FechaT,token)==0)//pregunta si es el termino final por lo que avanza y guardara el ultimo monto y lo mostrara por pantalla
		        {     
                    token = strtok(NULL,"\";");//tercer avance correspondiente al monto
                    acum=acum+atof(token); //monto acumulado                 
                    cout<<"fecha termino "<<acum<<endl;        
                } 
                token = strtok(NULL,"\";");//tercer avance correspondiente al monto
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
	
	cout<<"ingrese nombre de la tienda"<<endl;
	cin>>nombre;
	cout<<"ingrese fecha inicio"<<endl;
	fgets(fechai,20,stdin);
	cin.getline(fechai,20);
	cout<<"la fecha de inicio es:"<<fechai<<endl;
	cout<<"ingrese fecha de termino "<<endl;
	scanf("%[^\n]", fechat);
	cout<<"la fecha de termino es:"<<fechat<<endl;
	
	calcularM(nombre,fechai,fechat);
	/*calcularM("Falaferia","2013-01-01 00:12:33","2013-12-31 09:20:46");*/
    system("pause");
}
