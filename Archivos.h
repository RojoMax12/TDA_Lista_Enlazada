#include <stdio.h>
#include "TDA_Lista_Enlazada.h"

FILE *abrirarchivoleer(char *nomA);

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


Lista *ingresardatos(Lista *L, FILE *p, int n){
  int datos;
  for(int i = 0; i <= n; i++){
    fscanf(p, "%d", &datos);
    L  = Insertal_al_final(L, datos);
  }
  return L;
}


Lista *cambiarelementos(Lista *L, int a, int b){
  nodo *aux1, *aux2;
  int aux3;
  aux1 = L->head;
  aux2 = L->head;
  while(aux1->sig && aux2->sig != NULL){
    if(aux1->valor == a && aux2->valor == b){
      aux3 = aux1->valor;
      aux1->valor = aux2->valor;
      aux2->valor = aux3;
    }
  aux1 = aux1->sig;
  aux2 = aux2->sig;
  }
  return L;
}