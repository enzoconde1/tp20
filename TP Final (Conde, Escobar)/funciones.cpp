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

int tiroDePuntaje(int Total, int apuesta, int TotalApuesta){
    int v[5],i, valor, contador=0, apuesta_mult;

     for(i=0;i<5;i++){
        v[i]= (rand()%6)+1;
        cout<<v[i]<<endl;
    }

    switch (Total){
        case 20: valor=1; break;
        case 21: valor=2; break;
        case 22: valor=3; break;
        case 23: valor=4; break;
        case 24: valor=5; break;
        default: valor=6; break;
    }

    for(i=0;i<5;i++){
        if (v[i]==valor){
            contador++;
        }
    }



    if(contador!=0){
        apuesta_mult = apuesta * contador;
    }
    else{
    apuesta_mult = apuesta;
    }



    cout << "ganaste: " << apuesta_mult << endl;

    return apuesta_mult;
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

    while(input!='1' && input!='2' && input!='3' && input!='4'){
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

    system("cls");

    switch(input){
            case '1': unJugador(); break;
            case '2': dosJugadores(); break;
            case '3': puntaje(); break;
            case '4': modoSimulacion() ; break;
    }

}

void unJugador() {
    int apuesta,
    rondas=0,
    vueltas=5,
    tirada,
    giro=5,
    dados=0,
    v[5],
    i,
    Total=0,
    RondasSinPuntos=0,
    RondasPerdidas=0,
    resultado,
    TotalApuesta=0;
    char nombre[30];

    srand(time(NULL));

    system("color B1");

    cout << "Modo un Jugador" << endl;
    cout<< "Ingrese nombre : ";
    fflush(stdin);
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

            for(i=0;i<giro;i++){
                v[i]= (rand()%6)+1;
                cout<<v[i]<<endl;

                if(v[i]>dados){
                    dados=v[i];
                }
            }

            cout<< "el maximo dado es en esta ronda  : "<<dados<<endl;
            Total=Total+dados;
            dados=0;
            cout<< "el total es : "<< Total <<endl;
            system("pause");
            system("cls");
            giro=giro-1;
        }

        if (Total >= 20) {
            cout<< "felicidades obtuviste el tiro de puntaje "<<endl;
            system("pause");
            resultado = tiroDePuntaje(Total, apuesta, TotalApuesta);
            TotalApuesta+=resultado;
        }
        else{
            cout<< "lastima perdiste: "<<apuesta<<endl;
            RondasPerdidas=RondasPerdidas+1;
            TotalApuesta=TotalApuesta-apuesta;
            apuesta=0;
        }

        if(resultado==0){
            RondasSinPuntos=RondasSinPuntos+1;
        }


        if(vueltas!=rondas){
            cout<< "-------------------------------------"<<endl;
            cout<< "cuanto vas a apostar en la siguiente ronda: ";
            cin>> apuesta;
            system("cls");
        }

        if(giro==0) {
            giro=5;
            Total=0;
        }

    }

    system("pause");
    system("cls");

    if(RondasPerdidas==0){
    cout<<endl<< "total de rondas perdidas fue ninguna"<<endl;
    }
    else{
    cout<< endl<<"total de rondas perdidas fue : "<<RondasPerdidas<<endl;
    }

    cout<<endl<< "total de rondas sin puntos es : "<<RondasSinPuntos<<endl;
    cout<<endl<<"en total ganaste : "<<TotalApuesta<<endl;
    cout<< endl<<"fin del juego para jugador #1"<<endl;
    cout<<endl<< "gracias por jugar "<<nombre<< "!!"<<endl;
    cout<<endl;
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


