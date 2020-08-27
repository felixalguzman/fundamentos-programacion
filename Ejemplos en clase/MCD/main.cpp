#include <iostream>

using namespace std;

int main()
{

    int a, b, res, res2;

    cout << "digite 2 numeros" << endl;
    cin >> a;
    cin >> b;

    res = a % b;

    while( res != 0)
    {
        int aux, aux1;

        aux = a % b;

        if (aux != 0)
        {
            res = b / aux;
            aux1 = b % aux;
        }
          if( aux1  == 0)
            {
                res2 = (a * b ) / aux;
                cout << "El MCD es: " << aux << endl;
                cout << "El MCM es: " << res2 << endl;

            }

    }

    if( res == 0)
        {
        res2 = (a * b ) / b;
        cout << "El MCD es: " << b;
        cout << "El MCM es: " << res2 << endl;

        }
}
