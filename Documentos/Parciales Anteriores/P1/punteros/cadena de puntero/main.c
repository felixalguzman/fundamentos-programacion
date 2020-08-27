#include <stdio.h>
#include <stdlib.h>
#define N 25

elimrepeticion(char cadena)
{


     for (ind = 0; cad[ind]; ind++ )
    {

        if ( cad[ind] == caract )
        {
            for ( ind2 = ind; cad[ind2]; ind2 ++ )
                cad[ind2] = cad[ind2 + 1];

            ind --;
        }
    }
}

int main()
{

    char cad[N] ,caract;
    gets(cad);
    puts(cad);
    caract= getchar();

   int ind, ind2;


}
