#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include"rlutil.h"
#include<conio.h>
#include<stdio.h>
#include<math.h>

using namespace std;
using namespace rlutil;

void unJugador();
void dosJugadores();
void puntaje();
void modoSimulacion();

void Menu(){
    cout<< "Bienvenido al Juego de 20 :"<<endl;
    cout<< "-----------------------------------------------------------------------"<<endl;
    system("pause");
    cout<<endl<< "-----------------------------------------------------------------"<<endl;
    system("cls");
}

void Opciones(){
    char input;
    cout << "Seleccione modo de juego :"<<endl;
    cout << "-----------------------------------------------------------------------"<<endl;
    cout << "Ingrese 1 para modo de juego de una persona"<<endl;
    cout << "Ingrese 2 para modo de juego para dos personas"<<endl;
    cout << "Ingrese 3 para mostrar puntuacion mas alta" << endl;
    cout << "Ingrese 4 para el modo simulacion"<<endl;
    system("pause");


    cout<<endl<< "------------------------------------------------------------------"<<endl;
    cout<<endl<< "Ingrese uno de los 4 numeros para ingresar :";
    input = getch();
    cout<<endl<< "-----------------------------------------------------------------"<<endl;

    while(input<0 || input>4 || isnan(input)){
        if(input=='1' || input=='2'|| input=='3' || input== '4'){
            system("cls");
        } else {
            cout << "Ingrese un numero correcto del 1 al 4: " <<endl;
            input = getch();
        }
        switch(input){
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
