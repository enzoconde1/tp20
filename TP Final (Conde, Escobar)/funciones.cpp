#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include"rlutil.h"
#include<conio.h>
#include<stdio.h>
#include <math.h>

using namespace std;
using namespace rlutil;

void unJugador();
void dosJugadores();
void puntaje();
void modoSimulacion();

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

while(n1<0 || n1>4 || isnan(n1)){
            if(n1=='1' || n1=='2'|| n1=='3' || n1== '4'){
                system("cls");
            } else {
                cout << "Ingrese un numero correcto del 1 al 4" << endl;
                cin >> n1;
            }

            switch(n1){
                case '1': unJugador(); break;
                case '2': dosJugadores(); break;
                case '3': puntaje(); break;
                case '4': modoSimulacion() ; break;
            }

}
}

void unJugador() {
    cout << "hola";

}

void dosJugadores() {
    cout << "hola2";

}

void puntaje() {
    cout << "hola3";

}

void modoSimulacion() {
    cout << "hola4";

}
