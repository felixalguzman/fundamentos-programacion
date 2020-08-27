/*Los conejos de Fibonacci. El matemático Leonardo Fibonacci
expuso el siguiente problema, haga un programa para
solucionarlo. Suponga que una pareja de conejos tiene una par
de crías cada mes y a la vez las crías se hacen fértiles al cabo de
un mes. Si comenzamos con una pareja fértil y no muere,
¿Cuántos pares de conejos se tendrían al cabo de un año?*/


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
