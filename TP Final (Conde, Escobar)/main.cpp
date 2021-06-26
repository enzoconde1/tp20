#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
using namespace std;

void Opciones(char n1){

cout<< "seleciones modo de juego :"<<endl;

cout<< "-----------------------------------------------------------------------"<<endl;
cout<< "ingrese 1 para modo de juego de una persona"<<endl;
cout<< "ingrese 2 para modo de juego para dos personas"<<endl;
cout<< "ingrese 3 para el modo simulacion"<<endl;
system("pause");
cout<<endl<< "------------------------------------------------------------------"<<endl;
cout<<endl<< "ingrese uno de los 3 numeros para selecionar el modo de juego :";
cin>>n1;
cout<<endl<< "-----------------------------------------------------------------"<<endl;

switch(n1){
    case 1:

    break;
    case 2:

    break;
    case 3:

    break;

    default:
        cout<< "el numero no es correcto"<<endl;
        break;
}

}




int main()
{char n1;
Opciones(n1);
    return 0;
}
