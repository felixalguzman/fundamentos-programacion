#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define max 50

int puntajeacu =0;



int main()
{


   char cadena[max] ={0};
   char caract;
   char aste[max];
   puts("Digite una frase ");
    char cad2[max];

    asterico(cadena);
    puts("\n");

   // printf(cadena);

    printf("La cantidad de intentos disponibles es de: %d \n\n", oportunidades(cadena) );

   //strcpy(aste, astasteri(cadena));
   //asteri(cadena);


    asteri(cadena,cad2);
    varios(cadena, caract, cad2 );

    printf("La frase introducida es : %s :", cadena);
}

void asterico(char cad[])
{

    int ind, n=0, ind2;
    ind = 0;

    while(cad[ind] != 13)
    {
        cad[ind] = getch();

        /*do
        {


            if( cad[ind] <= 'a' || cad[ind] >= 'z')
            {
                printf(" Solo trabajamos con letras digite de nuevo\n");
                cad[ind] = getch();

            }

        }while(cad[ind] <= 'a' || cad[ind] >= 'z');*/



        if(cad[ind] > 32 || cad[ind] == ' ' && cad[ind] >= 'a' && cad[ind] <= 'z' )
        {


               putchar('*');
                ind++;


            if(cad[ind] == '\r')
            {
                cad[ind]='\0';
            }
        }
        else if ( cad[ind] == 8 && ind > 0)
        {

            putchar(8);
            putchar(' ');
            putchar(8);
            ind--;

        }


    }
        for( ind2 =0; cad[ind2] ; ind2++)
        {
             if( cad[ind2] == 13)
             {
                 cad[ind2] = 0;
             }
        }


    return;

}


int oportunidades(char cad[])
{
    //espacio(cad);
    int ind, cont, sum;
    sum=0;
    char iguala[max]={};
    iguala[max]=espacio(cad);

    for( ind =0; cad[ind] != '\0'; ind++)
    {

        sum ++;
        //printf("%d \n",sum);

    }
    cont= 0.80 * sum;

    return cont;
}

void espacio(char cad[])
{
    int ind, ind2;

    for( ind =0; cad[ind]; ind++)
    {

      if( cad[ind] == ' ' )
        {
            for( ind2=ind; cad[ind2]; ind2++)
            {
                cad[ind2] = cad[ind2 + 1];
                ind--;
            }
        }

    }

    return;
}

int puntos(char car)
{

    char letras[max]= {'A', 'E', 'I', 'O', 'C', 'S', 'U', 'D', 'L', 'P', 'R', 'B', 'T', 'F', 'M', 'N', 'G', 'H', 'J', 'Q', 'V', 'K', 'W', 'X', 'Y', 'Z'};
    int valor[max]= {10, 10, 10, 10, 10, 10, 15, 15, 15, 15, 15, 20, 20, 20, 20, 20, 25, 25, 25, 25, 25, 30, 30, 30, 30, 30 };
    int ind,cont=0;



   for(ind=0;letras[ind]!='\0';ind++)
    {

        if (tolower(car)==tolower(letras[ind]))
        {

            cont+=valor[ind];


        }

    }

return cont;


}

int puntosacu(char car)
{

    puntajeacu+= puntos(car);


return puntajeacu;


}




void asteri(char cad[], char cad2[])
{

    int ind, n;
    espacio(cad);

  n = strlen(cad);




    for(ind =0; ind<=n; ind++)
    {
        cad2[ind]='*';
    }
    cad2[n-1] = 0;

   //puts(cad2);

    //strcpy(iguala2, cad2);



   return;
}

void varios (char cad[], char car, char ast[])
{

    int n, ind, ind2,ind3, co, cont=0,racha=0;
    n = strlen(cad);
    co=oportunidades(cad);

    do
    {


        printf("\nDigite una letra para adivinar: ");
        scanf(" %c%*[^\n]%*c", &car);
        /* 1) " " leer y descartar el espacio blanco al inicio de la linea.
            2) "%c" leer un carácter y almacenarlo en la variable "ch".
            3) "%*[^\n]" leer y descartar todo carácter distinto de '\n'.
            4) "%*c" leer y descartar un carácter (el '\n').*/

        for( ind =0; ind<n; ind++ )
        {

            if( cad[ind] == car)
            {
                for( ind2=ind; ind2< n; ind2++ )
                {
                    if( cad[ind2] == car)
                    {
                        ast[ind2] = car;
                    }

                }
                printf("Encontraste una letra, Felicidades... :)\n\n");
                racha++;
                puts(ast);
                printf("Intentos Disponibles -> %d <- \n",co);
                printf("Puntos Ganados actualmente: %d \n", puntos(car));
                printf("Puntos Acumulados: %d \n", puntosacu(car));
                printf("La racha es de %d intento/s \n",racha);



                //printf("La racha es de %s intento/s \n");
                //printf("Puntos de la racha %d \n",rach );
                ind = n;
                co++;




            }

            if( ind == n-1)
            {
                printf("Esta letra no fue encontrada\n");
                printf("La racha se Reinicia\n");

                racha=0;
                //printf("La racha es de %s intento/s \n");

                //racha=0;
               // printf("Puntos de la racha %d \n", rach);
            }



        }

         if(strcmp(cad,ast)==0)
        {
           printf("Son iguales\n");
           return;
        }

    co--;
    }while( co > 0);

return;

}
