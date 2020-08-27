#include <stdio.h>
#include <stdlib.h>
#define N 5

int overpromedio(int pro[])
{
    int i,j, cont=0, cont1=0, promedio=0;
    for(i=0; i<N ; i++)
    {
         promedio+=pro[i];
         cont++;
    }
    promedio= promedio/cont;
    for(j=0; j<N; j++)
    {
        if(pro[j] > promedio)
            cont1++;
    }
    return cont1;
}

int main()
{
    int promedio[N];
    int i;
    printf("Digite los datos del vector\n");
    for(i=0; i<N ; i++)
    {
        scanf("%d", &promedio[i]);
    }

    for(i=0; i<N ; i++)
    {
        printf("%d", promedio[i]);
    }
    printf("\n%d", overpromedio(promedio));
}
