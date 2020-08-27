#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <time.h>
#include <conio.c>
#include <ctype.h>

#define MAXID   5
#define INCEST  5
#define EMPINI 2
#define LENNOM 41
#define LENAPE 31
#define MAXEMP 10
#define ARRIBA 72
#define ABAJO 80
#define ENTER  13
#define CANTOPC 5
#define TAMAOPC 30
#define MAXCAR 99

#define NOMARCH "C:\\TEMP\\DATOSEMP.DAT"


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
    char StActivo; // ‘T’ activo y ‘F’inactivo
}EMP;

EMP capemp(int);
int valfecha(EMP );
int edadhoy(EMP );
int actual();
int actualmes();
int actualdia();
int movimiento(int);
void mostrar(int);
void colordefault(void);
void ponercolor(int, int);
void listanombre (int, EMP[]);
void menu1();
void menu2();
void impemp(EMP, int ,int);
void buscarnom( int, EMP[]);
void buscarape( int, EMP[]);
void buscareda( int, EMP[]);
void buscarestatus( int, EMP[]);

int main()
{
    EMP *empl;
    int ind=0, totemp, salir=0, modi=0, pos=0, opc=0;
    char input[2], input2[2], caract;
    long tamarchiv;
    FILE *ArchEmp;



    do
    {

        system("cls");
        menu1();
        fflush(stdin);
        input[0] = getchar();
        fflush(stdin);

        switch(input[0])
        {

            case '1':
            {


                ArchEmp = fopen(NOMARCH, "rt");

                if(ArchEmp == NULL)
                {
                    totemp = EMPINI;
                    empl = (EMP *) malloc(totemp * sizeof(EMP));
                }
                else
                {

                    fseek(ArchEmp, 0L, SEEK_END);
                    tamarchiv = ftell(ArchEmp);
                    totemp = tamarchiv / sizeof(EMP);

                    ind = totemp;
                    totemp += EMPINI;
                    empl = (EMP *) malloc(totemp * sizeof(EMP));
                    rewind(ArchEmp);

                    fread(empl, totemp, 1, ArchEmp );
                    fclose(ArchEmp);


                }
                printf("Ingrese los datos de el nuevo usuario\n\n");
                // printf("Cantidad de empleados a capturar : ");

                do
                {
                    if( ind == totemp)
                    {
                        totemp += INCEST;
                        printf("\nReasignando memoria...\n");
                        empl = (EMP *) realloc(empl, totemp * sizeof(EMP));
                    }

                    printf("\nEmpleado %02d: \n",ind+1);
                    empl[ind++] = capemp(ind);

                    printf("%cDesea capturar otro empleado? (Si) o (No) \n\n",168);

                    do
                    {
                        caract = (tolower(getch()));

                    }while(caract != 's' && caract != 'n');


                }while(caract == 's');

                totemp = ind;

                ArchEmp  = fopen(NOMARCH, "a");

                if( ArchEmp == NULL)
                {
                    printf("Error creando archivo de salida...\n");
                    exit(-1);
                }

                fwrite(empl, totemp * sizeof(EMP), 1, ArchEmp);
                fclose(ArchEmp);

                system("cls");
                break;
            }

            case '2':
            {

                do
                {

                    system("cls");
                    menu2();

                    fflush(stdin);
                    input2[0] = tolower(getchar());
                    fflush(stdin);

                    switch(input2[0])
                    {
                        case 'n':
                        {
                            salir = 0;
                            printf("Ingrese un nombre para buscar: ");

                            buscarnom( totemp, empl);

                            getch();
                            break;
                        }

                        case 'a':
                        {
                            salir = 0;
                            printf("Ingrese el apellido por el cual se buscara: ");

                            buscarape( totemp, empl);

                            getch();
                            break;
                        }

                        case 'e':
                        {
                            salir = 0;
                            printf("Ingrese la edad a buscar: \n");

                            buscareda( totemp, empl);
                            getch();
                            break;
                        }

                        case 'v':
                        {
                            salir = 1;
                            system("cls");
                            break;
                        }

                        case 't':
                        {
                            printf("Digite (s) o (n) para buscar empleados por estatus: \n");

                            buscarestatus(totemp, empl);
                            getch();

                            break;
                        }

                        case 's':
                        {
                            return 0;
                            break;
                        }

                        default:

                        puts("Opcion no valida\n");
                        getch();
                    }


                }while(input2[0] != 's' && salir != 1);


                break;

            }

            case '3':
            {
                do
                {


                    system("cls");
                    gotoxy(1,1);
                    puts("\t\t\t Bienvenido al menu de listar.\n\n");
                    puts("\t Seleccione con ENTER y las flachas de direccion ARRIBA y ABAJO.\n\n");
                    salir = 0;
                    opc = movimiento(CANTOPC);


                    system("cls");

                    switch(opc)
                    {

                        case 0:
                        {
                            colordefault();
                            puts("Digite el patron por el que desea buscar: ");

                            listanombre(totemp, empl);
                            getch();
                            break;
                        }

                        case 1:
                        {
                            colordefault();
                            puts("Menu de salario\n");
                            getch();
                            break;
                        }

                        case 2:
                        {
                            colordefault();
                            puts("Menu de edades\n");
                            getch();
                            break;
                        }

                        case 3:
                        {
                            salir = 1;
                            break;
                        }

                        case 4:
                        {
                            return 0;
                            break;
                        }


                    }

                }while( opc != 5 && salir != 1);

                printf("Esta es la lista de los usuarios registrados\n");

                ArchEmp  = fopen(NOMARCH, "rb");
                //totemp = ind;

                if( ArchEmp == NULL)
                {
                    printf("Error creando archivo de salida...\n");
                    exit(-1);
                }
                else
                {
                    fseek(ArchEmp, 0L, SEEK_END);
                    tamarchiv = ftell(ArchEmp);
                    totemp = tamarchiv / sizeof(EMP);

                    //ind = totemp;
                    //totemp += EMPINI;
                    empl = (EMP *) malloc(totemp * sizeof(EMP));
                    rewind(ArchEmp);

                    fread(empl, totemp, 1, ArchEmp );
                    fclose(ArchEmp);

                    //Imprimir empleados
                    printf("Empleados capturados...\n\n");
                    for(ind = 0; ind < totemp; ind++ )
                    {
                        printf("\t \tEmpleado %02d \n ",ind+1);
                        impemp(empl[ind],1, ind+1);
                    }
                }

                fclose(ArchEmp);



                break;
            }

            case '4':
            {

                system("cls");
                printf("\n Empleados capturados...\n\n");

                for(ind = 0; ind < totemp; ind++ )
                {
                    printf("\t \tEmpleado %02d \n ",ind+1);
                    impemp(empl[ind],1, ind+1);
                }

                do
                {
                    printf("Digite el id del empleado que desea modificar: ");
                    fflush(stdin);
                    scanf("%d", &modi);
                    printf("\n%d", modi);
                    fflush(stdin);


                }while( modi <= ind);

                printf("\nEmpleado %02d: \n",modi);

                for(ind = 0 ; ind < totemp; ind++)
                {

                    if( ind == modi)
                    {
                        pos = ind;
                        empl[pos] = capemp(modi);
                    }

                }

                getch();
                break;
            }

            case '5':
            {
                return 0;
                break;
            }

            default:

            puts("\nOpcion no valida.  \n");
            getch();

        }

    }while(input[0] != '5');


    free(empl);
    return 0;
}

/*
Funcion: menu1
Argumentos: Nada.
Objetivo: Imprimir las opciones del menu1.
Retorno: Ningun valor.
*/

void menu1()
{
    puts("\t\t Bienvenido al programa\n\n");
    puts("Digite 1: para ingresar un nuevo empleado.");
    puts("Digite 2: para buscar un empleando.");
    puts("Digite 3: para listar los empleados presentes.");
    puts("Digite 4: para modificar un empleado.");
    puts("Digite 5: para salir.");
}

/*
Funcion: menu2
Argumentos: Nada.
Objetivo: Imprimir las opciones del menu2.
Retorno: Ningun valor.
*/

void menu2()
{
    printf("\t\t Bienvenido al menu de busqueda \n\n");
    puts("Digite n: para buscar por nombre.");
    puts("Digite a: para buscar por apellido.");
    puts("Digite e: para buscar por edad.");
    puts("Digite t: para buscar por estatus. ");
    puts("Digite v: para volver al menu anterior. ");
    puts("Digite s: para salir. ");

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

    int ind, f=0, maxed=0, fen=0, fna=0, ap=0, nom=0;


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
        fflush(stdin);

        //Comprobar de que el nombre no este en blanco.
        if(emp.nombre1[0] == '\0' || emp.nombre1[0] == 0 || strcmp(emp.nombre1, "") == 0 ||  strlen(emp.nombre1) == 0)
        {
            nom=1;
        }

        for( ind =0; ind<strlen(emp.nombre1); ind++)
        {
            //Transformar a mayusculas
            if (emp.nombre1[ind] >= 'a' && emp.nombre1[ind] <= 'z'  )
            {
                emp.nombre1[ind] -= 32;
            }

            if( emp.nombre1[ind] != 'ñ' || emp.nombre1[ind] != 'Ñ')
            {
                //Revisar si es guion o espacio
                if (emp.nombre1[ind] != 45 && emp.nombre1[ind] != 32 )
                {

                    if( emp.nombre1[ind] < 65 || emp.nombre1[ind] > 90 )
                    {
                        f=1;
                        ind=strlen(emp.nombre1);
                    }

                }
            }



        }

        if(f == 1)
        {
            printf("Solo se permiten espacios, letras o guiones.\n");
        }

        if(nom == 1)
        {
            printf("El nombre no puede estar en blanco.\n");
        }



    }while(f ==1 || nom == 1 );



    do
    {
        f=0;
        printf("Segundo nombre: ");
        fflush(stdin);
        memset( emp.nombre2, 0, sizeof(emp.nombre2) );

        gets(emp.nombre2);
        fflush(stdin);


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
        fflush(stdin);

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
        fflush(stdin);

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
    fflush(stdin);



    do
    {
        printf("Fecha de nacimiento(dd/mm/yyyy): ");
        fflush(stdin);
        scanf("%d/%d/%d",&emp.fnacim.dia,&emp.fnacim.mes,&emp.fnacim.agno);
        fflush(stdin);

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
        fflush(stdin);

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


    do
    {
        printf("Digite si el empleado esta activo(S)i o (N)o: ");
        fflush(stdin);
        emp.StActivo = (toupper(getch()));
        fflush(stdin);

        if((emp.StActivo != 'S' && emp.StActivo != 'N') )
        {
            printf("\nError! Digite de nuevo.\n ");
        }

    }while( emp.StActivo != 'S' && emp.StActivo != 'N');

    printf("\n");

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

void impemp(EMP emp, int titulo, int c)
{
    int n1=0,n2=0, ap1=0, ap2=0, eda=0, esp=0;

    n1=strlen(emp.nombre1);
    n2=strlen(emp.nombre2);
    ap1=strlen(emp.apellido1);
    ap2=strlen(emp.apellido2);
    eda = edadhoy(emp);
    esp = 5;

    if ( titulo )
    {
        printf("%-*s %-*s  %-*s  %s %s %s \n\n" , n1+n2, "Id Emp", ap1+ap2+n2+1, "Nombre", 2,"Sueldo", "Fecha Ingreso", "Edad", "Activo(S)i o (N)o" );
        printf("%04d %-*s %-*s %-*s %-*s %.2f %02d/%02d/%04d %d %-* %c\n ",
        c,n1+n2,emp.nombre1,n2,emp.nombre2,ap1,emp.apellido1,ap2,emp.apellido2,emp.salario,
        emp.fentrada.dia,emp.fentrada.mes,emp.fentrada.agno, eda, esp, emp.StActivo);

        printf("\n\n\n");
    }


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
Argumentos: int totemp: total empleados.
            EMP empl[]: Estructura de empleados
Objetivo: Buscar por nombre.
Retorno: Ningun valor.
*/

void buscarnom( int totemp, EMP empl[])
{
    char buscarnombre[LENNOM];
    int ind;

    fflush(stdin);
    gets(buscarnombre);
    fflush(stdin);

    for(ind =0; ind < totemp; ind++)
    {

        if( (strcmp(toupper(buscarnombre), empl[ind].nombre1) == 0 ) || strcmp(toupper(buscarnombre), empl[ind].nombre2) == 0 )
        {
            impemp(empl[ind], 1, ind+1);
        }

    }


}

/*
Funcion: buscarape
Argumentos: int totemp: total empleados.
            EMP empl: Estructura de empleados
Objetivo: Buscar por apellido.
Retorno: Ningun valor.
*/
void buscarape(int totemp, EMP empl[])
{
    int ind;
    char buscarapellido[LENAPE];

    fflush(stdin);
    gets(buscarapellido);
    fflush(stdin);

    for( ind =0; ind < totemp; ind++)
    {
        if((strcmp( toupper(buscarapellido), empl[ind].apellido1) == 0) || (strcmp(toupper(buscarapellido), empl[ind].apellido2) == 0))
        {

            impemp(empl[ind], 1, ind+1);

        }

    }


}

/*
Funcion: buscareda
Argumentos: int totemp: total empleados.
            EMP empl: Estructura de empleados
Objetivo: Buscar por edad.
Retorno: Ningun valor.
*/

void buscareda( int totemp, EMP empl[])
{
    int ind = 0, digitedad = 0;



    fflush(stdin);
    scanf("%d", &digitedad);
    fflush(stdin);

    for( ind =0; ind < totemp; ind++)
    {

        if(digitedad == edadhoy(empl[ind]))
        {
            impemp(empl[ind], 1, ind+1);
        }


    }


}

/*
Funcion: buscarestatus
Argumentos: int totemp: total empleados.
            EMP empl: Estructura de empleados
Objetivo: Buscar por estatus.
Retorno: Ningun valor.
*/

void buscarestatus( int totemp, EMP empl[])
{
    int ind;
    char estatu;

    fflush(stdin);
    estatu = getchar();
    fflush(stdin);


    for( ind = 0; ind < totemp; ind++)
    {
        if(toupper(estatu)== empl[ind].StActivo)
        {
            impemp(empl[ind], 1, ind+1);
        }
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
    int dia=0 ,mes=0 ,anio=0 , edad=0;

    time_t fecha_sistema;
    time(&fecha_sistema);
    tiempo = localtime(&fecha_sistema);

    anio = tiempo->tm_year + 1900;
    mes = tiempo->tm_mon + 1;
    dia = tiempo->tm_mday;

    edad = anio - empl.fnacim.agno;

    if(mes > empl.fnacim.mes)
    {
       edad++;
    }

    if (mes == empl.fnacim.mes)
    {
        if(dia > empl.fnacim.dia)
        {
            edad++;
        }
    }

    return edad;
}

/*
Funcion: movimiento
Argumentos: int n: total de empleados
Objetivo: Moverse.
Retorno: Nada.
*/

int movimiento( int n)
{
    int ind, sel=0;
    _setcursortype(0);
    char tecla;
    //system("cls");
    do
    {
        gotoxy(1, 5);
        mostrar(sel);

        tecla = getch();

        if( tecla == ABAJO)
        {
            if(sel == n - 1)
            {
                sel = 0;
            }
            else
            {
                sel++;
            }
        }

        if( tecla == ARRIBA)
        {
            if( sel == 0)
            {
                sel = n -1;
            }
            else
            {
                sel--;
            }
        }


    }while( tecla != ENTER);

    _setcursortype(1);
    colordefault();
    return sel;

}

/*
Funcion: mostrar
Argumentos: int sel: seleccion para el color
Objetivo: Seleccionar la opcion de un color e imprimirla.
Retorno: Nada.
*/

void mostrar(int sel)
{

    int ind;
    char menu3[CANTOPC][TAMAOPC] = {"Nombres con un patron.",
                                    "Salario en un rango   ",
                                    "Edad en un rango.     ",
                                    "Menu anterior.        ",
                                    "Salir.                "};

    for( ind =0; ind < CANTOPC; ind++)
    {
        if( sel == ind)
        {
            ponercolor(YELLOW, BLUE);
        }
        else
        {
            ponercolor(BLUE, LIGHTGRAY);
        }
        printf( "%s \n", menu3[ind]);
    }


}

/*
Funcion: ponercolor
Argumentos: int tc: color del texto
            int tbc: color del background
Objetivo: poner color al texto y background
Retorno: Nada.
*/

void ponercolor(int tc, int tbc)
{
    textbackground(tbc);
    textcolor(tc);
}

/*
Funcion: colordefault
Argumentos: Nada
Objetivo: poner color al texto y background
Retorno: Nada.
*/

void colordefault()
{
    ponercolor(LIGHTGRAY, BLACK);

}

/*
Funcion: listanombre
Argumentos: int totemp: Total de empleados
            EMP empl[]: estructura con los datos de los empleados
Objetivo: imprimir los nombres por un patron
Retorno: Nada.
*/

void listanombre (int totemp, EMP empl[])
{
    int ind, ind2;
    char patron[5];

    fflush(stdin);
    gets(patron);
    fflush(stdin);

    for( ind = 0; ind < totemp; ind++)
    {
        for(ind2 = 0; ind2 < strlen(patron); ind2++)
        {
            if( strcmp(toupper(patron), empl[ind].nombre1[ind2]) ==0 || strcmp(toupper(patron), empl[ind].nombre2[ind2]) ==0 || strcmp(toupper(patron), empl[ind].apellido1[ind2]) ==0 || strcmp(toupper(patron), empl[ind].apellido2[ind2]) ==0)
            {
                impemp(empl[ind],1, ind+1);
            }
        }
    }

}

