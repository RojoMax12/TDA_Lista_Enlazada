#include <stdio.h>
#include "Archivos.h"



int main(int argc, char *argv[]) {
  Lista *L;
  FILE *p, *q;
  int n, pos, elemento;
  L = Crearlista();
  p = abrirarchivoleer(argv[1]);
  q = abrirarchivoescrib(argv[2]);
  fscanf(p, "%d", &n);
  L = ingresardatos(L, p, n);
  introducirdatos(L, q);
  mostrar_elementos(L);
  pos = Buscar_elemento(L, 5);
  n = Largo_lista(L);
  Actualizar_Lista(L, pos, 10);
  mostrar_elementos(L);
  elemento = PrimeroLista(L);
  printf("Primero: %d\n", elemento);
  elemento = UltimoLista(L);
  printf("Ultimo: %d\n", elemento);
  introducirdatos(L, q);
  elemento = recuperar_elemento(L, 5);
  printf("El elemento recuperado es: %d", elemento);
  par_impar(L, q);
  

  
  fclose(p);
  fclose(q);
}