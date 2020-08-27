#include <stdio.h>
#include <stdlib.h>

#define MAXSTR 50



int contarc(char s[], char c)
{
    int ind, contchar;

    for(ind = 0, contchar = 0; s[ind] != '\0'; ind ++)
        if ( tolower(s[ind]) == tolower(c) )// Este if transforma todas las letras a minuscula y compara con la variable elegida tambien trasnformada como minuscula
            contchar ++;

    return contchar;

}


void aminus(char s[])
{
    int ind;

    for (ind = 0; s[ind]; ind++ )
        if ( s[ind]>='A' && s[ind] <= 'Z') // esta transforma todo a minuscula
            s[ind] += 32;

    return;
}


int main()
{
    char frase[MAXSTR], caract;

    printf("Digite una frase: ");
    gets(frase);

   // aminus(frase);
    //printf("En min%cscula: \n%s\n",163,frase);

    printf("Digite caracter a contar: ");
    caract = getche();// este analiza el caracter y da un salto de linea de una vez

    printf("\nEl caracter %c se repite %d veces en la cadena '%s'\n",caract,contarc(frase,caract),frase);


    return 0;
}

