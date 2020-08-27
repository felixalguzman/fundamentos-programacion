#include <stdio.h>
#include <stdlib.h>
#define N 30

int contarcaracter(char chain[], char caracter)
{
    int i, contador=0;
    for(i=0; chain[i]!= '\0'; i++)
    {
        if(chain[i]== caracter)
        {
            contador++;
        }
    }
    return contador;
}

char modachar(char cadena[]) //ojo
{
    int i, j, contador=0, repeticion=0;
    char moda, caracter, maxrepeticion[N],mayor, auxiliar;


    for(i=0 ; cadena[i]!='\0'; i++)
    {
         for(j=0 ; cadena[j]!='\0'; j++)
         {    moda= cadena[j];
              maxrepeticion[j] = contarcaracter(cadena[i], moda);
         }

    }


   /* for(j=0 ; maxrepeticion[j]!='\0'; j++)
         {
             mayor = maxrepeticion[j]
             if(mayor < maxrepeticion[j+1])
             {
                 aux =mayor;
                 mayor = maxrepeticion[j+1];
                 maxrepeticion[j+1]= aux;
             }
         }
        return ;*/
}

int main()
{
    char matriz[N], caracter;
    printf("Digite la palabra que quiere analizar: ");
    gets(matriz);
    printf("Digite el caracter que desea buscar: ");
    caracter = getche();

 printf("\n%d", contarcaracter(matriz, caracter));
    return 0;
}
