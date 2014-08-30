#include <stdio.h>
#include <iostream.h>
#include <string.h>
#include <time.h>

using namespace std;

typedef char 	StringN[40];
typedef char 	StringF[19];
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
    long long acum=0; 
    FILE		*pArchivo;
    str_linea   linea;
    char 		*token;
    Retail 	vNombre[9999];
    pArchivo=fopen("ventas.csv","rt");
     while (!feof(pArchivo))
	 {
		fgets(linea,MAXLINEA,pArchivo);
		
	
        token = strtok(linea,"\"\";");
        		
			if(strcmp(Nombre,token)==0)
			{
                strcpy(vNombre[i].sNombre,token);
                token = strtok(NULL,"\";");
                
	        	if(strcmp(FechaI,token)==0)
	        	{
                cout<<"fecha iguales"<<endl;
	         	strcpy(vNombre[i].sFecha,token);
		
	         	token = strtok(NULL,"\";");
	        	vNombre[i].Monto = atof(token);
	        	acum=acum+vNombre[i].Monto;
		        //cout<<acum<<endl;
                i++;     
                } 
                
                
                while()
                {
                     
                 }
                
                
                
                if(strcmp(FechaT,token)==0)
		        {
                 
                 cout<<"fecha termino"<<endl;
                 cout<<acum<<endl;
                }
                
              }  
              else
              {
                  //cout<<"No Son iguales"<<endl;
                  token = strtok(NULL,"\";");
	         	  token = strtok(NULL,"\";");
              }
          }         
}


int main()
{
    StringN nombre;
    StringF fechai;
    StringF fechat;

/*cout<<"ingrese nombre de la tienda"<<endl;
cin>>nombre;
cout<<"ingrese fecha inicio"<<endl;
cin>>fechai;
cout<<"ingrese fecha termino"<<endl;
cin>>fechat;
//cin.getline(fecha,19);*/



//calcularM(nombre,fechai,fechat);
calcularM("Falaferia","2013-01-01 00:49:02","2013-12-31 21:41:47");
 
      

     system("pause");
}
