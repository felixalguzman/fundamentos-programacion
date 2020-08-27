#include <stdio.h>
#include <stdlib.h>
#define N 50




//Realice una función int cuadruple(char s[])  que recibe como parámetro una cadena de caracteres s y debe devolver cuantas palabras de cuatros letras tiene la cadena.

int cuadruple(char cade[]) // esta funcion tiene algunos errores pero la logica esta correcta
{
    int i, contador=0;

    for(i=0; cade[i]!='\0'; i++)
    {
        if(cade[i]!= ' ' && cade[i+1]!= ' ' && cade[i+2]!= ' ' && cade[i+3]!= ' ' && cade[i+4]== ' ')
        {
            contador++;
        }
    }

    return contador;
}

int main()
{
    char cadena[N];
    printf("Inserte las palabras  de la cadena : ");
    gets(cadena);
    printf("\n%d",cuadruple(cadena));
    return 0;
}
