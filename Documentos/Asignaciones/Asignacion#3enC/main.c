#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <time.h>

#define MAXID   5
#define LENNOM 41
#define LENAPE 31
#define MAXEMP 10



typedef struct
{
    int dia,mes,agno;
}FECHA;

typedef struct
{
    char idemp[MAXID];
    char nombre1[LENNOM];
    char nombre2[LENNOM];
    char apellido1[LENAPE];
    char apellido2[LENAPE];
    FECHA fnacim;
    FECHA fentrada;
    float salario;
}EMP;

EMP capemp(int);
void impemp(EMP ,int , int );
int valfecha(EMP );
EMP Buscar( char[] );
int actual();
int actualmes();
int actualdia();
void menu1();
void menu2();

int main()
{
    EMP *empl;
    int ind,totemp, no, salir=0;
    char input[2];
    char input2[2];
    char busq[LENNOM];


    puts("\t\t Bienvenido al programa\n\n");

    do
    {

        menu1();
        fflush(stdin);
        input[0] = getchar();
        fflush(stdin);

        switch(input[0])
        {

            case '1':
            {
                printf("Ingrese los datos de el nuevo usuario\n\n");


                do
                {
                    printf("Cantidad de empleados a capturar : ");
                    scanf("%d",&totemp);

                    if (totemp <= 0 )
                    printf("Cantidad de empleados debe ser mayor que cero.\n" );

                }while( totemp <= 0);

                empl = (EMP *) malloc(totemp * sizeof(EMP));

                //Leer empleados
                for(ind = 0; ind < totemp; ind++ )
                {
                    printf("\nEmpleado %02d: \n",ind+1);
                    empl[ind] = capemp(ind+1);

                }
                no = 1;

                system("cls");
                break;
            }
            case '2':
            {
                system("cls");
                printf("\t\t Bienvenido al menu de busqueda \n\n");

                do
                {


                    menu2();
                    fflush(stdin);
                    input2[0] = getchar();
                    fflush(stdin);

                    switch(input2[0])
                    {
                        case '5':
                        {
                            //printf("Busqueda por nombre\n");
                            printf("Digite un nombre para buscar: ");
                            fflush(stdin);
                            gets(busq);

                            buscarnom(busq, totemp, empl[totemp]);

                            break;
                        }

                        case '6':
                        {
                            char ape;
                            printf("Ingrese el apellido por el cual se buscara: ");
                            fflush(stdin);
                            scanf("%c", &ape);
                            buscarape(ape, totemp, empl[totemp]);
                            break;
                        }

                        case '7':
                        {
                           int i = 0, ed;

                            printf("Inserte la edad a buscar: \n");
                            scanf("%d", &ed);
                            for(i = 0; i < totemp; i++)
                            {
                                if (edadhoy(empl[i]) == ed)
                                {
                                    impemp(empl[i], 1, i + 1);
                                }
                            }
                            break;
                        }

                        case '8':
                        {
                            salir = 1;
                            break;
                        }

                        case '9':
                        {
                            return 0;
                            break;
                        }

                        default:
                            puts("Opcion incorrecta\n");
                    }


                }while(input2[0] != '9' && salir != 1);

                break;

            }
            case '3':
            {
                if(no == 1)
                {
                    system("cls");
                    printf("Esta es la lista de los usuarios registrados\n");

                    //Imprimir empleados
                    printf("Empleados capturados...\n\n");
                    for(ind = 0; ind < totemp; ind++ )
                    {
                        printf("\t \tEmpleado %02d \n ",ind+1);
                        impemp(empl[ind],1, ind+1);
                    }

                }
                else
                {
                    //system("cls");
                    printf("\nDebe digitar usuarios \n");
                }


                break;
            }

            case '4':
            {
                return 0;
                break;
            }

            default:


                puts("\nOpcion no valida.\n");


        }

    }while(input[0] != '4');


    free(empl);
    return 0;
}

/*
Funcion: menu
Argumentos: Nada.
Objetivo: Imprimir las opciones del menu.
Retorno: Ningun valor.
*/

void menu1()
{
    puts("Digite 1: para ingresar un nuevo empleado.");
    puts("Digite 2: para buscar un empleando.");
    puts("Digite 3: para listar los empleados presentes.");
    puts("Digite 4: para salir.");
}

void menu2()
{

    puts("Digite 5: para buscar por nombre.");
    puts("Digite 6: para buscar por apellido.");
    puts("Digite 7: para buscar por edad.");
    puts("Digite 8: para volver al menu anterior. ");
    puts("Digite 9: para salir. ");

}

/*
Funcion: capemp
Argumentos: int c: Genera el id.
Objetivo: Capturar los datos de los empleados.
Retorno: Ningun valor.
*/
EMP capemp(int c)
{
    EMP emp;

    int ind, f=0, maxed=0, fen, fna, ap=0, nom=0;

    printf("Id empleado: ");
    fflush(stdin);
    printf("%04d\n",c);

    do
    {
        f=0;
        nom = 0;
        printf("Primer nombre: ");
        fflush(stdin);
        memset( emp.nombre1, 0, sizeof(emp.nombre1) );

        gets(emp.nombre1);
        //Comprobar de que no este en blanco.
        if(emp.nombre1[0] == '\0' || emp.nombre1[0] == 0 || strcmp(emp.nombre1, "") == 0 ||  strlen(emp.nombre1) == 0)
        {
            nom=1;
        }

        for( ind =0; ind<strlen(emp.nombre1); ind++)
        {   //Transformar a mayusculas
            if (emp.nombre1[ind] >= 'a' && emp.nombre1[ind] <= 'z' )
            {
                emp.nombre1[ind] -= 32;
            }


            //Revisar si es guion o espacio
            if (emp.nombre1[ind] != 45 && emp.nombre1[ind] != 32 )
            {

                //Revisar si los caracteres estan en el abecedario en
                if( emp.nombre1[ind] < 65 || emp.nombre1[ind] > 90 )
                {
                    f=1;

                    ind=strlen(emp.nombre1);

                }

            }


        }


        if(f==1)
        {
            printf("Solo se permiten espacios, letras o guiones.\n");
        }

        if(nom == 1)
        {
            printf("El nombre no puede estar en blanco.\n");
        }



    }while(f ==1 || nom == 1);



    do
    {
        f=0;
        printf("Segundo nombre: ");
        fflush(stdin);
        memset( emp.nombre2, 0, sizeof(emp.nombre2) );

        gets(emp.nombre2);


        for( ind =0; ind<strlen(emp.nombre2); ind++)
        {
            if (emp.nombre2[ind] >= 'a' && emp.nombre2[ind] <= 'z' )
            {
                emp.nombre2[ind] -= 32;
            }


            if (emp.nombre2[ind] != 45 && emp.nombre2[ind] != 32 )
            {


                if(emp.nombre2[ind] < 65 || emp.nombre2[ind] > 90)
                {
                    f=1;
                    ind=strlen(emp.nombre2);


                }

            }

        }

        if(f==1)
        {
            printf("Solo se permiten espacios, letras o guiones.\n");
        }


    }while(f ==1);


    do
    {
        f=0;
        ap = 0;
        printf("Primer Apellido: ");
        fflush(stdin);
        memset( emp.apellido1, 0, sizeof(emp.apellido1) );
        gets(emp.apellido1);

        if(emp.apellido1[0] == '\0' || emp.apellido1[0] == 0 || strcmp(emp.apellido1, "") == 0 ||  strlen(emp.apellido1) == 0)
        {
            ap=1;
        }


        for( ind =0; ind<strlen(emp.apellido1); ind++)
        {
            if (emp.apellido1[ind] >= 'a' && emp.apellido1[ind] <= 'z' )
            {
                emp.apellido1[ind] -= 32;
            }


            if (emp.apellido1[ind] != 45 && emp.apellido1[ind] != 32 )
            {

                if( emp.apellido1[ind] < 65 || emp.apellido1[ind] > 90 )
                {
                    f=1;
                    ind=strlen(emp.apellido1);

                }

            }

        }

        if(f==1)
        {
            printf("Solo se permiten espacios, letras o guiones.\n");
        }

         if(ap == 1)
        {
            printf("El apellido no puede estar en blanco.\n");
        }




    }while( f ==1 || ap == 1);


    do
    {
        f=0;
        printf("Segundo Apellido: ");
        fflush(stdin);
        memset( emp.apellido2, 0, sizeof(emp.apellido2) );
        gets(emp.apellido2);

        for( ind =0; ind<strlen(emp.apellido2); ind++)
        {
            if (emp.apellido2[ind] >= 'a' && emp.apellido2[ind] <= 'z' )
            {
                emp.apellido2[ind] -= 32;
            }


            if (emp.apellido2[ind] != 45 && emp.apellido2[ind] != 32 )
            {


                if(emp.apellido2[ind] < 65 || emp.apellido2[ind] > 90)
                {
                    f=1;
                    ind=strlen(emp.apellido2);

                }

            }

        }

        if(f==1)
        {
            printf("Solo se permiten espacios, letras o guiones.\n");
        }

    }while(f == 1);


    printf("Sueldo: ");
    fflush(stdin);
    scanf("%f",&emp.salario);



    do
    {
        printf("Fecha de nacimiento(dd/mm/yyyy): ");
        fflush(stdin);
        scanf("%d/%d/%d",&emp.fnacim.dia,&emp.fnacim.mes,&emp.fnacim.agno);

        if(emp.fnacim.mes > 12 || emp.fnacim.mes <= 0 || emp.fnacim.agno <= 1850 || emp.fnacim.dia <= 0 || emp.fnacim.dia > 31 || emp.fnacim.agno > actual() )
        {
            if((emp.fnacim.dia <= 0 || emp.fnacim.dia > 31) && emp.fnacim.mes != 2)
            {
                printf("El dia debe ser entre el 1 y %d. \n", valfecha(emp));
            }
            if( emp.fnacim.agno < 1900)
            {
                printf("El a%co debe ser mayor a 1900.\n", 164);
            }

            if( emp.fnacim.agno > actual())
            {
                printf("La fecha de nacimiento esta incorrecta. \n");
            }

            if(emp.fnacim.mes == 2)
            {

                if(valfecha(emp) == 29)
                {
                    printf("El dia debe ser entre el 1 y el 29 porque el a%co es bisiesto. \n", 164);
                }
                else
                {
                    printf("El dia debe ser entre el 1 y el 28. \n");
                }

            }
            if( emp.fnacim.mes > 12)
            {
                printf("La cantidad de meses maximo es 12.\n");
            }

        }

    }while(emp.fnacim.mes > 12 || emp.fnacim.mes <= 0 || emp.fnacim.agno <= 1900 || emp.fnacim.dia <= 0 || emp.fnacim.dia > 31 || emp.fnacim.agno > actual());


    do
    {
        printf("Fecha de ingreso(dd/mm/yyyy): ");
        fflush(stdin);
        scanf("%d/%d/%d",&emp.fentrada.dia,&emp.fentrada.mes,&emp.fentrada.agno);

        fen = emp.fentrada.agno;
        fna = emp.fnacim.agno;
        maxed = fen - fna;


        if(emp.fentrada.mes > 12 || emp.fentrada.mes <= 0 || emp.fentrada.agno <= 1900 || emp.fentrada.dia <= 0  || maxed < 18 || emp.fentrada.dia > valfecha(emp) || (actual()-fna) > 116 || emp.fentrada.agno > actual())
        {
            if(emp.fentrada.dia <= 0 && emp.fentrada.mes != 2)
            {
                printf("El dia debe ser entre el 1 y %d. \n", valfecha(emp));
            }

            if(emp.fentrada.dia > valfecha(emp))
            {
                printf("El mes que ha entrado no llega a esa cantidad de dias. \n");
            }

            if( emp.fentrada.agno < 1900)
            {
                printf("El a%cdo debe ser mayor a 1900.\n", 164);
            }

            if((actual()-fna) > 116)
            {
                printf("Lo sentimos no se admiten fantasmas (No existe nadie con esta edad). \n");
            }

            if( maxed < 18 )
            {
                printf("La fecha de entrada debe ser mayor a la fecha de nacimiento en 18 a%cos. \n", 164);
                fen = 0;
                fna = 0;
                maxed = 0;
            }

            if( emp.fentrada.agno > actual())
            {
                printf("La fecha de entrada esta incorrecta. \n");
            }

            if(emp.fentrada.mes > 12)
            {
                printf("La cantidad de meses maximo es 12.\n");
            }

        }

    }while(emp.fentrada.mes > 12 || emp.fentrada.mes <= 0 || emp.fentrada.agno <= 1850 || emp.fentrada.dia <= 0 || emp.fentrada.dia > 31 || maxed < 18 || emp.fentrada.dia > valfecha(emp) || (actual()-fna) > 116 || emp.fentrada.agno > actual());

    return emp;

}


/*
Funcion: impemp
Argumentos: EMP emp: Estructura con los datos de los empleados.
int titulo: Imprimir el encabezado.
int c: Obtener el valor del id.
Objetivo: Imprimir los datos de los empleados.
Retorno: Ningun valor.
*/
void impemp(EMP emp,int titulo, int c)
{
    int n1=0,n2=0, ap1=0, ap2=0, eda;

    n1=strlen(emp.nombre1);
    n2=strlen(emp.nombre2);
    ap1=strlen(emp.apellido1);
    ap2=strlen(emp.apellido2);


    eda = edadhoy(emp);



    if ( titulo )

        printf("%-*s %-*s  %-*s  %s %s \n\n" , n1+n2, "Id Emp", ap1+ap2+n2+1, "Nombre", 2,"Sueldo", "Fecha Ingreso", "Edad" );
        printf("%04d %-*s %-*s %-*s %-*s %.2f %02d/%02d/%04d %d \n ",
        c,n1+n2,emp.nombre1,n2,emp.nombre2,ap1,emp.apellido1,ap2,emp.apellido2,emp.salario,
        emp.fentrada.dia,emp.fentrada.mes,emp.fentrada.agno, eda);

        printf("\n\n\n");

    return;
}



/*
Funcion: valfecha
Argumentos: EMP emp: Estructura con los datos de los empleados.
Objetivo: Saber la cantidad de dias del mes.
Retorno: Dias del mes.
*/
int valfecha(EMP emp)
{


    int numberOfDays, m, a, es=0;

    m = emp.fentrada.mes;
    a= emp.fentrada.agno;

    if (m == 4 ||m == 6 || m == 9 || m == 11)
        numberOfDays = 30;

    else if (m == 2)
    {
      es = (a % 4 == 0 && a % 100 != 0) || ( a % 400 == 0);

        if(es)
        {
            numberOfDays=29;
        }
        else
        {
            numberOfDays=28;
        }

    }
    else
      numberOfDays = 31;

    return numberOfDays;

}



/*
Funcion: actual
Argumentos: Nada.
Objetivo: Obtener el año actual.
Retorno: Año actual.
*/
int actual()
{

    time_t now = time(NULL);
    struct tm *t = localtime(&now);



    return t->tm_year+1900;

}

/*
Funcion: actualmes
Argumentos: Nada.
Objetivo: Obtener el mes actual.
Retorno: Mes actual.
*/
int actualmes()
{

    time_t now = time(NULL);
    struct tm *t = localtime(&now);


    return t->tm_mon+1;

}

/*
Funcion: actualdia
Argumentos: Nada.
Objetivo: Obtener el dia actual.
Retorno: Dia actual.
*/
int actualdia()
{

    time_t now = time(NULL);
    struct tm *t = localtime(&now);


    return t->tm_mday;

}

/*
Funcion: buscarnom
Argumentos: Char nomb: Nombre digitado.
int totemp: total empleados.
EMP empl: Estructura de empleados
Objetivo: Buscar por nombre.
Retorno: Ningun valor.
*/

void buscarnom(char nomb, int totemp, EMP empl)
{
    int i = 0;
    EMP emplo[totemp];
    //for(i = 0; i < totemp; i++){

    for(emplo[i]; empl.nombre1 == nomb; i++)
    {
        impemp(emplo[i], 1, i+1);
    }

}

/*
Funcion: buscarape
Argumentos: Char apell: Apellido digitado.
int totemp: total empleados.
EMP empl: Estructura de empleados
Objetivo: Buscar por apellido.
Retorno: Ningun valor.
*/
void buscarape(char apell, int totemp, EMP empl)
{
    int i = 0;
    EMP emplo[totemp];
    //for(i = 0; i < totemp; i++){

    for(emplo[i]; empl.apellido1 == apell; i++)
    {
        impemp(emplo[i], 1, i+1);

    }
}
/*
Funcion: edadhoy
Argumentos: EMP empl: Estructura de empleados
Objetivo: Edad del empleado.
Retorno: Edad del empleado.
*/
int edadhoy(EMP empl)
{
    struct tm *tiempo;
    int dia ,mes, anio, edad;

    time_t fecha_sistema;
    time(&fecha_sistema);
    tiempo=localtime(&fecha_sistema);

    anio=tiempo->tm_year + 1900;
    mes=tiempo->tm_mon + 1;
    dia=tiempo->tm_mday;

    edad = anio - empl.fnacim.agno;

    if(mes > empl.fnacim.mes)
    {
       edad++;
    }

    if (mes = empl.fnacim.mes)
    {
        if(dia > empl.fnacim.dia)
        {
            edad++;
        }
    }

    //system("pause");
    return edad;
}


