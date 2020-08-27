#include <iostream>

using namespace std;


double media ( double a, double b){

    double inverso1, inverso2, resultado, resultadoinver, promedio;

    inverso1 = 1 / a;
    inverso2 = 1 / b;

    resultado = inverso1 + inverso2;
    //cout << resultado << endl;

    promedio = (resultado)/2;
    //cout << promedio << endl;

    resultadoinver = 1/( promedio);

    return resultadoinver;




}
int main()
{
    double m, n;

    cin >> m;
    cin >> n;

    cout << media(m, n);
}
