#include <stdio.h>
#include <stdlib.h>
#define N 3




int main
{

    int matriz[N][N];
    int i, j;

    for(i=0; i< N; i++)
    {
        for(j=0; j< N; j++)
        {
            scanf("%d", &matriz[i][j]);
            fflush(stdin);
        }
    }

printf("\n");
for(i=0; i< N; i++)
    {
        for(j=0; j< N; j++)
        {
            printf("%d",matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nSegunda comlumna\n");

    for(i=1; i< 2; i++)
    {
        for(j=0; j< N; j++)
        {
            printf("%d",matriz[i][j]);
        }
        printf("\n");
    }


printf("\nDiagonal principal");
    for(i=0; i< N; i++)
    {
        for(j=0; j< N; j++)
        {
            if(i==j)
            {
                printf("%d",matriz[i][j]);
            }
            else
            {
                if(i<j)
                {
                    printf("%d",matriz[i][j]);
                }
                else
                {
                    printf("%c",' ');
                }

                if(i>j)
                {
                    printf("%d",matriz[i][j]);
                }
                else
                {
                    printf("%c",' ');
                }

            }



        }
        printf("\n");
    }
/*
    printf("\nDiagonal secundaria");
    for(i=0; i< N; i++)
    {
        for(j=0; j< N; j++)
        {
            if(i ==0)
            {
                j+=2;
                printf("%d",matriz[i][j]);



            }
            if(j==i)
                {

                    printf("%d",matriz[i][j]);
                }



        }
        printf("\n");
    }*/


}
