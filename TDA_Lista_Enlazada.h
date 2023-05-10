#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//Estructura nodo
typedef struct nodo{
    int valor;
    struct nodo *sig; 
}nodo;

//Estructura lista
typedef struct lista{
    struct nodo *head;
    int n;
}Lista;

//Funciones elementales
nodo *Crear_nodo();
Lista *Crearlista();

//Funciones para Listas
Lista *Insertar_al_final(Lista *lista, int val);
Lista *Insertar_al_inicio(Lista *lista, int val);
Lista *Eliminar_al_Final(Lista *lista);
Lista *Eliminar_al_Inicio(Lista *lista);
Lista *Actualizar_Lista(Lista *lista, int posicion, int valor);
int Buscar_elemento(Lista *lista, int val);
int Largo_lista(Lista *lista);
int PrimeroLista(Lista *lista);
int UltimoLista(Lista *lista);
bool isvacia(Lista *lista);
int recuperar_elemento(Lista *lista, int posicion);

//Funciones que se pueden usar para la lista
void suma_elementos(Lista *L);
void par_impar(Lista *L);
Lista *elevar_elementos_a_x(Lista *L, int exp);

/*Funciones*/
nodo *Crear_nodo(){
    nodo *n;
    n = (nodo*)malloc(sizeof(nodo));
    n->valor = 0;
    n->sig = NULL;
    return n;
}
Lista *Crearlista(){
     Lista *L;
    L = (Lista*)malloc(sizeof(Lista));
    L->head = NULL;
    return L;
}
Lista *Insertal_al_final(Lista *lista, int val){
    nodo *aux;
    nodo *nuevo;
    nuevo = Crear_nodo();
    nuevo->valor = val;
    if(lista->head != NULL){
        aux = lista->head;

        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
    else{
        lista->head = nuevo;
    }
    return lista;
}
Lista *Insertar_al_inicio(Lista *lista, int val){
    nodo *nuevo;
    nodo *aux = lista->head;
    nuevo = Crear_nodo();
    nuevo->valor = val;
    if(aux != NULL){
        nuevo->sig = aux;
        lista->head = nuevo;
    }
    else{
        lista->head = nuevo;
    }
    return lista;
}
Lista *Eliminar_al_Final(Lista *lista){
    nodo *aux = lista -> head;
    nodo *aux2;
    if(lista -> head != NULL){
        while(aux -> sig -> sig != NULL){
            aux = aux -> sig;
        }
        // Guardamos el último elemento
        aux2 = aux -> sig;
        // Eliminamos de la lista el último elemento
        aux -> sig = NULL;
        // Liberamos memoria del último elemento recién eliminado de la lista
        free(aux2);
    }
    return lista;
}
Lista *Eliminar_al_Inicio(Lista *lista){
    nodo *aux = lista -> head;
    if(lista -> head != NULL){
        if(lista -> head -> sig != NULL){
            lista -> head = lista -> head -> sig;
            free(aux);
        } else {
            lista -> head = NULL;
        }
    }
    return lista;
}
int Buscar_elemento(Lista *lista, int val){
    nodo *aux;
    int pos = 0;
    aux  = lista->head;
    while(aux->sig != NULL){
        pos= pos + 1;
        if(aux->valor == val){
        printf("El elemento %d esta dentro de la lista y se encuentra en la posicion %d\n", val, pos);
        }
    aux = aux->sig;
    }
    return pos;
}
int Largo_lista(Lista *lista){
    nodo *aux; //Puntero tipo Lista el cual nos permitira movernos dentro de la lista 
    int count = 0;
    aux = lista->head;
    while(aux->sig != NULL){ //Mientras que el puntero auxiliar apunte hacia el siguiente y este sea distinto de null se movera
        count = count + 1;
        aux = aux->sig;  //El auxiliar toma la siguiente direccion de memoria del siguiente nodo y este se mueve ahi.
    }
    return count;
}
Lista *Actualizar_Lista(Lista *lista, int posicion, int valor){
  nodo *aux;
  int pos = 0;
  aux = lista->head;
  while(aux->sig != NULL)
  {
    pos = pos + 1;
    if(pos == posicion)
    {
      aux->valor = valor;
      printf("Lista actualizada correctamente\n");
    }
    aux = aux->sig;
  }
  return lista;
}
void mostrar_elementos(Lista *lista){
  nodo *aux;
  aux = lista->head;
  while(aux->sig!=NULL)
  {
    printf("%d->", aux->valor);
    aux = aux->sig;
  }
  printf("NULL");
  printf("\n");
}
int PrimeroLista(Lista *lista){
  nodo *aux;
  int elemento = 0, pos = 0;
  aux = lista->head;
  while (aux->sig != NULL)
  { 
    pos = pos + 1;
    if (pos == 1)
    { 
      elemento = aux->valor;
    }
    aux = aux->sig;
  }
  return elemento;
}
int UltimoLista(Lista *lista){
  nodo *aux;
  int elemento = 0, pos = 0, n = 0;
  n = Largo_lista(lista);
  aux = lista->head;
  while (aux->sig != NULL)
  { 
    pos = pos + 1;
    if (pos == n)
    { 
      elemento = aux->valor;
    }
    aux = aux->sig;
  }
  return elemento;
}
bool isvacia(Lista *lista){
  nodo *aux;
  aux = lista->head;
  if (aux == NULL)
  { printf("Esta vacia");
    return 1;
  }
  else{
    printf("No esta vacia");
    return 0;
  }
}
int recuperar_elemento(Lista *lista, int posicion){
  
}
/*Funciones extras que se pueden utilizar para las listas*/

void suma_elementos(Lista *L){
  int suma = 0;
  nodo *aux;
  aux = L->head;
  while(aux->sig != NULL){
    suma = suma + aux->valor;
    aux = aux->sig;
  }
  printf("La suma de todos los elementos de el arreglo del arreglo dinamico: %d\n", suma);
}
void par_impar(Lista *L){
  nodo *aux;
  aux = L->head;
  while(aux->sig != NULL){
    if((aux->valor % 2) == 0){
      printf("El numero %d es par\n", aux->valor);
    }
    else{
      printf("El numero %d es impar\n", aux->valor);
    }
  aux = aux->sig;
  }
}
Lista *elevar_elementos_a_x(Lista *L, int exp){
  nodo *aux;
  aux = L->head;
  while(aux->sig != NULL){
    aux->valor = pow(aux->valor, exp);
    aux = aux->sig;
  }
  return L;
}
