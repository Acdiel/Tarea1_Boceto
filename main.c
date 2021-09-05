#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include"canciones.h"

const char *get_csv_field (char * tmp, int k) {
  int open_mark = 0;
  char* ret=(char*) malloc (1000*sizeof(char));
  int ini_i=0, i=0;
  int j=0;
  while(tmp[i+1]!='\1'){

    if(tmp[i]== '\"'){
        open_mark = 1-open_mark;
        if(open_mark) ini_i = i+1;
        i++;
        continue;
    }

    if(open_mark || tmp[i]!= ','){
        if(k==j) ret[i-ini_i] = tmp[i];
        i++;
        continue;
    }

    if(tmp[i]== ','){
      if(k==j) {
        ret[i-ini_i] = 0;
        return ret;
      }
      j++; ini_i = i+1;
    }

    i++;
  }

  if(k==j) {
      ret[i-ini_i] = 0;
      return ret;
  }


  return NULL;
}


int main(void) {

int i;

  char archivo[20];
  char nombre[41];
  char artista[11];
  char genero[11];
  char lista[10];
  char año[7];

  Cancion* nuevo;

  List * listaCanciones;
  listaCanciones = createList();


  int op;

    while (op!=0)
    {   
        printf("---------------------------------------------------\n");
        printf("1.- Importar Canciones\n");
        printf("2.- Exportar Canciones\n");
        printf("3.- Agregar Cancion\n");
        printf("4.- Buscar Cancion por Nombre\n");
        printf("5.- Buscar Cancion por Artista\n");
        printf("6.- Buscar Cancion por Genero\n");
        printf("7.- Eliminar Cancion\n");
        printf("8.- Mostrar nombres de las listas de reproducción\n");
        printf("9.- Mostrar una lista de reproducción\n");
        printf("10.- Mostrar todas las cancionesn\n");
        printf("0.- Salir\n");
        printf("---------------------------------------------------\n");
        printf("Indica la opcion: ");
        scanf("%d", &op);
        printf("\n");

        switch(op)
        {         
      
/*----------------------------------------------------------------*/   
    
case 1: printf("IMPORTAR CANCIONES \n");
// Se abre el archivo de mundos csv en modo lectura "r"

   
    char archivo [30];
    printf("Escriba el nombre del archivo: \n");
    scanf("%s", archivo);
    int llave;
    llave = strcmp (archivo, "canciones.csv") ;
    
    if (llave == 0)
  {
    FILE *fp = fopen ("canciones.csv", "r");


    // Cadena para guardar la linea completa del archivo csv
    char linea[1024];
    int i;

    fgets (linea, 1023, fp);
    int k=0;
    while (fgets (linea, 1023, fp) != NULL) { // Se lee la linea
        for(i=0;i<1;i++){
            const char *aux = get_csv_field(linea, i); // Se obtiene el nombre
            printf("%s ",aux);
        }

        printf("\n");
        k++; if(k==100) break;
    }
  
    return 0;
  }else{
    return 0;
  }
/*-----------------------------------------------------------------*/



/*-----------------------------------------------------------------*/
   // case 2: printf("EXPORTAR CANCIONES\n");
/*-----------------------------------------------------------------*/


/*-----------------------------------------------------------------*/

   case 3: printf("AGREGAR CANCION \n");
   
   char nombre[40];
   char artista[40];
   char genero[40];
   char año[40];
   char lista[40];

   printf("Ingresar Nombre de la Cancion: \n");
   scanf("%s",nombre);
   printf("Ingresar Artista: \n");
   scanf("%s",artista);
   printf("Ingresar Genero: \n");
   scanf("%s",genero);
   printf("Ingresar Año: \n");
   scanf("%s",año);
   printf("Ingresar Lista de Reproduccion: \n");
   scanf("%s",lista);

   FILE *fpA = fopen ("canciones.csv", "a");
   fputc('\n',fpA);
   fputs(nombre,fpA);
   fputs(artista,fpA);
   fputs(genero,fpA);
   fputs(año,fpA);
   fputs(lista,fpA);

   fclose(fpA);

   agregarCancion(listaCanciones,nombre,artista,genero,lista,año);

   return 0;

/*-----------------------------------------------------------------*/


/*-----------------------------------------------------------------*/

   case 4: printf("BUSCAR CANCION POR NOMBRE\n");
   printf("\n");
   char nombre2;
   printf("Ingrese el nombre de la cancion:\n");
   scanf("%s",&nombre2);

   FILE *fp5 = fopen("canciones.csv", "r");
   //Abrir archivo 
    char linea0[1024];
    fgets (linea0, 1023, fp5);
    int k0=0;
    while (fgets (linea0, 1023, fp5) != NULL) { // Se lee la linea++)
        for(i=0;i<1;i++){
          
          const char* aux = get_csv_field(linea0, i); // Se obtiene la linea
        if(*aux == nombre2){
              printf("%s",linea0);
              
             return 0;
            }
          
        }
        k0++; if(k0==100) break;
    }
    return 0;

/*-----------------------------------------------------------------*/


/*-----------------------------------------------------------------*/

case 5 : printf("BUSCAR CANCIÓN POR ARTISTA\n");
printf("\n");
char artista1;
printf("Ingrese el nombre del artista\n");
scanf("%s", &artista1);
FILE *fp6 = fopen("canciones.csv", "r");
//Se procede a abrir el archivo
 char lineas[1024];
 fgets (lineas , 1023 , fp6);
 while (fgets (lineas, 1023, fp6) != NULL)
 {
   for( i = 0; i < 3 ; i++)
   {
   const char* aux = get_csv_field(lineas, i);
    if(*aux == artista1 )
    {
      printf("%s", lineas);
    }
   }
 }
 return 0;

/*-----------------------------------------------------------------*/
 
/*-----------------------------------------------------------------*/
    //case6 printf("BUSCAR CANCIÓN POR GÉNERO\n");
/*-----------------------------------------------------------------*/


/*-----------------------------------------------------------------*/

  case 7: printf("ELIMINAR CANCION \n");
  
  printf("Nombre de la Cancion:  ");
        scanf(" %[^\n]",nombre);

        printf("----------------------\n");
        printf("  CANCION ELIMINADA\n");
        printf("----------------------\n");

        return 0;

/*-----------------------------------------------------------------*/

/*-----------------------------------------------------------------*/
 //case8 printf("NOMBRES DE LAS LISTAS DE REPRODUCCIÓN\n");
/*-----------------------------------------------------------------*/


/*-----------------------------------------------------------------*/
 //case9 printf("MOSTRAR LIsTA DE REPRODUCCIÓN\n")
/*-----------------------------------------------------------------*/


/*-----------------------------------------------------------------*/

  case 10: printf("MOSTRAR TODAS LAS CANCIONES \n");
  printf("\n");

    FILE *fp2 = fopen ("canciones.csv", "r");

    char linea2[1024];
    fgets (linea2, 1023, fp2);
    int k2=0;
    while (fgets (linea2, 1023, fp2) != NULL) { // Se lee la linea
        for(i=0;i<1;i++){
            const char* aux = get_csv_field(linea2, i); // Se obtiene el nombre
            printf("%s ",aux);
        }
        k2++; if(k2==100) break;
    }
    return 0;

/*-----------------------------------------------------------------*/
  


  
     
  }
    }

}

