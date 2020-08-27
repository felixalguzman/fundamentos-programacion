#include <stdio.h>
#include <stdlib.h>

int main()
{
    int caracter, ind, cont=0;
    char cadena[50];
    printf("Ingrese la frase que desea analizar: ");
    gets(cadena);
    printf("Ingrese el caracter que desea comprobar: ");
    caracter= getchar();
    for(ind=0; cadena[ind]!='\0'; ind++)
    {
            if(caracter >='A' && caracter <='Z')
                caracter+=32;


            if(cadena[ind] >='A' && cadena[ind] <='Z')
            {
                cadena[ind]+=32;

            }
            if(cadena[ind]== caracter)
            {
                    cont++;

            }

    }
    printf("%d\n", cont);

    return 0;
}
