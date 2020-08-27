#include <stdio.h>
#include <stdlib.h>
#define N 50
// faltan 2 ejercicios de cadenas de caracteres

int contarmayusculas(char cadena[])
{
    int i, contador=0;
    for(i=0 ; cadena[i]!='\0'; i++)
    {
        if(cadena[i]>= 'A' && cadena[i]<= 'Z')
            contador++;
    }
    return contador;
}


//	Realice la función int sustchar(char cadena[ ], char charbus, char charsust), que sustituya en la cadena “cadena” el carácter “charbus” por el carácter “charsust” y retorne las cantidad de sustituciones realizadas.

int sustituirchar(char cadena1[], char charbus, char sustituto)
{
    int i, contador=0;
    for(i=0 ; cadena1[i]!='\0'; i++)
    {
        if(cadena1[i]== charbus)
        {
            cadena1[i] = sustituto;
            contador++;
        }

    }
    return contador;

}


int contarpalabras(char cadena2[])
{
     int i, contador=0;
    for(i=0 ; cadena2[i]; i++)
    {
        if(cadena2[i]!= ' ' && (cadena2[i+1]== ' ' || cadena2[i+1]== '\0'))
            contador++;
    }
    return contador;
}






int main()
{
    char cadena[N];
    char cadena1[N], primero, susti;

    printf("digite la palabra a evaluar: ");
    gets(cadena);
    printf("digite el primer digito que usara: ");
    primero=getche();
    printf("\n");
    printf("digite el segundo digito con el que sustituira: ");
    susti=getche();
    printf("\nLa cantidad de letras mayusculas es de: %d",contarmayusculas(cadena));
    printf("\nLa cantidad de caracteres sustituido es de: %d\n",sustituirchar(cadena, primero, susti));
    printf("\nLa cantidad de palabras es de: %d\n",contarpalabras(cadena));
    puts (cadena);

}
