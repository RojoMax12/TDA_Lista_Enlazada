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
Lista *ingresardatos(Lista *L, FILE *p, int n);

//Funciones que se pueden usar para la lista
void suma_elementos(Lista *L);
void par_impar(Lista *L, FILE *q);
Lista *elevar_elementos_a_x(Lista *L, int exp);
Lista *cambiarelementos(Lista *L, int a, int b);
void introducirdatos(Lista *L, FILE *q);

/*Funciones*/

/*Funcion que crea los nodos*/
nodo *Crear_nodo(){
    nodo *n;
    n = (nodo*)malloc(sizeof(nodo));
    n->valor = 0;
    n->sig = NULL;
    return n;
}

/*Funcion que crea la lista*/
Lista *Crearlista(){
     Lista *L;
    L = (Lista*)malloc(sizeof(Lista));
    L->head = NULL;
    return L;
}

/*Funcion que inserta los nodos al final de la lista ya creada*/
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

/*Funcion que inserta los nodos de la lista enlazada al comienzo de esta*/
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

/*Funcion que elimina el ultimo nodo de la lista enlazada*/
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

/*Funcion que elimina el primer nodo de la lista enlazada*/
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

/*Funcion que retorna la posicion del valor que buscamos en la lista enlazada*/
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

/*Funcion que nos retorna el largo de la lista enlazada*/
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

/*Funcion que actualiza el valor en la posicion indicada de la lista enlazada*/
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

/*Muestra todo los datos de lista enlazada*/
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

/*Funcion que retorna el primer elemento de la lista enlazada*/
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

/*Funcion que retorna el ultimo elemento de la lista enlazada*/
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

/*Funcion que verifica si la lista esta vacia retorna True = 1 si es verdadero y por otro lado False = 0 si esta no lo esta*/
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

/*Funcion que recupera un elemento en la posicion indicada*/
int recuperar_elemento(Lista *lista, int posicion){
  int cont = 0, elemento = 0;
  nodo *aux;
  aux = lista->head;
  while (aux->sig!= NULL)
  { 
    cont = cont + 1;
    if (cont == posicion)
    {
      elemento = aux->valor;
    }
    aux = aux->sig;
  }
  return elemento;
}

/*Funcion que sirve para introducir los datos de un archivo a la lista enlazada*/
Lista *ingresardatos(Lista *L, FILE *p, int n){
  int datos;
  for(int i = 0; i <= n; i++){
    fscanf(p, "%d", &datos);
    L  = Insertal_al_final(L, datos);
  }
  return L;
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

void par_impar(Lista *L, FILE *q){
  nodo *aux;
  aux = L->head;
  while(aux->sig != NULL){
    if((aux->valor % 2) == 0){
      fprintf(q, "El numero %d es par\n", aux->valor);
    }
    else{
      fprintf(q, "El numero %d es impar\n", aux->valor);
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
