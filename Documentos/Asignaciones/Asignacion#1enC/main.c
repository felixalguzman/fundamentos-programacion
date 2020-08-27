#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define PARADA 10
#define PARADA2 20
#define PARADA3 30
#define PARADA4 40
#define ENTER 13

/*
Funcion: calcusemanasanta
Argumentos: int k: El año donde empieza el rango a evaluar.
int f: El año donde termina el rango a evaluar.
int l: La cantidad de columnas deseadas.
Objetivo: Dado un rango de años,  imprimir el año, la fecha de inicio y fin de la semana santa en una cantidad decolumnas especificadas.
Retorno: Ningun valor.


*/


void calcusemanasanta ( int k, int f, int l ){

	int a, b, c, d, e, n, cont2=0, abril1, abril2, tecla , cont=0, i;

	for( i=k; i<= f; i++ )
	{


		a = i % 19;
		b = i % 4;
		c = i % 7;
		d = ( 19 * a + 24 ) % 30;
		e = ( 2 * b + 4 *c + 6 * d + 5 ) % 7;
		n = ( 22 + d + e );

		if( l == 1 ) // Si la cantidad de columnas es 1.
		{
			if( n <= 31 ) // Si el resultado de la operacion es menor o igual que 31.
			{

				printf( "%i  %i/3  -  %i/4  ", i, n-7, n );

				cont2++;

				if( cont2 == l ) // Para controlar cuando se utilizara el salto de linea dependiendo de la cantidad de columnas elegidas.
				{
					printf( "\n" );
					cont2 = 0;

				}


				if ( ++ cont % PARADA == 0 ) // Para controlar que se pare cada 10 lineas y pida solo enter para continuar.
				{


					do{

						printf( "\n" );
						printf( "Presione ENTER para continuar. \n" );

						tecla = getch(  );
						system( "cls" );
						printf( "\n" );

					}


					while ( tecla != ENTER );

				}


			}

			else if ( n > 31 ) // Si el resultado de la operacion es mayor que 31.
			{

				abril2 = ( n - 31 ) - 7; // Para obtener el valor del mes adecuado se le resta 31, y 7 para obtener el dia cuando empieza la semana santa.
				abril1 = abril2 + 7; // Se le suma 7 para obtener el ultimo dia de la semana santa.


				if( abril2 < 0 ) // Si la fecha de semana santa esta entre marzo y abril.
				{
					abril2 = 31 + abril2;
					printf( "%i  %i/3  -  %i/4  ",i, abril2, abril1 );

					cont2++;
					if( cont2 == l ) // Para controlar cuando se utilizara el salto de linea dependiendo de la cantidad de columnas elegidas.
					{
						printf( "\n" );
						cont2 = 0;

					}

					if ( ++ cont % PARADA == 0 ) // Para controlar que se pare cada 10 lineas y pida solo enter para continuar.
					{


						do{

							printf( "\n" );
							printf( "Presione ENTER para continuar. \n" );

							tecla = getch(  );
							system( "cls" );
							printf( "\n" );

						}


						while ( tecla != ENTER );

					}


				}

				else if ( abril2 > 0 ) // Si la semana santa queda en abril.
				{
					printf( "%i  %i/4  -  %i/4  ",i, abril2, abril1 );


					cont2++;
					if( cont2 == l ) // Para controlar cuando se utilizara el salto de linea dependiendo de la cantidad de columnas elegidas.
					{
						printf( "\n" );
						cont2 = 0;

					}

					if ( ++ cont % PARADA == 0 ) // Para controlar que se pare cada 10 lineas y pida solo enter para continuar.
					{


						do{

							printf( "\n" );
							printf( "Presione ENTER para continuar. \n" );

							tecla = getch(  );
							system( "cls" );
							printf( "\n" );

						}


						while ( tecla != ENTER );

					}


				}



			}


		}

		else if( l == 2 )    // Si la cantidad de columnas es 2
		{
			if( n <= 31 ) // Si el resultado de la operacion es menor o igual que 31.
			{

				printf( "%i  %i/3  -  %i/4  ", i, n-7, n );

				cont2++;

				if( cont2 == l ) // Para controlar cuando se utilizara el salto de linea dependiendo de la cantidad de columnas elegidas.
				{
					printf( "\n" );
					cont2 = 0;

				}


				if ( ++ cont % PARADA2 == 0 ) // Para controlar que se pare cada 10 lineas y pida solo enter para continuar.
				{


					do{

						printf( "\n" );
						printf( "Presione ENTER para continuar. \n" );

						tecla = getch(  );
						system( "cls" );
						printf( "\n" );


					}


					while ( tecla != ENTER );

				}


			}

			else if ( n > 31 ) // Si el resultado de la operacion es mayor que 31.
			{

				abril2 = ( n - 31 ) - 7; // Para obtener el valor del mes adecuado se le resta 31, y 7 para obtener el dia cuando empieza la semana santa.
				abril1 = abril2 + 7;  // Se le suma 7 para obtener el ultimo dia de la semana santa.



				if( abril2 < 0 ) // Si la fecha de semana santa esta entre marzo y abril.
				{
					abril2 = 31 + abril2;
					printf( "%i  %i/3  -  %i/4  ",i, abril2, abril1 );

					cont2++;
					if( cont2 == l ) // Para controlar cuando se utilizara el salto de linea dependiendo de la cantidad de columnas elegidas.
					{
						printf( "\n" );
						cont2 = 0;

					}

					if ( ++ cont % PARADA2 == 0 ) // Para controlar que se pare cada 10 lineas y pida solo enter para continuar.
					{


						do{

							printf( "\n" );
							printf( "Presione ENTER para continuar. \n" );

							tecla = getch(  );
							system( "cls" );
							printf( "\n" );

						}


						while ( tecla != ENTER );

					}


				}



				else if ( abril2 > 0 ) // Si la semana santa queda en abril.
				{
					printf( "%i  %i/4  -  %i/4  ",i, abril2, abril1 );


					cont2++;
					if( cont2 == l ) // Para controlar cuando se utilizara el salto de linea dependiendo de la cantidad de columnas elegidas.
					{
						printf( "\n" );
						cont2 = 0;

					}

					if ( ++ cont % PARADA2 == 0 ) // Para controlar que se pare cada 10 lineas y pida solo enter para continuar.
					{


						do{

							printf( "\n" );
							printf( "Presione ENTER para continuar. \n" );

							tecla = getch(  );
							system( "cls" );
							printf( "\n" );


						}


						while ( tecla != ENTER );

					}


				}


			}


		}

		else if( l == 3 )    // Si la cantidad de columnas es 3
		{
			if( n <= 31 ) // Si el resultado de la operacion es menor o igual que 31.
			{

				printf( "%i  %i/3  -  %i/4  ", i, n-7, n );

				cont2++;

				if( cont2 == l ) // Para controlar cuando se utilizara el salto de linea dependiendo de la cantidad de columnas elegidas.
				{
					printf( "\n" );
					cont2 = 0;

				}

				if ( ++ cont % PARADA3 == 0 ) // Para controlar que se pare cada 10 lineas y pida solo enter para continuar.
				{


					do{

						printf( "\n" );
						printf( "Presione ENTER para continuar. \n" );

						tecla = getch(  );
						system( "cls" );
						printf( "\n" );

					}


					while ( tecla != ENTER );

				}


			}

			else if ( n > 31 ) // Si el resultado de la operacion es mayor que 31.
			{

				abril2 = ( n - 31 ) - 7; // Para obtener el valor del mes adecuado se le resta 31, y 7 para obtener el dia cuando empieza la semana santa.
				abril1 = abril2 + 7;  // Se le suma 7 para obtener el ultimo dia de la semana santa.



				if( abril2 < 0 ) // Si la fecha de semana santa esta entre marzo y abril.
				{
					abril2 = 31 + abril2;
					printf( "%i  %i/3  -  %i/4  ",i, abril2, abril1 );

					cont2++;
					if( cont2 == l ) // Para controlar cuando se utilizara el salto de linea dependiendo de la cantidad de columnas elegidas.
					{
						printf( "\n" );
						cont2 = 0;

					}

					if ( ++ cont % PARADA3 == 0 ) // Para controlar que se pare cada 10 lineas y pida solo enter para continuar.
					{


						do{

							printf( "\n" );
							printf( "Presione ENTER para continuar. \n" );

							tecla = getch(  );
							system( "cls" );
							printf( "\n" );

						}


						while ( tecla != ENTER );

					}


				}

				else if ( abril2 > 0 ) // Si la semana santa queda en abril.
				{
					printf( "%i  %i/4  -  %i/4  ",i, abril2, abril1 );


					cont2++;
					if( cont2 == l ) // Para controlar cuando se utilizara el salto de linea dependiendo de la cantidad de columnas elegidas.
					{
						printf( "\n" );
						cont2 = 0;

					}

					if ( ++ cont % PARADA3 == 0 ) // Para controlar que se pare cada 10 lineas y pida solo enter para continuar.
					{


						do{

							printf( "\n" );
							printf( "Presione ENTER para continuar. \n" );

							tecla = getch(  );
							system( "cls" );
							printf( "\n" );

						}


						while ( tecla != ENTER );

					}


				}


			}


		}

		else if( l == 4 )    // Si la cantidad de columnas es 4
		{
			if( n <= 31 ) // Si el resultado de la operacion es menor o igual que 31.
			{

				printf( "%i  %i/3  -  %i/4  ", i, n-7, n );

				cont2++;

				if( cont2 == l ) // Para controlar cuando se utilizara el salto de linea dependiendo de la cantidad de columnas elegidas.
				{
					printf( "\n" );
					cont2 = 0;

				}

				if ( ++ cont % PARADA4 == 0 ) // Para controlar que se pare cada 10 lineas y pida solo enter para continuar.
				{


					do{

						printf( "\n" );
						printf( "Presione ENTER para continuar. \n" );

						tecla = getch(  );
						system( "cls" );
						printf( "\n" );

					}


					while ( tecla != ENTER );

				}


			}

			else if ( n > 31 ) // Si el resultado de la operacion es mayor que 31.
			{

				abril2 = ( n - 31 ) - 7; // Para obtener el valor del mes adecuado se le resta 31, y 7 para obtener el dia cuando empieza la semana santa.
				abril1 = abril2 + 7;  // Se le suma 7 para obtener el ultimo dia de la semana santa.



				if( abril2 < 0 ) // Si la fecha de semana santa esta entre marzo y abril.
				{
					abril2 = 31 + abril2;
					printf( "%i  %i/3  -  %i/4  ",i, abril2, abril1 );

					cont2++;
					if( cont2 == l ) // Para controlar cuando se utilizara el salto de linea dependiendo de la cantidad de columnas elegidas.
					{
						printf( "\n" );
						cont2 = 0;

					}

					if ( ++ cont % PARADA4 == 0 ) // Para controlar que se pare cada 10 lineas y pida solo enter para continuar.
					{


						do{

							printf( "\n" );
							printf( "Presione ENTER para continuar. \n" );

							tecla = getch(  );
							system( "cls" );
							printf( "\n" );

						}


						while ( tecla != ENTER );

					}


				}

				else if ( abril2 > 0 ) // Si la semana santa queda en abril.
				{
					printf( "%i  %i/4  -  %i/4  ",i, abril2, abril1 );


					cont2++;
					if( cont2 == l ) // Para controlar cuando se utilizara el salto de linea dependiendo de la cantidad de columnas elegidas.
					{
						printf( "\n" );
						cont2 = 0;

					}

					if ( ++ cont % PARADA4 == 0 ) // Para controlar que se pare cada 10 lineas y pida solo enter para continuar.
					{


						do{

							printf( "\n" );
							printf( "Presione ENTER para continuar. \n" );

							tecla = getch(  );
							system( "cls" );
							printf( "\n" );

						}

						while ( tecla != ENTER );

					}

				}


			}


		}


	}



}


int main(  )
{
	int a, b, c;

	printf( "Digite el rango de a\xA4os que desea evaluar: \n" );
	scanf( "%i", &a );
	scanf( "%i", &b );

	printf( "Digite el numero de columnas que desea ver: \n" );
	scanf( "%i", &c );


	do
	{
		if( c > 4 )
		{
			printf( "Las columnas no pueden ser mayor a 4. Intente de nuevo \n" );
			scanf( "%i", &c );

		}

	}while( c > 4 );

	calcusemanasanta( a, b, c );


}
