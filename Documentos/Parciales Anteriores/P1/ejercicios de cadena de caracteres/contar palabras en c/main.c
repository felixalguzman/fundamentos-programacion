#include <stdio.h>
#include <stdlib.h>
#define MAXSTR 50

int cantpal(char s[])
{
    int ind, pal = 0;

    for (ind = 0; s[ind]; ind ++)
        if ( s[ind]!= ' ' && (s[ind+1] == ' ' || s[ind+1] == '\0') )// esta sirve para contar palabras pues si el primer caracter es letra y el segundo espacio se considerara una letra lo mismo sucede si llega al nulo
            pal++;

    return pal;

}


int main()
{
    char frase[MAXSTR];

    printf("Digite una frase: ");
    gets(frase);
    printf("%s tiene %d palabras\n",frase,cantpal(frase));

    return 0;
}


