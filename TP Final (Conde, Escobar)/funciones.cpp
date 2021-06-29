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
    int Aposto,
    Rondas=0,
    vueltas,
    tiradas=5,
    MenosDados,
    TirarDados,
    MaximoDado,
    TotalDePuntos=0,
    dados,
    TotalGanado=0,
    RondasPerdidas=0,
    RondasSinPuntos=0;
    char Nombre[30];

    system("color B1");

    srand(time(NULL));

    cout << "Modo un Jugador" << endl;

    cout<< "ingrse su nombre no maximo de 20 caracteres : ";
    cin.getline(Nombre,30);
    cout<< "-------------------------------------"<<endl;
    cout<< "cuantas rondas vas a jugar : ";
    cin>> Rondas;
    cout<< "-------------------------------------"<<endl;
    cout<< "cuanto vas a apostar : ";
    cin>> Aposto;
    system("CLS");

    for(vueltas=1;vueltas<=Rondas;vueltas++){
        cout<< "ronda #"<<vueltas<<endl;

        for(MenosDados=1;MenosDados<=5;MenosDados++){
            cout<< "-------------------------------------"<<endl;
            cout<< "tirada de dados #"<<MenosDados<<": "<<endl;
            system("pause");

            for(TirarDados=1;TirarDados<=tiradas;TirarDados++){
                dados= 1 + rand() % (6);

                if(TirarDados==1){
                    MaximoDado=dados;
                } else
                if(dados>MaximoDado){
                    MaximoDado=dados;
                }

                switch(dados)  {
                    case 1:
                    cout<< dados<<endl;
                    break;
                    case 2:
                    cout<< dados<<endl;
                    break;
                    case 3:
                    cout<< dados<<endl;
                    break;
                    case 4:
                    cout<< dados<<endl;
                    break;
                    case 5:
                    cout<< dados<<endl;
                    break;
                    case 6:
                    cout<< dados<<endl;
                    break;
                }
            }

            TotalDePuntos=TotalDePuntos+MaximoDado;
            tiradas=tiradas -1;

            if(tiradas==0){
                tiradas=5;
                MaximoDado=0;
            }
        }

        system("cls");
        cout<<endl<< "el total de puntos es: "<<TotalDePuntos<<endl;

        if(TotalDePuntos>=20){
            cout<< "Felicidades ganaste : "<<Aposto<<endl;
            TotalGanado=TotalGanado+Aposto;
        }
        else {
            cout<< "lastima perdiste: "<<Aposto<<endl;
            RondasPerdidas=RondasPerdidas+1;
            Aposto=0;
        }

        if(Aposto==0){
            RondasSinPuntos=RondasSinPuntos+1;
        }

        if(vueltas!=Rondas){
            cout<< "-------------------------------------"<<endl;
            cout<< "cuanto vas a apostar en la siguiente ronda: ";
            cin>> Aposto;}

        TotalDePuntos=0;
    }

    cout<<endl<< "Felicidades "<<Nombre<< " ganaste en total : "<<TotalGanado<<endl;

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

void Recuadro(int x, int y, int ancho, int alto){

    for (int i = x; i <= x + ancho; i++) {
        gotoxy(i, y);
        cout << '-';
        gotoxy(i, y + alto);
        cout << '-';
    }

    for (int i = y; i <= y + alto; i++) {
        gotoxy(x, i);
        cout << '|';
        gotoxy(x+ancho, i);
        cout << '|';
    }


}
