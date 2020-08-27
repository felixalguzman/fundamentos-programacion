#include <stdio.h>
#include <stdlib.h>

int main()
{
    char vector[50];
    int ind=0, cont=0, cont1=0;
    scanf("%s", vector);
    for (ind=0 ; vector[ind]!='\0'; ind++)
        {
        if(vector[ind] >= 'a' && vector[ind] <= 'z')
        cont ++;
        if(vector[ind] >= '1' && vector[ind] <= '9')
        cont1 ++;

    }
    printf(" Hay tantos caracteres en la palabra: %d\n", cont);
    printf(" Hay tantos numeros en la palabra: %d\n", cont1);

}
