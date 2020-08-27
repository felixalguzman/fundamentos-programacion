#include <iostream>
#include <stdlib.h>

#define MAXGRAD 100

using namespace std;

int main()
{int farenheit, celsius;

for (farenheit = 0; farenheit <= MAXGRAD; farenheit += 5){

    celsius = (farenheit - 32) / 1.8;
    cout << farenheit << "\t" << celsius << endl;
}

    return 0;


}
