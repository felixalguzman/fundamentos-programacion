#include <iostream>

using namespace std;


int cuantavece (int a, int b){


    int aux=0, cont=0;

    do{


        aux = a % 10;

        if(aux == b)
        {
            cont++;
        }
        a =a / 10;




    }while( a != 0);

    return cont;


    return cont;
}
int main()
{
    int n, m;

    cin >> n;
    cin >> m;

    cout <<cuantavece(n, m);
}
