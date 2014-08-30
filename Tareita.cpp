#include <stdio.h>
#include <iostream.h>

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

float calcularM (StringN Nombre,StringF Fecha)
{
    int acum=0; 
     while (!feof(pArchivo))
	 {
		fgets(linea,MAXLINEA,pArchivo);
		
	
        token = strtok(linea,"\"\";");
		strcpy(vNombre[i].sNombre,token);
		
			if(Nombre==vNombre[i].sNombre)
			{
	        	token = strtok(NULL,"\";");
	         	strcpy(vNombre[i].sFecha,token);
		
	         	token = strtok(NULL,"\";");
	        	vNombre[i].Monto = atof(token);
	        	acum=acum+vNombre[i].Monto;
		
		        cout<<acum<<endl;
                i++;      
              }  
          }         
     return  acum;
}
int main()
{
    FILE		*pArchivo;
    str_linea   linea;
    char 		*token;
    Retail 	vNombre[9999];
    int i=0;
    
    pArchivo=fopen("ventas.csv","rt");//abre un fichero de texto para lectura
        /*if(pArchivo==NULL)
	    {
            cout<<"No se pudo abrir el Archivo de Entrada.\n";
        }
	    else
	    {
		    cout<<"El archivo se abrio correctamente.\n";
        }*/
      cout<<  
        
        
     while (!feof(pArchivo))
	 {
		fgets(linea,MAXLINEA,pArchivo);
		
		token = strtok(linea,"\"\";");
		strcpy(vNombre[i].sNombre,token);
		
		token = strtok(NULL,"\";");
		strcpy(vNombre[i].sFecha,token);
		
		token = strtok(NULL,"\";");
		vNombre[i].Monto = atof(token);
		
		/*cout<<vNombre[i].sNombre<<endl;
		cout<<vNombre[i].sFecha<<endl;
		cout<<vNombre[i].Monto<<endl;*/
		cout<<i<<endl;
        i++;      
     }
     fclose(pArchivo);
     
     /*for(i=0;i<2;i++)
	{
		cout<<"Nombre: "<<vLibro[i].sNombre<<endl;
		cout<<"Fecha: "<<vLibro[i].sAutor<<endl;
		cout<<"Monto: "<<vLibro[i].fPrecio<<endl;
		cout<<setw(8)<<setfill('-')<<"-"<<endl;
	}*/	
     system("pause");
}
