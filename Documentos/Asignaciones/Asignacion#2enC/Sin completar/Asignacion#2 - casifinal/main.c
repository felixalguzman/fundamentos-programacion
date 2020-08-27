#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define max 50

int puntajeacu =0;


int main()
{

    int p=0;
    int op;
    int num1,num2;
    char cadena[max] ={0};
    char caract;
    char aste[max];
    char cadorig[max];

/*
        printf("1.- Presione 1 para jugar\n");
        printf("2.- Presione 2 para ver las instrucciones de juego\n");
        printf("3.- presione 3 prra salir\n");

        printf("Indica la opcion: ");
        scanf("%d", &op);

            /*if(op!=4){printf("Introduce el primer numero: ");
            scanf("%d", &num1);
            printf("Introduce el segundo numero: ");
            scanf("%d", &num2);}
    while(op!=3);
    {*/
      //  switch(op){

          //  case '1':

           // system("cls");

            puts("Digite una frase ");
            char cad2[max];
            asterico(cadena);
            puts("\n");
            // printf(cadena);
            strcpy(cadorig, cadena);
            espacio(cadena);
            printf("La cantidad de intentos disponibles es de: %d \n\n", oportunidades(cadena) );

            //strcpy(aste, astasteri(cadena));
            //asteri(cadena);
            asteri(cadorig, cad2);


            varios(cadorig, caract, cad2 );

           // printf("Presione cualquier tecla para volver al menu. \n");
           // system("pause>nul");
           // system("cls");

            //printf("La frase introducida es : %s :", cadena);

/*
            ;break;


            case '2':
                    system("cls");
                    printf("\t\tINSTRUCCIONES");
                    printf("\n\n\n");
                    printf("1) El juego consta de que el jugador numero 1 tiene que\n");
                    printf("   digitar una frase sin que el jugador numero 2 sepa la frase.\n\n");
                    printf("2) El jugador numero 2 debera ir adivinando letra por letra, \n");
                    printf("   este cuenta con un numero de oportunidades definida por la\n");
                    printf("   cantidad de letras de la frase previamente introducida.\n\n");
                    printf("3) Usted Ganara la partida cuando adivine todas las letras de la frase.\n\n");
                    printf("4) Usted perdera cuando se le acaben las oportunidades disponibles.\n\n");
                    printf("5) Diviertase con sus amigos.\n\n\n");
                    printf("\tValor de Letras \n\n");
                    printf(" A E I O C S    ---     10pts.  \n");
                    printf(" U D L P R      ---     15pts.  \n");
                    printf(" B T F M N      ---     20pts.  \n");
                    printf(" G H J Q V      ---     25pts.  \n");
                    printf(" K W X Y Z      ---     30pts.  \n\n\n");



                printf("Presione cualquier tecla para volver al menu. \n");
                system("pause>nul");
                system("cls");

            break;
            case '3': break;



            }*/

    }





void asterico(char cad[])
{

    int ind, n=0;
    ind = 0;

    while(cad[ind] != 13)
    {
        cad[ind] = getch();

        if(cad[ind] > 32 || cad[ind] == ' ' )
        {


               putchar('*');
                ind++;



        }
        else if ( cad[ind] == 8 && ind > 0)
        {

            putchar(8);
            putchar(' ');
            putchar(8);
            ind--;

        }


    }


    return;

}


int oportunidades(char cad[])
{
    espacio(cad);
    int ind, cont, sum;
    sum=0;


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

        if (tolower(car) == tolower(letras[ind]))
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
    //espacio(cad);

    n = strlen(cad);




    for(ind =0; ind<n; ind++)
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

    int n, ind, ind2,ind3,ind4, co, cont=0,racha=0;
    n = strlen(cad);
    co=oportunidades(cad);




    do
    {


         for( ind4 =0; cad[ind4]; ind4++)
        {
             if( cad[ind4] == 13)
             {
                 cad[ind4] = '\0';
             }
        }

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
                    if( cad[ind2] == car )
                    {
                        ast[ind2] = car;
                    }

                    if(cad[ind2] == 32)
                    {
                        ast[ind2] = 32;
                    }


                }
                printf("Adivinaste una letra!\n\n");
                racha++;
                puts(ast);
                printf("Intentos Disponibles -> %d <- \n",co);
                printf("Puntos Ganados actualmente: %d \n", puntos(car));
                printf("Puntos Acumulados: %d \n", puntosacu(car));
                printf("La racha es de %d intento/s \n",racha);





                ind = n;
               // co++;



            }

            if( ind == n-1)
            {

                co--;

                printf("Intentos Disponibles -> %d <- \n",co);
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
                printf("Son iguales\n\n\n");
                return;
            }
    }while( co > 0);

return;

}
