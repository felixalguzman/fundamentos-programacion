#include <iostream>

using namespace std;


int esperfecto (int n)
{

    int fact, sumfact;

    for (fact = 1; fact < n; fact++)
    {
        if( n % fact == 0)
        {
            sumfact += fact;
        }

        if( sumfact == n)
        {
            return 1;
        }
    }
    return 0;

}
int main()
{
    int num;
    cout << "Digite un numero para saber si es perfecto  " << endl;
    cin >> num;
    cout << endl;

    cout << esperfecto(num);


}
