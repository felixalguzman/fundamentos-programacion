#include <iostream>

using namespace std;
/*9. Se llama media arm�nica de dos n�meros al resultado obtenido
al calcular los inversos de los n�meros, promediarlos y calcular
el inverso del resultado. Escriba una funci�n que acepte dos
argumentos double y devuelva la media arm�nica de los
n�meros.*/

double medarmon(double a,double b){

double prom=0;

prom=(1/a + 1/b)/2;

return 1/prom;
}

int main()
{
int n,m;
cout<<"Introduzca el 1er numero"<<endl;
    cin>>n;
cout<<"Introduzca el 2do numero"<<endl;
    cin>>m;

cout<<"La media armonica de "<<n<<" y "<<m<<" es: "<<medarmon(n,m);
}
