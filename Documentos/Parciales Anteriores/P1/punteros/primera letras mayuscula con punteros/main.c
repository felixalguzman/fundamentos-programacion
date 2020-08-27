#include <stdio.h>
#include <stdlib.h>
#define N 5
// ojo

void primeraletramayuscula(char cadena[])
{
    int i;
    for(i=0; cadena[i]!='\0'; i++)
    {
        if(cadena[i-1]== ' ' && cadena[i]!=' ')
        {
            cadena[i]-=32;
        }
    }
}

int main()
{
    char *cadena;
    int i;
    cadena = (char *) calloc(N, sizeof(char));
    for(i=0; (cadena+i)!='\0'; i++)
    {
        scanf("%s", (cadena+i));
    }
    primeraletramayuscula(cadena);

    for(i=0; *(cadena+i)!='\0'; i++)
    {
       printf("%s", *cadena);
    }


    free(cadena);
}
