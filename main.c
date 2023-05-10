#include <stdio.h>
#include "Archivos.h"



int main(int argc, char *argv[]) {
  Lista *L;
  FILE *p;
  int n, pos, elemento;
  L = Crearlista();
  p = abrirarchivoleer(argv[1]);
  fscanf(p, "%d", &n);
  L = ingresardatos(L, p, n);
  mostrar_elementos(L);
  pos = Buscar_elemento(L, 5);
  n = Largo_lista(L);
  Actualizar_Lista(L, pos, 10);
  mostrar_elementos(L);
  elemento = PrimeroLista(L);
  printf("Primero: %d", elemento);
  elemento = UltimoLista(L);
  printf("Ultimo: %d", elemento);
  

  
  fclose(p);
}