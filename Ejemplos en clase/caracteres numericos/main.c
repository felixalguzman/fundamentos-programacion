#include <stdio.h>
#include <stdlib.h>
#define N 50

int caract(char t []){

int ind, cont=0;

for (ind=0; t[ind]!='\0'; ind++)
    {


    if(t[ind]>=0 || t[ind] <= 9)
    cont++;
if (t[ind] >='a' && t[ind] <= 'z')
    cont--;
    }
if(cont >0)
return 1;
else
    return 0;

}



int main()
{
    char frase[N];
    printf("Digite una frase: ");
    gets(frase);
    printf("%d", caract(frase));
    return 0;
}
