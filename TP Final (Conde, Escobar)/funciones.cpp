#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include"rlutil.h"

using namespace std;
using namespace rlutil;

void unJugador();

void Menu(){
char n1;

cout<< "Bienvenido al Juego de 20 :"<<endl;

cout<< "-----------------------------------------------------------------------"<<endl;
system("pause");
cout<<endl<< "-----------------------------------------------------------------"<<endl;
system("cls");
}




void Opciones(){
char n1;

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

while(n1==1 || n1==2 || n1==3){

switch(n1){
    case 1:
        unJugador();
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

}

void unJugador() {

}
