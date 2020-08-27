#include <stdio.h>
#include <stdlib.h>
#define N 50


void primeraletramayuscula(char cadena[])//ojo
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
    char cadena[N];
    gets(cadena);
    primeraletramayuscula(cadena);
    puts(cadena);
}
