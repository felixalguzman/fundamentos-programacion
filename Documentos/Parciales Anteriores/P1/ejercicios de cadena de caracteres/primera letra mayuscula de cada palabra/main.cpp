#include <iostream>
#define N 50

using namespace std;

void primeraletramayuscula(char cadena[])
{
    int i;
    for(i=0; cadena[i]!='\0'; i++)
    {
        if(cadena[i]!= ' ' && cadena[i+1]!=' ' || cadena[i+1]!='\0')
        {
            cadena[i]-=32;
        }
    }
}

int main()
{
    char cadena[N];
    gets(cadena);
    primeraletramayuscula(cadena);
    puts(cadena);
}
