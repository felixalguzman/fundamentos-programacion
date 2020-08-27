#include <iostream>

using namespace std;
/*9. Se llama media armónica de dos números al resultado obtenido
al calcular los inversos de los números, promediarlos y calcular
el inverso del resultado. Escriba una función que acepte dos
argumentos double y devuelva la media armónica de los
números.*/

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
