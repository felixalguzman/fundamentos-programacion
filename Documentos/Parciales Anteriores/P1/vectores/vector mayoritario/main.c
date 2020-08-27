#include <stdio.h>
#include <stdlib.h>
#define N 8

//Un vector es mayoritario si existe un elemento almacenado en el vector, que se repite más de n/2 veces.  Realice la función int esmayoritario(int vector[ ], int n), que retorne 1 si “vector” es mayoritario y 0 si no lo es.
int contarcaracter(int chain[], int numero)
{
    int i, contador=0;
    for(i=0; i< N; i++)
    {
        if(chain[i]== numero)
        {
            contador++;
        }
    }
    return contador;
}

int esmayoritario(int cadena[], int n)
{
    int comprobador = 0;
    comprobador = n/2;

    int i, j, verificador=0, numero=0;
    for(i= 0; i< n; i++)
    {
            numero = cadena[i];
            verificador+= contarcaracter(cadena, numero);

            if(verificador > comprobador)
            {
                return 1;
            }

            else
            {
                verificador = 0;
            }

    }

    return 0;
}

int main()
{
    int vector[N], i;
    printf("Introduzca los datos del vector\n");

    for(i=0; i< N; i++)
    {
        scanf("%d", &vector[i]);
    }

    printf("\n%d",  esmayoritario(vector, N));

}
