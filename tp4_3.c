#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Tarea{
int TareaID; //Numerado en ciclo iterativo
char *Descripcion; //
int Duracion; // entre 10 – 100
} typedef Tarea;

struct Nodo{
Tarea T;
struct Nodo *Siguiente;
} typedef TNodo;

TNodo * crearListaVacia();
TNodo * CrearNodo(Tarea tarea); 
void InstertarNodo(TNodo ** start, Tarea tarea);

 

 int main(){
    TNodo *start = crearListaVacia(); 


    return 0;
 }

 TNodo *crearListaVacia(){
    return NULL;
 }


TNodo * CrearNodo(Tarea tarea){
    TNodo *newNodo = (TNodo*) malloc(sizeof(TNodo));
    newNodo->T =tarea; 
    newNodo->Siguiente= NULL; 
    return newNodo;
    
}

void InstertarNodo(TNodo ** start, Tarea tarea){

TNodo *newNodo =CrearNodo(tarea);
newNodo->Siguiente=*start;
*start=newNodo;



}