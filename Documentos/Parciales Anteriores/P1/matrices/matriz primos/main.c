#include <stdio.h>
#include <stdlib.h>
#define N 2
// resolver problema con la funcion de los numeros primos lo demas esta bien
int primos(int mat)
{
    int i, cont=0;
   for(i=1; i < mat; i++)
   {
      if(mat%i != 0)
        cont=1;
   }
    return cont;


}

int contarprimos(int matrix[][N])
{
    int i, j, contador=0;
    for(i=0; i< N; i++)
    {
        for(j=0; j< N; j++)
        {


                contador+= primos(matrix[i][j]);
        }
    }
    return contador;

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

    printf("La cantidad de numeros primos que hay es de: %d\n", contarprimos(matriz));



}
