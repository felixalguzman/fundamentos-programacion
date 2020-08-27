#include <iostream>

using namespace std;



int pi(int num)
{

	int denominador=1;
	float sumatoria=0;

	for (int i = 0; i < num; i++, denominador+=2){

        if (i % 2 == 0)
            sumatoria +=1.0 /denominador;
        else
        sumatoria -=1.0 /denominador;

	}

cout << 4*sumatoria << endl;




}

int main()
{  int numero;
    cout << "Ingrese el numero que desea evaluar: ";
    cin >> numero;
    pi(numero);

}
