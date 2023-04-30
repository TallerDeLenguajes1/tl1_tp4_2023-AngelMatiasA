#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// int idL = 0;
struct Tarea
{
    int id;
    char *descripcion;
    int duracion;
    float precio;
} typedef Tarea;

struct Nodo
{
    Tarea tarea;
    struct Nodo *siguiente;
} typedef Nodo;

Nodo *CrearListaVacia();
Nodo *CrearNodo(Tarea tarea);
Tarea cargarTarea();
void AgregarLibro(Nodo **Lista, Tarea Tarea);
void MostrarLista(Nodo *lista);
void eliminarLibroPorId(Nodo **lista, int id);
void moverTarea(Nodo **listaPend, Nodo **listaRealizado);
// void BuscarTareasPorId(Tarea *tareasP, Tarea *tareasR);
Nodo *BuscarTareaID(Nodo *tareasPend, Nodo *tareasReal);
void BuscarTareaPorPalabra(Nodo *tareasP, Nodo *tareasR, char *palabra);
void eliminarTareaPorId(Nodo **listaP, Nodo **listaR);
int main()
{
    int idEliminar;

    Nodo *listaPendientes = CrearListaVacia();
    Nodo *listaRealizado = CrearListaVacia();
    Nodo *auxPBorrar;
    Nodo *aux;
    int opcion = 0;
    int opcion2 = 1;
    Tarea libroAux;
    int idaux = 0;
    int *id = idaux; // si le pongo ampersan solo muestra la direcc d memoria,
    // si no le pongo me muestra warning del casteo

    char buffer[50];
    char *palabra;
    do
    {
        opcion2 = 1;
        printf("Seleccione una opcion:\n");
        printf("1-Cargar nueva tarea \n");
        printf("2-Mover tareas \n");
        printf("3-Buscar tarea por ID \n");
        printf("4-Buscar tarea por Palabra \n");
        printf("5-Mostrar tareas realizadas \n");
        printf("6-Mostrar tareas pendientes \n");
        printf("7-Eliminar tareas  \n");

        printf("8-Cerrar \n");
        scanf("%d", &opcion);
        fflush(stdin);
        switch (opcion)
        {
        case 1:
            while (opcion2 == 1)
            {
                libroAux = cargarTarea(&id);
                AgregarLibro(&listaPendientes, libroAux);
                printf("quiere cargar otra tarea \n 1: para si, 0 para no \n");
                scanf("%d", &opcion2);
                fflush(stdin);
            }

            break;

        case 2:

            printf("Comienza a mover \n ********************* \n");

            moverTarea(&listaPendientes, &listaRealizado);
            break;

        case 3:
            // BuscarTareasPorId(listaPendientes, listaRealizado);
            aux = BuscarTareaID(listaPendientes, listaRealizado);

            if (aux)
            {

                printf("Se enontro la tarea de id nro  %d\n", aux->tarea.id);
                printf("el descripcion del tarea es : ");
                puts(aux->tarea.descripcion);

                printf("la duracion de la tarea es : %d \n ", aux->tarea.duracion);
            }
            else
            {
                printf("no se enontro la tarea buscada  \n");
            }

            break;

        case 4:
            printf("ingrese la palabra clave a buscar \n");
            gets(buffer);
            fflush(stdin);
            palabra = malloc(sizeof(char) * strlen(buffer));
            strcpy(palabra, buffer);
            BuscarTareaPorPalabra(listaPendientes, listaRealizado, palabra);

            break;

        case 5:

            printf("  ******************\n Mostrar lista de realizado  \n");
            MostrarLista(listaRealizado);
            break;

        case 6:
            printf("******************\n Mostrar lista de pendientes  \n ");
            MostrarLista(listaPendientes);
            break;
        case 7:
            eliminarTareaPorId(&listaPendientes, &listaRealizado);
            // printf("ingrese el id del tarea a eliminar \n");
            // scanf("%d", &idEliminar);
            // fflush(stdin);
            // eliminarLibroPorId(&listaRealizado, idEliminar);
            // eliminarLibroPorId(&listaPendientes, idEliminar);

            //          printf("para eliminar de pendientes ingrese 1, de realizado ingrese 2 \n");
            //          scanf("%d", &opcion2);
            //          fflush(stdin);
            //         switch (opcion2)
            //         {
            //         case 1:
            //             printf("ingrese el id del tarea a eliminar \n");
            // scanf("%d", &idEliminar);
            // fflush(stdin);
            //         eliminarLibroPorId(&listaPendientes, idEliminar);

            //             break;

            //         case 2:
            //             printf("ingrese el id del tarea a eliminar \n");
            // scanf("%d", &idEliminar);
            // fflush(stdin);

            //         eliminarLibroPorId(&listaRealizado, idEliminar);
            //             break;

            //         default:
            //             break;
            //         }

            break;

        default:
            break;
        }

    } while (opcion != 8);

    while (listaPendientes)
    {
        free(listaPendientes);
        listaPendientes = listaPendientes->siguiente;
    }

    return 0;
}

void BuscarTareaPorPalabra(Nodo *tareasP, Nodo *tareasR, char *palabra)
{
    Nodo *aux = tareasP;
    while (aux && strstr(aux->tarea.descripcion, palabra) == NULL)
    {
        aux = aux->siguiente;
    }
    if (aux == NULL)
    {
        aux = tareasR;
        while (aux && strstr(aux->tarea.descripcion, palabra))
        {
            aux = aux->siguiente;
        }
        if (aux == NULL)
        {
            printf("no se encontro la tarea \n");
        }
        else
        {
            printf("Se encontro la tarea  de id %d\n", aux->tarea.id);
            printf("La descripcion de la tarea es ");
            puts(aux->tarea.descripcion);
        }
    }
    else
    {
        printf("Se encontro la tarea  de id %d\n", aux->tarea.id);
        printf("La descripcion de la tarea es ");
        puts(aux->tarea.descripcion);
    }
}

Nodo *CrearListaVacia()
{
    return NULL;
}
Nodo *CrearNodo(Tarea tarea)
{
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    aux->tarea.id = tarea.id;
    aux->tarea.descripcion = malloc(sizeof(char) * strlen(tarea.descripcion));
    strcpy(aux->tarea.descripcion, tarea.descripcion);
    aux->tarea.duracion = tarea.duracion;
    aux->siguiente = NULL;
    return aux;
}
Tarea cargarTarea(int *id)
{
    Tarea aux;
    char buffer[20];
    (*id)++;
    aux.id = *id;
    printf("ingrese la descripcion de la tarea \n");
    gets(buffer);
    fflush(stdin);
    aux.descripcion = malloc(sizeof(char) * strlen(buffer));
    strcpy(aux.descripcion, buffer);

    printf("ingrese la duracion de la tarea \n");
    scanf("%d", &aux.duracion);
    fflush(stdin);

    return aux;
}
void AgregarLibro(Nodo **Lista, Tarea Tarea)
{
    Nodo *nuevoNodo = CrearNodo(Tarea);
    nuevoNodo->siguiente = *Lista;
    *Lista = nuevoNodo;
}
void agregarNodo(Nodo **lista, Nodo *newNodo)
{
    newNodo->siguiente = *lista;
    *lista = newNodo;
}
void MostrarLista(Nodo *lista)
{

    int indice = 0;
    Nodo *aux = lista;
    while (aux)
    {
        printf("************* \n ");
        //   printf("el tarea numero %d ", indice);
        printf("el id del tarea es : %d \n ", aux->tarea.id);
        printf("el descripcion del tarea es : ");
        puts(aux->tarea.descripcion);

        printf("la duracion de la tarea es : %d \n ", aux->tarea.duracion);

        aux = aux->siguiente;
        indice++;
    }
}

void eliminarLibroPorId(Nodo **lista, int id)
{
    Nodo *aux = *lista;
    Nodo *auxAnterior = *lista;
    while (aux && aux->tarea.id != id)
    {
        auxAnterior = aux;
        aux = aux->siguiente;
    }
    if (aux == *lista)
    {
        *lista = aux->siguiente;
        free(aux);
        // printf("Se elimino la tarea de id nro  %d\n", id);
    }
    else if (aux)
    {
        auxAnterior->siguiente = aux->siguiente;
        free(aux);
        // printf("Se elimino la tarea de id nro %d\n", id);
    }
    else
    {
        printf("no se encontro la tarea de id nro %d\n", id);
    }
}

/*se puede hacer void evaluando el valor de aux dentro de la funcion*/
void eliminarTareaPorId(Nodo **listaP, Nodo **listaR)
{
    int id;
    printf("ingrese el id de la tarea a buscar \n");
    scanf("%d", &id);
    fflush(stdin);
    Nodo *aux = *listaP;
    Nodo *auxAnterior = NULL;
    while (aux && aux->tarea.id != id)
    {
        auxAnterior = aux;
        aux = aux->siguiente;
    }
    if (aux == *listaP)
    {
        *listaP = aux->siguiente;
        free(aux);
        printf("Se elimino la tarea de id nro %d de la lista de Pendientes\n", id);
    }
    else if (aux)
    {
        auxAnterior->siguiente = aux->siguiente;
        free(aux);
        printf("Se elimino la tarea de id nro %d de la lista de Pendientes\n", id);
    }
    else if (aux == NULL)
  
    { 
        printf("ingresa al aux == null y redefine aux");
        aux = *listaR;
        while (aux!= NULL && aux->tarea.id != id)
        {
            auxAnterior = aux;
            aux = aux->siguiente;
        }
        if (aux == NULL)
        {
            printf("no se encontro la tarea de id nro %d\n", id);

        } else
       
        if (aux == *listaR)
        {
            *listaR = aux->siguiente;
            free(aux);
            printf("Se elimino la tarea de id nro %d de la lista de Realizados\n", id);
        }
        else if (aux!=NULL)
        {
            auxAnterior->siguiente = aux->siguiente;
            free(aux);
            printf("Se elimino la tarea de id nro %d de la lista de Realizados\n", id);
         }
     
        }
        
    
    // }else
    //     {
    //         printf("no se encontro la tarea de id nro %d\n", id);
    //     }


}
Nodo *BuscarTareaID(Nodo *tareasPend, Nodo *tareasReal)
{
    int id;
    printf("ingrese el id de la tarea a buscar \n");
    scanf("%d", &id);
    fflush(stdin);
    Nodo *aux = tareasPend;
    while (aux != NULL && aux->tarea.id != id)
    {
        aux = aux->siguiente;
    }
    if (aux == NULL)
    {
        aux = tareasReal;
        while (aux != NULL && aux->tarea.id != id)
        {
            aux = aux->siguiente;
        }
    }
    return aux;
}

/*preguntar porque tira advertencias si uso los mismos parametros q la funcion anterior?*/
// void BuscarTareasPorId(Tarea *tareasP, Tarea *tareasR)
// {
//    int id;
//    printf("ingrese el id de la tarea a buscar \n");
//    scanf("%d", &id);
//    fflush(stdin);
//    Nodo *aux = tareasP;
//    //  Nodo *auxAnterior = *lista;
//    while (aux && aux->tarea.id != id)
//    {
//       aux = aux->siguiente;
//    }
//    if (aux)
//    {
//       printf("************* Lista de pendientes  \n ");
//       printf("Se enontro la tarea de id nro  %d\n", id);
//       printf("el descripcion del tarea es : ");
//       puts(aux->tarea.descripcion);
//       printf("la duracion de la tarea es : %d \n ", aux->tarea.duracion);
//    }
//    else
//    {
//       printf("no se encontro la tarea de id nro %d En la lista de pendientes \n", id);
//    }
//    if (!aux)
//    {
//        aux = tareasR;
//     while (aux && aux->tarea.id != id)
//    {
//       aux = aux->siguiente;
//    }
//    if (aux)
//    {
//       printf("************* Lista de Realizadas \n ");
//       printf("Se enontro la tarea de id nro  %d\n", id);
//       printf("el descripcion del tarea es : ");
//       puts(aux->tarea.descripcion);
//       printf("la duracion de la tarea es : %d \n ", aux->tarea.duracion);
//    }
//    else
//    {
//       printf("no se encontro la tarea de id nro %d En la lista de Realizados \n", id);
//    }
//    }
// }

Nodo *extraerTareaPorId(Nodo **lista, int id)
{
    Nodo *aux = *lista;
    Nodo *auxAnterior = *lista;
    while (aux && aux->tarea.id != id)
    {
        auxAnterior = aux;
        aux = aux->siguiente;
    }
    if (aux == *lista)
    {
        *lista = aux->siguiente;
    }
    else
    {
        auxAnterior->siguiente = aux->siguiente;
    }

    return aux;
}
void moverTarea(Nodo **listaPend, Nodo **listaRealizado)
{
    int opcion = 0;
    Nodo *aux = *listaPend;
    Nodo *auxDos = NULL;
    while (aux)
    {
        printf("Tarea nro : %d \n ", aux->tarea.id);
        printf("el descripcion del tarea es : ");
        puts(aux->tarea.descripcion);
        printf("la duracion de la tarea es : %d \n ", aux->tarea.duracion);
        printf("realizo este tarea? \n ingrese 1 para si 0 para no");
        scanf("%d", &opcion);
        fflush(stdin);
        if (opcion == 1)
        {
            auxDos = aux;
            aux = aux->siguiente;
            auxDos = extraerTareaPorId(listaPend, auxDos->tarea.id);
            agregarNodo(listaRealizado, auxDos);
        }
        else
        {
            aux = aux->siguiente;
        }
    }
}