#include <iostream>

using namespace std;

int tipotriang(int a,int b,int c){
 if ((a == b) && (c == a)){
        return 1;
    }
else if ((a == b)||(b == c)|| (a ==c)){
    return 2;
    }
else {
    return 3;
    }
}
int main(){
int x,y,z;

cout<<"Introduzca el lado 1"<<endl;
cin>>x;
cout<<"Introduzca el lado 2"<<endl;
cin>>y;
cout<<"Introduzca el lado 3"<<endl;
cin>>z;
cout<<tipotriang(x,y,z);

}
