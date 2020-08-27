#include <stdio.h>
#include <stdlib.h>

#define MAXSTR 50
#define LENMAT  9
#define MAXEST  1

typedef struct
{
    char mat[LENMAT];
    char nombre[MAXSTR];
    int edad;

}EST;


EST capest(void)
{
    EST est1;
    printf("Matr%ccula:  ",161);
    fflush(stdin);
    scanf("%s",&est1.mat);
    printf("Nombre:  ");
    fflush(stdin);
    gets(est1.nombre);
    printf("Edad:  ");
    scanf("%d",&est1.edad);

    return est1;
}

EST analizar(EST est3)
{
    if(est3.nombre>='a' && est3.nombre<='z' || est3.nombre==' ' || est3.nombre=='-')
    {
        return 1;
    }

    else
        return 0;



void impest(EST est2)
{
    printf("\n\nDatos del estudiante\n");
    printf("Matr%ccula: %s\n",161,est2.mat);
    printf("Nombre:  %s\n",est2.nombre);
    printf("Edad: %d\n",est2.edad);

    return;
}



int main()
{
    EST estudiantes[MAXEST];
    int ind;

    printf("Digite los datos de los estudiantes\n");
    for ( ind = 0; ind < MAXEST; ind ++ )
    {
        printf("Estudiante %d\n",ind+1);

        estudiantes[ind] = capest();
        analizar(estudiantes[ind]);
    do
    {
        printf("Digite Un nombre valido\n");
    }while(analizar(estudiantes[ind]>=1))

    }



    printf("Datos de estudiantes.\n");
    for ( ind = 0; ind < MAXEST; ind ++ )
    {
        printf("Estudiante %d\n",ind+1);
        impest(estudiantes[ind]);
    }


    return 0;
}

