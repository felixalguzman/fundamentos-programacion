#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>


int main()
{
    // Declaracion de variables
     int numero,cantidad,contador, limite, inicio, numero1;
     int hora = time(NULL);

     // Semilla de rand();
     srand(hora);

        printf("Ingrese la cantidad de numerosaleatorios que desea generar: ");
        scanf("%d",&cantidad);
        printf("Ingrese en que numero quiere que empiece: ");
        scanf("%d",&inicio);
         printf("Ingrese hasta que numero quiere que sus numeros aleatorios lleguen: ");
        scanf("%d",&limite);



        for(contador = 0; contador<cantidad; contador++)
        {

               numero = (rand()%limite +20); // Para controlar  si quieres que los numeros que se muestren sea del 1 al 20 debes de poner modulo de 20 o modulo del numero maximo
               numero1= numero = rand()% (limite-inicio) + inicio; // de esta forma se generan numeros aleatorios entre intervalos
               printf("%d ", numero1);

        }
       getch();
}
