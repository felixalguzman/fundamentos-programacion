#include <stdio.h>
#include <stdlib.h>
#include <conio.c>
#include <string.h>
#include <time.h>
#include <windows.h>

#define MAXC 16
#define MAXF 16
#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77
#define ESC    27
#define ENTER  13


int main(){

	SetConsoleTitle("[JUEGO] Felix y Regis");
	srand(time(NULL));
	int d=0, mat[MAXF][MAXC], inicio;

	printf("\nInserte el numero de filas y columnas de la matriz (3-15): ");

	do
	{
		fflush(stdin);
		scanf("%d",&d);

		if (d < 3 || d > 15)
		{
			colortexto(LIGHTRED);
			printf("ERROR, digite denuevo: ");
			colordefault();
		}

	}while(d < 3 || d > 15);

	inicio = d-1;
	generarmatriz(mat,d);
	movimiento(mat, inicio, inicio, d);

	return 0;
}


/*
Funcion: mayormat
Argumentos: int matriz[][]: Matriz de numeros.
			int tammat: El tamaño de la matriz.
Objetivo: Buscar el mayor numero dentro de la matriz.
Retorno:El valor mas alto dentro de la matriz.
*/

int mayormat(int matriz[][MAXC], int tammat)
{
	int indf, indc, mayor = matriz[0][0];

	for(indf = 0; indf < tammat; indf++)
	{
		for(indc = 0; indc < tammat; indc++)
		{
			if(mayor < matriz[indf][indc])
			{
				mayor = matriz[indf][indc];
			}
		}
	}
	return mayor;
}

/*
Funcion: mayormatfila
Argumentos: int matriz[][]: Matriz de numeros.
			int tammat: El tamaño de la matriz.
Objetivo: Buscar el mayor numero dentro de la matriz.
Retorno: La posicion de la fila en el valor mas alto.

*/

int mayormatfila(int matriz[][MAXC], int tammat)
{
	int indf, indc, mayor=matriz[0][0], posi;

	for(indf=0; indf<tammat; indf++)
	{
		for(indc=0; indc<tammat; indc++)
		{
			if(mayor < matriz[indf][indc])
			{
				mayor = matriz[indf][indc];
				posi=indf;

			}
		}
	}
	return posi;
}

/*
Funcion: mayormatcol
Argumentos: int matriz[][]: Matriz de numeros.
			int tammat: El tamaño de la matriz.
Objetivo: Buscar el mayor numero dentro de la matriz.
Retorno: La posicion de la columna del valor mas alto.

*/

int mayormatcol(int matriz[][MAXC], int tammat)
{
	int indf, indc, mayor = matriz[0][0], posj;

	for(indf = 0; indf < tammat; indf++)
	{
		for(indc = 0; indc < tammat; indc++)
		{
			if(mayor < matriz[indf][indc])
			{
				mayor = matriz[indf][indc];
				posj = indc;
			}
		}
	}
	return posj;
}

/*
Funcion: menormatriz
Argumentos: int matriz[][]: Matriz de numeros.
			int tammat: El tamaño de la matriz.
Objetivo: Buscar el menor numero dentro de la matriz.
Retorno: El numero menor dentro de la matriz.

*/

int menormatriz(int matriz[][MAXC], int tammat)
{
	int indf, indc, menor = matriz[0][0], posi, posc;

	for( indf = 0; indf < tammat; indf++)
	{
		for(indc = 0; indc < tammat; indc++)
		{
			if( menor > matriz[indf][indc])
			{
				menor = matriz[indf][indc];
			}
		}
	}

	return menor;
}

/*
Funcion: matordenada
Argumentos: int matriz[][]: Matriz de numeros.
			int tammat: El tamaño de la matriz.
Objetivo: Revisar si la matriz esta ordenada.
Retorno: 0 o 1.

*/

int matordenada(int matriz[][MAXC], int tammat)
{
	int indf, indc , coincide = 0, matriordenada[MAXF][MAXC];

	for(indf = 0; indf < tammat; indf++)
	{
		for(indc = 0; indc < tammat; indc++)
		{
			matriordenada[indf][indc] = tammat * indf + indc + 1;

			if(matriz[indf][indc] != matriordenada[indf][indc])
			{
				coincide = 1;
			}
		}
	}

	return coincide;
}

/*
Funcion: colorbackground
Argumentos: int tc: Color del background.
Objetivo: Cambiar el color del background.
Retorno: Nada.

*/

void colorbackground(int tc)
{
    textbackground(tc);

}

/*
Funcion: colortexto
Argumentos: int tx: Color del texto.
Objetivo: Cambiar el color del texto.
Retorno: Nada.

*/

void colortexto(int tx)
{
	textcolor(tx);

}

/*
Funcion: colordefault
Argumentos: Nada.
Objetivo: Cambiar el color del texto y background al original.
Retorno: Nada.

*/
void colordefault()
{
    colorbackground(BLACK);
    textcolor(LIGHTGRAY);
}


/*
Funcion: impmat
Argumentos: int matriz[][]: Matriz de numeros.
			int tammat: El tamaño de la matriz.
Objetivo: Imprimir la matriz.
Retorno: Nada.

*/


void impmat(int matriz[][MAXC],int tammat)
{

	int indf,indc, mayor = mayormat(matriz, tammat), menor = menormatriz(matriz, tammat), cont=0;

	for(indf = 0;indf < tammat; indf++)
	{
		for(indc = 0; indc < tammat; indc++)
		{

			if( tammat <= 9)
			{
				if(mayor == matriz[indf][indc])
				{
					colorbackground(WHITE);
					printf("   ");
				}
				else
				{
					colorbackground(BLUE);
					printf("%02d ",matriz[indf][indc]);
				}
			}
			else if( tammat > 9 && tammat <= 15)
			{
				if(mayor == matriz[indf][indc])
				{
					colorbackground(WHITE);
					printf("    ");
				}
				else
				{
					colorbackground(BLUE);
					printf("%03d ",matriz[indf][indc]);
				}
			}

		}
		printf("\n");
	}
	return;
}

/*
Funcion: movimiento
Argumentos: int matriz[][]: Matriz de numeros.
			int tammat: El tamaño de la matriz.
			int posf: Posicion de las filas.
			int posc: Posicion de las columnas.
Objetivo: Moverse a traves de la matriz.
Retorno: Nada.

*/

void movimiento(int matriz[][MAXC],int posf,int posc, int tammat)
{
	_setcursortype(0);
	clrscr();
	system("cls");
	int mov = 0, cont = 0;
	char tecla;
	posf = mayormatfila(matriz, tammat);
	posc = mayormatcol(matriz, tammat);

	do
	{

		gotoxy(1,2);
		impmat(matriz,tammat);
		colordefault();
		printf("\nMovimientos hechos: %d \n", mov);

		if(matordenada(matriz,tammat) == 1)
		{
			colordefault();
			puts("Presione ESC para salir.\n");
			//clrscr();
		}
		else
		{
			colorbackground(WHITE);
			colortexto(LIGHTBLUE);
			puts("\nHas ganado !!\n");
			//colordefault();
		}

		tecla=getch();

		if(tecla == ARRIBA)
		{
			if(posf > 0)
			{
				int temp = matriz[posf-1][posc];
				matriz[posf-1][posc] = matriz[posf][posc];
				matriz[posf][posc] = temp;
				posf--;
				mov++;
			}
		}

		if(tecla == ABAJO)
		{
			if(posf < tammat-1)
			{
				int temp = matriz[posf+1][posc];
				matriz[posf+1][posc] = matriz[posf][posc];
				matriz[posf][posc] = temp;
				posf++;
				mov++;
			}
		}

		if(tecla == IZQUIERDA)
		{
			if(posc > 0)
			{
				int temp = matriz[posf][posc-1];
				matriz[posf][posc-1] = matriz[posf][posc];
				matriz[posf][posc] = temp;
				posc--;
				mov++;
			}
		}

		if(tecla == DERECHA)
		{
			if(posc < tammat-1)
			{
				int temp = matriz[posf][posc+1];
				matriz[posf][posc+1] = matriz[posf][posc];
				matriz[posf][posc] = temp;
				posc++;
				mov++;
			}
		}

		if( tecla == ESC)
		{
			colordefault();
			printf("\n\nPresione ENTER para salir, o J para jugar de nuevo, presione otra tecla para continuar.\n");
			tecla = getch();

			if(tecla == ENTER)
			{
				cont++;
			}

			if(tecla == 106 || tecla == 74)
			{
				system("cls");
				cont++;
				main();
			}
			else
			{
				system("cls");
				clrscr();
				colordefault();
			}

		}

	}while(cont != 1);

	return;
}


/*
Funcion: repetido
Argumentos: int matriz[][]: Matriz de numeros.
			int tammat: El tamaño de la matriz.
			int num: Numero random.
Objetivo: Revisar si el numero random esta en la matriz.
Retorno: 0 o 1.

*/

int repetido(int M[][MAXC],int tammat,int num)
{
	int indf, indc;

	for(indf = 0; indf < tammat; indf++)
	{
		for( indc = 0; indc < tammat; indc++)
		{
			if( M[indf][indc] == num )
				return 1;
		}
	}
	return 0;
}

/*
Funcion: generarmatriz
Argumentos: int matriz[][]: Matriz de numeros.
			int tammat: El tamaño de la matriz.
Objetivo: Generar la matriz con numeros aleatorios sin repeticion.
Retorno: Nada.

*/

void generarmatriz(int M[][MAXC],int tammat)
{
	int temp, indf;

	for( indf = 0; indf < tammat; indf++ )
	{
		int indc = 0;

		while(indc < tammat)
		{
			temp = rand() % (tammat*tammat) +1 ;

			if( (repetido(M,tammat,temp)) == 0 )
			{
				M[indf][indc++] = temp;
			}
		}
	}

	return;

}

