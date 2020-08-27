#include <stdio.h>
#include <stdlib.h>
// prueba de arreglo dinamico o arreglo con punteros

int main()
{
    int *arreglos, i;

    arreglos= (int *)calloc(5, sizeof(int)); // esta es la forma correcta de asignar memoria dinamica a un arreglo de punteros lo cual es necesario para que el arreglo funcione
    for(i=0; i< 5; i++)
    {
        scanf("%d", (arreglos+i)); // para introducir datos no se debe poner el asterisco fuera del parentesis
    }

    printf("Datos del arreglo");
    for(i=0; i< 5; i++)
    {
        printf("%d", *(arreglos+i));// pero para mostrar los datos si se debe poner un asterisco fuera
    }


}
