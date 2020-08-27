#include <stdio.h>
#include <stdlib.h>
#define N 5

int asimetrico(int vector[])
{

}

int main()// esto esta correcto pero me da error con el vector lo resolvere luego pero la logica esta correcta
{
    int simetrico[N], i=0, cont=0;

    for(i=0; i< N; i++)
    {
        printf("Digite los datos del vector: ");
        scanf("%d", &simetrico[i]);
    }

    for(i=0; i< N; i++)
    {
        if(simetrico[i] == simetrico[4])
            cont++;
             printf("\n%d vs %d ", simetrico[i], simetrico[N]);

    }
    if(cont>2)
        printf("El vector es simetrico ");
        else
            printf("No lo es ");


            //printf("%d ", simetrico);

}
