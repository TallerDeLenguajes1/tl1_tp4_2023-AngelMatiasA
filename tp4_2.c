#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Tarea
{
    int TareaID; // Numerado en ciclo iterativo
    char *Descripcion;
    int Duracion; // entre 10 – 100
    // Tarea *tarea
} typedef Tarea;

// void Cargar

void cargarTareas( Tarea ** tareas, int can);
void moverRealizadas(Tarea ** tareas, int can, Tarea ** tareasR);
void ListarTareas(Tarea ** tareas, int can, Tarea ** tareasR);

void BuscarTareas(Tarea ** tareas, int can, Tarea ** tareasR, char* palabra);

void BuscarTareasPorId(Tarea ** tareas, int can, Tarea ** tareasR);


int main()
{

    int can;
    printf("ingrese cantidad de tareas: \n");
    scanf("%d", &can);
    fflush(stdin);
    Tarea **tareas = (struct Tarea **)malloc(sizeof(struct Tarea *) * can); // reserva de memoeria a un puntero que va a apuntar a una estrcutura

    for (int i = 0; i < can; i++)

    {

        tareas[i] = NULL;
        // tareas[i]->tarea = malloc(sizeof(Tarea)* 2);
        // for (int j = 0; j < 2; j++)
        // {
        //     tareas[i]->tarea[j].
        // }
        
    }
    //reserva del puntero doble
    //reserva de la estructura
    //reserva de la descripcion

    cargarTareas(tareas, can);


//tareas realizadas y pendientes
    Tarea **tareasR = (struct Tarea **)malloc(sizeof(struct Tarea *) * can); // reserva de memoeria a un puntero que va a apuntar a una estrcutura
      for (int i = 0; i < can; i++)

    {
        tareasR[i] = NULL;
  
    }
    moverRealizadas(tareas, can, tareasR);
 


    /*5. Mostrar por pantalla todas las tareas realizadas y luego listar las tareas
pendientes.*/
ListarTareas(tareas, can, tareasR);
BuscarTareasPorId(tareas, can, tareasR);

printf("ingrese la palabra clave a buscar en la tarea \n"); 
char * aux = malloc(sizeof(char)*20); 
gets(aux); 
fflush(stdin); 
BuscarTareas(tareas, can, tareasR, aux);

for (int i = 0; i < can; i++)
{
    free(tareas[i]->Descripcion);
    free(tareas[i]->Duracion);
    free(tareas[i]->TareaID);
    free(tareasR[i]->Descripcion);    
    free(tareasR[i]->Duracion);   
    free(tareasR[i]->TareaID);

}
free(tareas); 
free(tareasR);
    


    // tareas[i].Duracion = 3;
    return 0;
}

void cargarTareas( Tarea ** tareas, int can){ 

     srand(time(NULL));
    char aux[500];
    for (int i = 0; i < can; i++)

    {
        tareas[i] =malloc(sizeof(Tarea));
        tareas[i]->TareaID=i+1;
        
        
        tareas[i]->Duracion = 10+ rand()% (100-10);  

        printf("ingrese una descripcion de la tarea \n"); 
        gets(aux); 
        fflush(stdin); 
        tareas[i]->Descripcion = malloc(sizeof(char) * strlen(aux) +1 );
        strcpy( tareas[i]->Descripcion, aux);
        


        
    }

}

void moverRealizadas(Tarea ** tareas, int can, Tarea ** tareasR){
     char respuesta[10];
    int j = 0;
     for (int i = 0; i < can; i++)

    {
        printf(" Realizo la tarea numero %d ?\n",  tareas[i]->TareaID);
        // printf(" duracion de la tarea %d\n",  tareas[i]->Duracion);
        printf("Cuya descripcion es: \n");  
        puts(tareas[i]->Descripcion);

        printf("ingrese si para confirmar, no para denegar \n"); 
        gets(respuesta); 
        fflush(stdin); 
        if (strcmp(respuesta, "si") == 0)
        {   
            tareasR[j] = tareas[i];
         
            tareas[i] = NULL; 
            j++;
        }
        
    }

}

void ListarTareas(Tarea ** tareas, int can, Tarea ** tareasR){
    printf("********************* \n");
printf("tareas pendiente \n");
      for (int i = 0; i < can; i++)

    {
        if (tareas[i] != NULL)
        {   
            
             printf(" la tarea numero %d \n",  tareas[i]->TareaID);
        printf(" duracion de la tarea %d\n",  tareas[i]->Duracion);
             printf("Cuya descripcion es: \n");  
        puts(tareas[i]->Descripcion);
        }
        
      
 
    }

printf("************* \n");
      printf("tareas realizadas \n");
    for (int i = 0; i < can; i++)
    {

       
       
        if (tareasR[i] != NULL)
        {   
           
             printf(" la tarea numero %d \n",  tareasR[i]->TareaID);
        printf(" duracion de la tarea %d\n",  tareasR[i]->Duracion);
             printf("Cuya descripcion es: \n");  
        puts(tareasR[i]->Descripcion);
        }
        
    }


} 

/*7. Vuelva al branch main e implemente también una nueva versión de la función
BuscarTarea en donde la misma sea por palabra clave en vez de por Id. (uno
le manda una palabra y te tiene que devolver la primera tarea que contenga
dicha palabra).
Nota: Para realizar este punto, investigue el uso de la función strstr*/ 

void BuscarTareas(Tarea ** tareas, int can, Tarea ** tareasR, char* palabra){
    int encontrado = 0; 
    int i = 0;
    while (encontrado == 0 && i<can )
    {
         for ( i = 0; i < can; i++)
    {
       if (tareas[i] != NULL && strstr(tareas[i]->Descripcion, palabra))
       {
         printf("Tarea Encontrada es:  \n");
         printf(" la tarea de id %d \n",  tareas[i]->TareaID);
        printf(" Su duracion de la tarea %d\n",  tareas[i]->Duracion);
             printf("Cuya descripcion es: \n");  
        puts(tareas[i]->Descripcion); 
        encontrado = 1;
       }
       else
       {
        if (tareasR[i] != NULL && strstr(tareasR[i]->Descripcion, palabra)){

            printf("Tarea Encontrada es:  \n");
         printf(" la tarea de id %d \n",  tareasR[i]->TareaID);
        printf(" Su duracion de la tarea %d\n",  tareasR[i]->Duracion);
             printf("Cuya descripcion es: \n");  
        puts(tareasR[i]->Descripcion); 
        encontrado = 1;

        }
        
       }
       
    }
        
    }
    if (encontrado == 0)
    {
       printf("no se encontro la tarea \n");
    }
    
    
   

}

/* Cree un nuevo branch llamado busca-tarea e implemente una función de
búsqueda de tarea por nro. de id de nombre BuscarTarea. La misma devuelve
la tarea solicitada.*/
void BuscarTareasPorId(Tarea ** tareas, int can, Tarea ** tareasR){
    int id ;
    printf("ingrese el id de la tarea a buscar \n"); 
    scanf("%d", &id);
    fflush(stdin);
    for (int i = 0; i < can; i++)
    {
        if (tareas[i] != NULL && tareas[i]->TareaID == id )
        {
            printf("La tarea con el id nro %d es: \n", id);
            puts(tareas[i]->Descripcion);
        }
        if (tareasR[i] != NULL && tareasR[i]->TareaID == id)
        {
            printf("La tarea con el id nro %d es: \n", id);
            puts(tareasR[i]->Descripcion);
        }
        
        
    }

    

}