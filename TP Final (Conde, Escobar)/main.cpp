#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
<<<<<<< HEAD
#include"rlutil.h"
#include<conio.h>
#include<stdio.h>

=======
>>>>>>> parent of b038649 (actualizacion)
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

<<<<<<< HEAD
void Opciones();
void Menu();
=======

>>>>>>> parent of b038649 (actualizacion)


<<<<<<< HEAD
Menu();
Opciones();
=======
int main()
{char n1;
Opciones(n1);
>>>>>>> parent of b038649 (actualizacion)
    return 0;
}
