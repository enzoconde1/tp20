#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include"rlutil.h"
#include<conio.h>
#include<stdio.h>
#include<math.h>

using namespace std;
#include"funciones.h"
using namespace rlutil;

void unJugador();
void dosJugadores();
void puntaje();
void modoSimulacion();
void NumerosAleatorios();

void NumerosAleatorios(int giro){
int v[5],i;
 srand(time(NULL));
 for(i=0;i<giro;i++){
    v[i]= (rand()%6)+1;
    cout<<v[i]<<endl;
 }
}

void Inicio(){
    gotoxy(15,5);
    cout<< "Bienvenido al Juego de 20 :"<<endl;
    gotoxy(10,7);
    system("pause");
    system("cls");
}

void Menu(){
    char input;

    recuadro(2, 4, 55, 20, 3, 5);
    gotoxy(15,5);
    cout << "Menu de Inicio :"<<endl;
    gotoxy(12,7);
    cout << "1. Modo UN JUGADOR"<<endl;
    gotoxy(12,8);
    cout << "2. Modo DOS JUGADORES"<<endl;
    gotoxy(12,9);
    cout << "3. Mostrar PUNTUACION" << endl;
    gotoxy(12,10);
    cout << "4. Modo SIMULACION"<<endl;

    gotoxy(5,12);
    cout<< "Ingrese uno de los 4 numeros para empezar :";
    input = getch();

    while(input<0 || input>4 || isnan(input)){
        if(input=='1' || input=='2'|| input=='3' || input== '4'){
            system("cls");
        }
        else {
            system("cls");
            system("color B1");
            gotoxy(20,8);
            setColor(RED);
            cout << "¡Atencion!";
            gotoxy(12,10);
            cout << "Ingrese un numero correcto";
            input = getch();
            system("cls");
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
    int apuesta,
    rondas=0,
    vueltas=5,
    tirada,
    giro=5,
    MaximoDado,
    dados,
    TotalDePuntos=0,
    TotalGanado=0,
    RondasPerdidas=0,
    RondasSinPuntos=0;
    char nombre[30];

    system("color B1");

    cout << "Modo un Jugador" << endl;
    cout<< "Ingrese nombre : ";
    cin.getline(nombre,30);
    cout<< "-------------------------------------"<<endl;
    cout<< "Ingrese rondas : ";
    cin>> rondas;
    cout<< "-------------------------------------"<<endl;
    cout<< "Ingrese apuesta : ";
    cin>> apuesta;
    system("CLS");

    for(vueltas=1;vueltas<=rondas;vueltas++){
        cout<< "ronda #"<<vueltas<<endl;

        for(tirada=1;tirada<=5;tirada++){
            cout<< "-------------------------------------"<<endl;
            cout<< "tirada de dados #"<<tirada<<": "<<endl;
            NumerosAleatorios(giro);
            system("pause");
            system("cls");
            giro=giro-1;
        }

        TotalDePuntos=TotalDePuntos+MaximoDado;

        if(tirada==0){
            tirada=5;
            MaximoDado=0;
        }

    }

    system("cls");
        cout<<endl<< "el total de puntos es: "<<TotalDePuntos<<endl;

    if(TotalDePuntos>=20){
            cout<< "Felicidades ganaste : "<<apuesta<<endl;
            TotalGanado=TotalGanado+apuesta;
        }
        else {
            cout<< "lastima perdiste: "<<apuesta<<endl;
            RondasPerdidas=RondasPerdidas+1;
            apuesta=0;
        }

        if(apuesta==0){
            RondasSinPuntos=RondasSinPuntos+1;
        }

        if(vueltas!=rondas){
            cout<< "-------------------------------------"<<endl;
            cout<< "cuanto vas a apostar en la siguiente ronda: ";
            cin>> apuesta;}

        TotalDePuntos=0;

    cout<<endl<< "Felicidades "<<nombre<< " ganaste en total : "<<TotalGanado<<endl;

    if(RondasPerdidas==0){
        cout<<endl<< "total de rondas perdidas fue ninguna"<<endl;
    }
    else {
        cout<< endl<<"total de rondas perdidas fue : "<<RondasPerdidas<<" suerte para la proxima"<<endl;
    }

    cout<<endl<< "total de rondas sin puntos es : "<<RondasSinPuntos<<endl;
    system("pause");

    system("cls");
    Menu();
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


