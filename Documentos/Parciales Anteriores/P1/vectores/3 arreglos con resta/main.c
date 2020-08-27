#include <stdio.h>
#include <stdlib.h>
#define N 5
int main()
{
    int arreglo[N];
    int arreglo1[N];
    int arreglo2[N];
    int i;
    printf("Digite los datos del primer arreglo: \n");
    for(i=0; i< N; i++)
    {
        scanf("%d", &arreglo[i]);
    }
    printf("Digite los datos del segundo arreglo: \n");

    for(i=0; i< N; i++)
    {
        scanf("%d", &arreglo1[i]);
    }

    for(i=0; i < N; i++)
    {
        arreglo2[i]= arreglo[i]+arreglo1[i];
    }

    for(i=0; i < N; i++)
    {
        printf("%d", arreglo2[i]);
    }
}
