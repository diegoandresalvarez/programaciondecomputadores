// LISTA SIMPLEMENTE ENLAZADA
// Adaptado de:
// http://www.thegeekstuff.com/2012/08/c-linked-list-example/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/// estructuras y tipos de datos
typedef int tipo_nodo;

struct struct_nodo
{
   tipo_nodo dato;
   struct struct_nodo *sgte;
};

typedef struct struct_nodo nodo;

typedef struct
{
   nodo *cabeza, *cola;
} lista;

// cabeza                                                  cola
// +---+                                                   +---+
// | * |                                                   | * |
// +---+                                                   +---+
//   |                                                       |
//   V                                                       V
// +-------+     +-------+     +-------+     +-------+     +--------+
// | X | *-|---->| X | *-|---->| X | *-|---->| X | *-|---->| X |NULL|
// +-------+     +-------+     +-------+     +-------+     +--------+

/// prototipos de funciones
nodo* crear_lista_enlazada(lista *L, tipo_nodo dato);
nodo* agregar_a_la_lista(lista *L, tipo_nodo dato, char ubicacion);
nodo* buscar_en_la_lista(lista *L, tipo_nodo dato, nodo **anterior);
bool borrar_de_la_lista(lista *L, tipo_nodo dato);
bool borrar_nodo_de_la_lista(lista *L, nodo *ptr_a_nodo_a_borrar);
void imprimir_lista(lista *L);

int main(void)
{
   lista milista = {.cabeza = NULL, .cola = NULL};
   nodo *ptr = NULL;

   imprimir_lista(&milista);

   for(int i = 5; i<10; i++) agregar_a_la_lista(&milista, i, 'F');
   imprimir_lista(&milista);

   for(int i = 4; i>0; i--)  agregar_a_la_lista(&milista, i, 'P');
   imprimir_lista(&milista);

   for(int i = 1; i<15; i += 3)
   {
      ptr = buscar_en_la_lista(&milista, i, NULL);
      if(ptr == NULL)
         printf("Dato [%d] no encontrado\n", i);
      else
         printf("Dato [%d] encontrado\n", ptr->dato);
   }
   imprimir_lista(&milista);

   for(int i = 1; i<15; i += 2)
   {
      if(borrar_de_la_lista(&milista, i))
         printf("Dato [%d] borrado\n",i);
      else
         printf("No se pudo borrar [%d], ya que no se encontró\n", i);

      imprimir_lista(&milista);
   }

   ptr = buscar_en_la_lista(&milista, 8, NULL);

   borrar_nodo_de_la_lista(&milista, ptr);
   imprimir_lista(&milista);

   borrar_nodo_de_la_lista(&milista, milista.cabeza);
   imprimir_lista(&milista);

   borrar_nodo_de_la_lista(&milista, milista.cola);
   imprimir_lista(&milista);

   borrar_nodo_de_la_lista(&milista, milista.cabeza);
   imprimir_lista(&milista);

   return 0;
}

// Crear la lista enlazada
// Retorna el puntero al primer nodo
// Si no hay memoria retorna un  NULL
nodo* crear_lista_enlazada(lista *L, tipo_nodo dato)
{
   printf("Creando lista enlazada cuyo nodo cabeza contiene [%d]\n", dato);
   nodo *punt_a_nuevo_nodo = (nodo*) malloc(sizeof(nodo));
   if (punt_a_nuevo_nodo == NULL)
   {
      perror("malloc() retornó un NULL");
      return NULL;
   }
   punt_a_nuevo_nodo->dato = dato;
   punt_a_nuevo_nodo->sgte = NULL;

   L->cabeza = L->cola = punt_a_nuevo_nodo;

   return punt_a_nuevo_nodo;
}

// Agregar nodo a la lista enlazada
// Si la cabeza == NULL, crea la lista enlazada
// Si ubicacion == 'P' agrega el nodo al principio (cabeza) de la lista
// Si ubicacion == 'F' agrega el nodo al final (cola) de la lista
// Si no hay memoria retorna un  NULL
// Si la lista está vacía la crea
// Retorna un puntero al principio de la lista
nodo* agregar_a_la_lista(lista *L, tipo_nodo dato, char ubicacion)
{
   if(L->cabeza == NULL) return crear_lista_enlazada(L, dato);

   nodo *punt_a_nuevo_nodo = (nodo *) malloc(sizeof(nodo));
   if(punt_a_nuevo_nodo == NULL)
   {
      perror("malloc() retornó un NULL");
      return NULL;
   }

   punt_a_nuevo_nodo->dato = dato;

   switch (ubicacion)
   {
   case 'P':
      printf("Agregando nodo cabeza de la lista con el dato [%d]\n",dato);
      punt_a_nuevo_nodo->sgte = L->cabeza;
      L->cabeza = punt_a_nuevo_nodo;
      break;
   case 'F':
      printf("Agregando nodo cola de la lista con el dato [%d]\n",dato);
      punt_a_nuevo_nodo->sgte = NULL;
      L->cola->sgte = punt_a_nuevo_nodo;
      L->cola = punt_a_nuevo_nodo;
      break;
   default:
      puts("Solo se puede agregar al principio 'P' o al final 'F' de la lista");
   }

   return punt_a_nuevo_nodo;
}

// Buscar dato en la lista enlazada
// Si no encontró el dato retorna NULL
// Si lo encontró, retorna el puntero al nodo que contiene el dato (el primero a
// partir de la cabeza); además si "anterior != NULL" retorna, por referencia,
// el nodo anterior a aquel en el cual se encuentra el dato
nodo* buscar_en_la_lista(lista *L, tipo_nodo dato, nodo **anterior)
{
   printf("Buscar en la lista el valor [%d]\n", dato);

   nodo *tmp = NULL;

   for(nodo *ptr = L->cabeza; ptr != NULL; ptr = ptr->sgte)
   {
      if(ptr->dato == dato) // se encontró el dato
      {
         if(anterior != NULL) *anterior = tmp;
         return ptr;
      }
      tmp = ptr;
   }

   return NULL;
}

// Buscar un dato de la lista y lo borra.
// Actualiza los punteros cola y cabeza
// Tiene en cuenta que puede existir un solo elemento en la lista
bool borrar_de_la_lista(lista *L, tipo_nodo dato)
{
   printf("Borrar el valor [%d] de la lista \n", dato);

   nodo *anterior = NULL;
   nodo *ptr_a_nodo_a_borrar = buscar_en_la_lista(L, dato, &anterior);
   if(ptr_a_nodo_a_borrar == NULL) return false; // no existe elemento en L

   if(anterior != NULL) anterior->sgte = ptr_a_nodo_a_borrar->sgte;

   if(ptr_a_nodo_a_borrar == L->cola)   L->cola = anterior;
   if(ptr_a_nodo_a_borrar == L->cabeza) L->cabeza = ptr_a_nodo_a_borrar->sgte;

   free(ptr_a_nodo_a_borrar);
   return true;
}

// Borra un nodo de la lista. Soporta las siguientes opciones
// Borra la cabeza
// Solo hay un nodo y cabeza == cola
// Borra la cola
// Borra nodo intermedio
// Nodo a borrar es NULL
// Nodo a borrar no existe
// La lista está vacía
bool borrar_nodo_de_la_lista(lista *L, nodo *ptr_a_nodo_a_borrar)
{
   nodo *anterior = NULL;

   if (ptr_a_nodo_a_borrar == NULL) return false; // no borre nada

   if (L->cabeza == ptr_a_nodo_a_borrar) // se borrará la cabeza
   {
      L->cabeza = ptr_a_nodo_a_borrar->sgte;
      if (L->cola == ptr_a_nodo_a_borrar) L->cola = NULL;
      free(ptr_a_nodo_a_borrar);
      return true;
   }

   for(nodo *ptr = L->cabeza; ptr != NULL; ptr = ptr->sgte)
   {
      if(ptr->sgte == ptr_a_nodo_a_borrar) // se encontró el nodo
      {
         ptr->sgte = ptr_a_nodo_a_borrar->sgte;
         if (L->cola == ptr_a_nodo_a_borrar) L->cola = ptr;
         free(ptr_a_nodo_a_borrar);
         return true;
      }
      anterior = ptr;
   }

   puts("Nodo no encontrado o lista vacía");
   return false;
}

// Imprimir la lista enlazada
void imprimir_lista(lista *L)
{
   if (L->cabeza == NULL)
   {
      printf("CABEZA = %p/COLA = %p\n", L->cabeza, L->cola);
      puts("*** Lista vacía ***\n");
      return;
   }

   puts("*** Inicio de la lista ***");
   printf("CABEZA = %p/COLA = %p\n", L->cabeza, L->cola);
   for(nodo *ptr = L->cabeza; ptr != NULL; ptr = ptr->sgte)
      printf("%p -> [%d # %p]\n", ptr, ptr->dato, ptr->sgte);

   puts("*** Final de la lista ***\n");
}
