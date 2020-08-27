#include <stdio.h>
#include <stdlib.h>

int main()
{
    char cadena[50];
    int ind;
    printf("Digite la palabra que desea evaluar: ");
    gets(cadena);
    for(ind=0; cadena[ind]!='\0'; ind++)
    {
        if(cadena[ind] >= 'a' && cadena[ind] <= 'z')
        {

            cadena[ind]-=32;
        }
        else
        {

            if(cadena[ind] >= 'A' && cadena[ind] <= 'Z')
            {

            cadena[ind]+=32;

            }
        }


    }
    printf("%s\n", cadena);
    return 0;
}
