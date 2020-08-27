#include <stdio.h>
#include <stdlib.h>
#define N 3

int balanceada(int mat[][N], int n)
{
    int sumadetraza=0, sumadenum=0, promedio, cont=0, i, j;
    for(i=0; i< N; i++)
    {
        sumadetraza+= mat[i][i];// suma la traza
        for(j=0; j< N; j++)
        {
            if(i!=j)// suma los numeros que estan fuera de la diagonal
            {
                cont++;
                sumadenum+=mat[i][j];
            }
        }

    }
    promedio= sumadenum/cont;
    if(sumadetraza > promedio)
    return 1;

    else
        return 0;
}
int main()
{
     int matriz[N][N];
    int i,j;
    printf("Inserte los datos de la matriz\n");

    for(i=0; i< N; i++)
    {
        for(j=0; j< N; j++)
        {
            scanf("%d", &matriz[i][j]);
        }

    }
    printf("Datos de la matriz\n");
    for(i=0; i< N; i++)
    {
        for(j=0; j< N; j++)
        {
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }

    printf("%d", balanceada(matriz, N));

}
