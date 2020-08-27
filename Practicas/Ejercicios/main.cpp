#include <iostream>

using namespace std;


int sumasuce(int n, int b){


    int sum=0;
    for( int i=0; i< b; i++)
    {
        sum += n;

    }
    return sum;


}
int main()
{
    int m, d;

    cout << "Digite 2 numeros:" << endl;

    cin >> m;
    cin >> d;

    cout << sumasuce(m, d);
}
