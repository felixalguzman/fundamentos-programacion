#include <iostream>

using namespace std;



float pi(int n)
{
    int term=0, den;
    float sumatoria=0;

    for(  den =1; term <= n; term++, den +=2)
    {
        if (term % 2 ==0){
            sumatoria += 1/ den;
        }
        else
            sumatoria -= 1/ den;


    }

    return (4)*(sumatoria);
}


int main()
{
    int num;
    cout << "Digite un numero hasta que desee que llegue la serie." << endl;
    cin >> num;
    cout << endl;

     cout << pi(num);


}
