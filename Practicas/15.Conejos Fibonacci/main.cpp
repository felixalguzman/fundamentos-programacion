/*Los conejos de Fibonacci. El matem�tico Leonardo Fibonacci
expuso el siguiente problema, haga un programa para
solucionarlo. Suponga que una pareja de conejos tiene una par
de cr�as cada mes y a la vez las cr�as se hacen f�rtiles al cabo de
un mes. Si comenzamos con una pareja f�rtil y no muere,
�Cu�ntos pares de conejos se tendr�an al cabo de un a�o?*/


#include <iostream>


using namespace std;

int bunnyland(int mama, int crias)
{
    int sum;
    for(int i= 1; i <= 12 ; i++)
    {
     sum=mama+crias;
        mama=crias;
        crias=sum;

    }

    cout << "La cantidad de conejos que tedran sera de: " << sum << endl;
}

int a=0, b=1;


int main()
{
    cout << "Programa para determinar la cantidad de conejos" << endl;
    bunnyland(a, b);





}
