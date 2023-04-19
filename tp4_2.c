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
        tareas[i]->Descripcion = malloc(sizeof(char) * strlen(aux));
        strcpy( tareas[i]->Descripcion, aux);
        


        
    }

//tareas realizadas y pendientes
    Tarea **tareasR = (struct Tarea **)malloc(sizeof(struct Tarea *) * can); // reserva de memoeria a un puntero que va a apuntar a una estrcutura
      for (int i = 0; i < can; i++)

    {

        tareasR[i] = NULL;
        
   
        
    }
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


    /*5. Mostrar por pantalla todas las tareas realizadas y luego listar las tareas
pendientes.*/

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
    


    // tareas[i].Duracion = 3;
    return 0;
}
