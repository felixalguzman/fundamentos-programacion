#include <iostream>

using namespace std;

/*18. Escriba un programa que divida números enteros positivos por
restas sucesivas.*/

int Divisionressuc(int Dividendo, int Divisor,int contd=0){

  while (Dividendo >0){
    Dividendo = Dividendo-Divisor;
   contd++; //El contador registra la contidad de veces que se hizo la resta osea, es el resultado de la division.

}
 return contd;
}


int main()
{

int x,y,control=0;

while(control==0){

cout<<"Inserte el 1er numero entero positivo"<<endl;
cin>>x;
cout<<"Inserte el 2do numero entero positivo"<<endl;
cin>>y;

if(x>=0 && y>=0){

control=1;

}
else

cout<<"Uno de los numeros introducidos no es entero positivo"<<endl;

}
cout<<"La division de "<<x<<" y "<<y<<" es igual a: "<<Divisionressuc(x,y);

}


