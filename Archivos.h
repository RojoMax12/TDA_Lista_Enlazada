#include <stdio.h>
#include "TDA_Lista_Enlazada.h"

/*Encabezado de funciones*/
FILE *abrirarchivoleer(char *nomA);
FILE *abrirarchivoescrib(char *nombre);
void introducirdatos(Lista *L, FILE *q);

/*Funcion para abrir un archivo en modo lectura*/
FILE *abrirarchivoleer(char *nomA){
  FILE *p;
  p = fopen(nomA, "r");
  if(p != NULL){
    printf("El archivo a sido correctamente abierto\n");
  }
  else{
    printf("Error al abrir el archivo\n");
  }
  return p;
}

/*Funcion para abrir un archivo en modo escritura*/
FILE *abrirarchivoescrib(char *nombre){
  FILE *p;
  p = fopen(nombre, "w");
  if(p != NULL){
    printf("El archivo a sido correctamente creado\n");
  }
  else{
    printf("Error al crear el archivo el archivo\n");
  }
  return p;
}

/*Funcion que se usa con un archivo tipo "w" el cual se podra escribir los datos recolectados*/
void introducirdatos(Lista *L, FILE *q){
  nodo *aux;
  aux = L->head;
  while (aux->sig != NULL)
  {
    fprintf(q, "%d->", aux->valor);
    aux = aux->sig;
  }
  fprintf(q,"NULL\n");
}

