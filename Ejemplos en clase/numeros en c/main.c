//%d este el formato de entrada y salida de un entero

#include <stdio.h>
#include <stdlib.h>

#define MAXELEM 10

void captar(int numeros[])
{

int ind;
    printf("digite %d n%cmeros\n", MAXELEM, 163);

    for(ind=0; ind <MAXELEM; ind++)
    {

        scanf("%d", &numeros[ind]);
    }

}

void mostrar(int numeros[])

    {
        int ind;
    printf("valores en el arreglo\n");

    for(ind=0; ind< MAXELEM; ind++)
        {

        printf("%d\n", numeros[ind]  );

    }

    }
int main()
{
    int num[MAXELEM], in;

    captar(num);
    mostrar(num);

    return 0;
}
