
#include <stdio.h>
#include <stdlib.h>
#define N 50
int upper(){

}

int main()
{
    char cadena[N];
    char pez[40];
    int ind;
    scanf("%s", &cadena);
    for(ind= 0; cadena[ind]!='\0'; ind++)
    {
        if(cadena[ind]>='a'&& cadena[ind]<='z')// este if es para saber si un caracter es minuscula y para convertir de mayuscula seria todo lo contrario
        cadena[ind]-=32;                  // al final se le resta -32 para transformar en minuscula, esto es debido a la tabla ascii

    }
    puts(cadena);

}

/*int ind;
    strcpy(cadena, "arrocero");
    printf("%s", cadena);
    puts(cadena);
    return 0;
    */
