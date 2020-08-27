#include <stdio.h>
#include <stdlib.h>

int main()
{


int pi(int num)
{

	int term,den;
	float sumatoria;

	for ( term = sumatoria = 0, den = 1; term <= num; term ++, den += 2 )
		if ( term % 2 == 0 )
			sumatoria += 1.0 / den;
		else
			sumatoria -= 1.0 / den;


	return 4 * sumatoria;
}



int pi2(int);
int pi2(int num)
{

	int term,den;
	float sumatoria;

	for ( term = sumatoria = 0, den = 1; term <= num; term ++, den += 2 )
		sumatoria += (term % 2 ? 1.0 : -1.0 ) / den;


	return 4 * sumatoria;
}

}
