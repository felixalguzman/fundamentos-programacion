#include <iostream>
#include <stdlib.h>
#define MAX 1000
using namespace std;

int main()
{
    int cont=0;
    float farenheit, celcius;

    cout << "Farenheit" << "      " << "Celcius" << endl;
    cout << endl;

    do {

        for(cont=0; cont <= 25; cont++)
        {

             for( farenheit=0; farenheit <= MAX; farenheit +=5)
                {

                    celcius = (farenheit - 32) / 1.8;
                    cont++;

                 if ( cont == 25)
            {
                                    cout << endl;
                                    cout << "PRESIONE ENTER PARA MOSTRAR MAS" << endl;

                system("pause>nul");

                system("cls");

                cont =0;

            }

        cout<< farenheit << "              " << celcius << endl;
        }
    }
    }while(farenheit <= 1000);
}
