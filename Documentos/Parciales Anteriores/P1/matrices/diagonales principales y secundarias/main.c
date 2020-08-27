#include <stdio.h>
#include <stdlib.h>
#define N 3

int main()
{
    int matriz[N][N], i, j;
    for(i=0; i< N; i++)
    {
        for(j=0; j< N; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

        printf("\n");

    for(i=0; i< N; i++)
    {
        for(j=0; j< N; j++)
        {
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }

       printf("Numeros que estan debajos de la diagonal\n");
    for(i=0; i< N; i++)
    {
        for(j=0; j< N; j++)
        {
            if(i< j)// Para trabajar con los numeros que estan por debajo de la diagonal principal o por encima solo hace falta asegurar que las columnas sean menores que la filas
            printf("%d", matriz[i][j]);// para imprimir los numeros que estan debajo de la diagonal principal las columnas tienen que ser mayores en todo momento
        }
        printf("\n");
    }

}
