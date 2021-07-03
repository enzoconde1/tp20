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
#include"ascii.h"
using namespace rlutil;

void unJugador();
void dosJugadores();
void puntaje();
void modoSimulacion();
void tiroDePuntajeDosJugadores();

int tiroDePuntajeDosJugadores(int ApostarJ1, int ApostarJ2, int Puestos, int  TotalDados){
    int v[5],i, valor, contador=0, apuesta_mult;

     for(i=0;i<5;i++){
        v[i]= (rand()%6)+1;
        cout<<v[i]<<endl;
    }

    switch (TotalDados){
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

    if(Puestos%2==0){

        if(contador!=0){
            apuesta_mult = ApostarJ2 * contador;
        }
        else{
        apuesta_mult = ApostarJ2;
        }
    }
    else if(contador!=0){
        apuesta_mult = ApostarJ1 * contador;
    }
    else{
        apuesta_mult = ApostarJ1;
    }

    return apuesta_mult;
}

int tiroDePuntaje(int Total, int apuesta, int TotalApuesta){
    int v[5],i, valor, contador=0, apuesta_mult, agregarX=35;

    system("color B1");
    recuadro(6, 2, 109, 27, 11, 5);

    for(i=0;i<5;i++){

        gotoxy(52,7);
        cout<< "Tiro de puntaje >> ";

        v[i]= (rand()%6)+1;

        if(v[i]==1){
            dado1(agregarX,12);
            agregarX=agregarX+10;
        }
        if(v[i]==2){
            dado2(agregarX,12);
            agregarX=agregarX+10;
        }
        if(v[i]==3){
            dado3(agregarX,12);
            agregarX=agregarX+10;
        }
        if(v[i]==4){
            dado4(agregarX,12);
            agregarX=agregarX+10;
        }
        if(v[i]==5){
            dado5(agregarX,12);
            agregarX=agregarX+10;
        }
        if(v[i]==6){
            dado6(agregarX,12);
            agregarX=agregarX+10;
        }
        Sleep(250);
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


    gotoxy(55,22);
    cout << "Ganaste: " << apuesta_mult;
    gotoxy(40,25);
    system("pause");

    return apuesta_mult;
}

void Inicio(){
    recuadro(6, 2, 109, 27, 11, 5);

    recuadro(42, 9, 30, 4, 11, 5);
    gotoxy(45,11);
    cout<< "BIENVENIDO AL JUEGO DE 20";
    gotoxy(40,25);
    system("pause");
    system("cls");
}

void Menu(){
    char input;

    system("color B1");

    recuadro(6, 2, 109, 27, 11, 5);

    recuadro(42, 9, 30, 4, 11, 5);
    gotoxy(50,11);
    cout << "Menu de Inicio";
    gotoxy(47,15);
    cout << "1. Modo UN JUGADOR";
    gotoxy(47,16);
    cout << "2. Modo DOS JUGADORES";
    gotoxy(47,17);
    cout << "3. Mostrar PUNTUACION";
    gotoxy(47,18);
    cout << "4. Modo SIMULACION";

    gotoxy(38,20);
    cout<< "Ingrese uno de los numeros para empezar :";
    input = getch();

    while(input!='1' && input!='2' && input!='3' && input!='4'){
            system("cls");
            system("color 4B");
            recuadro(6, 2, 109, 27, 11, 4);
            gotoxy(54,10);
            cout << "¡Atencion!";
            gotoxy(43,12);
            cout << "Ha ingresado un numero incorrecto";
            gotoxy(40,25);
            system("pause");
            Menu();
    }

    switch(input){
            case '1': unJugador(); break;
            case '2': dosJugadores(); break;
            case '3': puntaje(); break;
            case '4': modoSimulacion() ; break;
    }

}

void unJugador() {
    int apuesta,
    rondas,
    vueltas,
    tirada,
    giro=5,
    dados=0,
    v[5],
    i,
    agregarX=35,
    Total=0,
    RondasSinPuntos=0,
    RondasPerdidas=0,
    resultado,
    TotalApuesta=0;
    char nombre[15];

    srand(time(NULL));

    system("color B1");

    recuadro(6, 2, 109, 27, 11, 5);

    recuadro(42, 9, 30, 4, 11, 5);
    gotoxy(50,11);
    cout << "Modo UN JUGADOR" << endl;
    gotoxy(44,15);
    cout<< "Ingrese su nombre >> ";
    fflush(stdin);
    cin.getline(nombre,15);
    gotoxy(42,17);
    cout<< "Cantidad de rondas a jugar >> ";
    cin>> rondas;
    gotoxy(46,19);
    cout<< "Ingrese apuesta >> ";
    cin>> apuesta;
    system("cls");

    recuadro(6, 2, 109, 27, 11, 5);

    for(vueltas=1;vueltas<=rondas;vueltas++){

        for(tirada=0;tirada<5;tirada++){

            recuadro(6, 2, 109, 27, 11, 5);
            gotoxy(55,5);
            cout<< "Ronda >> "<<vueltas;
            gotoxy(54,7);
            cout<< "Tirada >>> "<<tirada+1;

            for(i=0;i<giro;i++){
                v[i]= (rand()%6)+1;

                if(v[i]==1){
                    dado1(agregarX,12);
                    agregarX=agregarX+10;
                }
                if(v[i]==2){
                    dado2(agregarX,12);
                    agregarX=agregarX+10;
                }
                if(v[i]==3){
                    dado3(agregarX,12);
                    agregarX=agregarX+10;
                }
                if(v[i]==4){
                    dado4(agregarX,12);
                    agregarX=agregarX+10;
                }
                if(v[i]==5){
                    dado5(agregarX,12);
                    agregarX=agregarX+10;
                }
                if(v[i]==6){
                    dado6(agregarX,12);
                    agregarX=agregarX+10;
                }

                if(v[i]>dados){
                    dados=v[i];
                }

                Sleep(250);
            }

            gotoxy(45,20);
            cout<< "Maximo dado de esta tirada >> "<<dados;
            Total=Total+dados;
            dados=0;
            gotoxy(50,22);
            cout<< "Total de puntos >> "<< Total;
            gotoxy(40,25);
            system("pause");
            system("cls");
            giro=giro-1;
            agregarX=35;
        }

        if (Total >= 20) {
            system("color B1");
            recuadro(6, 2, 109, 27, 11, 5);

            recuadro(41, 9, 35, 4, 11, 5);
            gotoxy(44,11);
            cout<< "Obtuviste el tiro de puntaje >> ";
            gotoxy(40,25);
            system("pause");
            resultado = tiroDePuntaje(Total, apuesta, TotalApuesta);
            TotalApuesta+=resultado;
            system("cls");
        }
        else{
            recuadro(6, 2, 109, 27, 5, 11);

            gotoxy(49,11);
            cout<< "Total de puntos >> "<< Total;
            gotoxy(47,13);
            cout<< "<< No superaste los 20 >>";
            gotoxy(46,15);
            cout<< "Perdiste lo apostado >> "<<apuesta;
            RondasPerdidas=RondasPerdidas+1;
            TotalApuesta=TotalApuesta-apuesta;
            apuesta=0;
            gotoxy(40,25);
            system("pause");
        }

        if(resultado==0){
            RondasSinPuntos=RondasSinPuntos+1;
        }


        if(vueltas!=rondas){
            system("color B1");
            recuadro(6, 2, 109, 27, 11, 5);

            gotoxy(40,11);
            cout<< "Apuesta para la siguiente ronda >> ";
            cin>> apuesta;
            gotoxy(40,25);
            system("pause");
            system("cls");
        }

        if(giro==0) {
            giro=5;
            Total=0;
        }

    }

    system("cls");

    system("color B1");
    recuadro(6, 2, 109, 27, 11, 5);

    recuadro(42, 9, 30, 4, 11, 5);
    gotoxy(52,11);
    cout<<"FIN DE JUEGO";
    gotoxy(44,15);
    cout<< "Gracias por jugar >> "<<nombre;
    gotoxy(46,17);
    cout<<"Puntaje acumulado >> "<<TotalApuesta;

    if(RondasSinPuntos!=0){
        gotoxy(44,19);
        cout<< "Cantidad de rondas sin puntos >> "<<RondasSinPuntos<<endl;
    }

    if(RondasPerdidas!=0){
        gotoxy(43,21);
        cout<<"Cantidad de rondas con perdidas >> "<<RondasPerdidas<<endl;
    }

    gotoxy(40,25);
    system("pause");
    system("cls");
    Menu();
}

void dosJugadores() {
    int Rondas,
    Puestos,
    RondasPerdidasJ1=0,
    RondasPerdidasJ2=0,
    Max[5],
    RondasSinPuntosJ1=0,
    RondasSinPuntosJ2=0,
    TirarDados,
    ApostarJ1,
    ApostarJ2,
    MenosDados=5,
    Resultado=0,
    Tiradas,
    Dados=0,
    TotalDados=0,
    TotalApuestaJ1=0,
    TotalApuestaJ2=0,
    Vueltas=5;
    char NombreJ1[30],
    NombreJ2[30];

    srand(time(NULL));

    system("color B1");

    cout<< "bienvenido al modo dos jugadores"<<endl;

    cout<< "ingrese el nombre del jugadorN1 :";
    fflush(stdin);
    cin.getline(NombreJ1,30);
    cout<< "ingrese el nombre del jugadorN2 :";
    cin.getline(NombreJ2,30);
    cout<< "-------------------------------------"<<endl;
    cout<< "Ingrese cuantas rondas jugaran los dos jugadores : ";
    cin>> Rondas;
    cout<< "-------------------------------------"<<endl;
    cout<< "ingrese cuanto va apostar Jugador#1 : ";
    cin>>  ApostarJ1;
    cout<< "ingrese cuanto va apostar  Jugador#2 : ";
    cin>> ApostarJ2;
    system("pause");
    system("cls");

    for(Vueltas=1;Vueltas<=Rondas;Vueltas++){

        cout<< "jugador#1 :"<<NombreJ1<<endl;
        cout<< "-------------------------------------"<<endl;
        cout<< "ronda #"<<Vueltas<<endl;



        for(Tiradas=0;Tiradas<5;Tiradas++){
            cout<< "-------------------------------------"<<endl;
            cout<< "Tirada #"<<Tiradas+1<<endl;

           for(TirarDados=0;TirarDados<MenosDados;TirarDados++){

                 Max[TirarDados]= (rand()%6)+1;
                cout<<Max[TirarDados]<<endl;

                if(Max[TirarDados]>Dados){
                    Dados=Max[TirarDados];
                }


           }
           cout<< "el maximo dado es en esta ronda  : "<<Dados<<endl;
           TotalDados+=Dados;
           cout<< "el total es : "<<  TotalDados <<endl;
           Dados=0;
           MenosDados=MenosDados-1;
           system("pause");
           system("cls");
       }









    Puestos+=1;



    if(TotalDados>=20){
    cout<< "felicidades obtuviste el tiro de puntaje "<<endl;
    Resultado=tiroDePuntajeDosJugadores(ApostarJ1, ApostarJ2, Puestos,  TotalDados);
       TotalApuestaJ1+=Resultado;
       cout<< "en total ganaste en esta ronda es : "<<TotalApuestaJ1<<endl;
        TotalDados=0;
            system("pause");
        }
    else{
            cout<< "lastima perdiste: "<<ApostarJ1<<endl;
            RondasPerdidasJ1=RondasPerdidasJ1+1;
            TotalApuestaJ1=TotalApuestaJ1-ApostarJ1;
            ApostarJ1=0;
            TotalDados=0;
        }


  if(Resultado==0){
            RondasSinPuntosJ1=RondasSinPuntosJ1+1;
        }


      TotalDados=0;
      MenosDados=5;


        cout<<endl<<"jugador#2 :"<<NombreJ2<<endl;
         for(Tiradas=0;Tiradas<5;Tiradas++){

           cout<< "-------------------------------------"<<endl;
           cout<< "Tirada #"<<Tiradas+1<<endl;

           for(TirarDados=0;TirarDados<MenosDados;TirarDados++){

                 Max[TirarDados]= (rand()%6)+1;
                cout<<Max[TirarDados]<<endl;

                if(Max[TirarDados]>Dados){
                    Dados=Max[TirarDados];
                }


           }
           cout<< "el maximo dado es en esta ronda  : "<<Dados<<endl;
           TotalDados+=Dados;
           cout<< "el total es : "<<  TotalDados <<endl;
           Dados=0;
           MenosDados=MenosDados-1;
           system("pause");
           system("cls");
           }

           Puestos+=1;



            if(TotalDados<=20){
            cout<< "felicidades obtuviste el tiro de puntaje "<<endl;
            Resultado=tiroDePuntajeDosJugadores(ApostarJ1, ApostarJ2, Puestos,  TotalDados);
            TotalApuestaJ2+=Resultado;
            cout<< "en total ganaste en esta ronda es : "<<TotalApuestaJ2<<endl;
            TotalDados=0;
            system("pause");}
            else{
            cout<< "lastima perdiste: "<<ApostarJ2<<endl;
            RondasPerdidasJ2=RondasPerdidasJ2+1;
            TotalApuestaJ2=TotalApuestaJ2-ApostarJ2;
            ApostarJ2=0;
            TotalDados=0;
            }
            if(Resultado==0){
            RondasSinPuntosJ1=RondasSinPuntosJ1+1;
            }

            if(Vueltas != Rondas){
            cout<< "-------------------------------------"<<endl;
            cout<< "cuanto vas a apostar en la siguiente ronda Jugador#1: ";
            cin>> ApostarJ1;
            cout<< "-------------------------------------"<<endl;
            cout<< "cuanto vas a apostar en la siguiente ronda jugador#2: ";
            cin>> ApostarJ2;
            system("cls");
            }

            MenosDados=5;
   }


    system("pause");
    system("cls");

    cout<< "jugador#1 nombre : "<<NombreJ1<<endl;





 if(RondasPerdidasJ1==0){
    cout<<endl<< "total de rondas perdidas fue ninguna"<<endl;
    }
    else{
    cout<< endl<<"total de rondas perdidas fue : "<<RondasPerdidasJ1<<endl;
    }
    cout<<endl<< "total de rondas sin puntos es : "<<RondasSinPuntosJ1<<endl;
    cout<<endl<<"en total ganaste : "<<TotalApuestaJ1<<endl;
    cout<<endl<<"fin del juego para jugador #1"<<endl;
    cout<<endl<< "gracias por jugar "<<NombreJ1<< "!!"<<endl;
    cout<<endl<< "al final del juego se mostrara el resultado de quien gano"<<endl;
    system("pause");
    system("cls");

    cout<< "jugador#2 nombre: "<<NombreJ2<<endl;
    if(RondasPerdidasJ2==0){
    cout<<endl<< "total de rondas perdidas fue ninguna"<<endl;
    }
    else{
    cout<< endl<<"total de rondas perdidas fue : "<<RondasPerdidasJ2<<endl;
    }
    cout<<endl<< "total de rondas sin puntos es : "<<RondasSinPuntosJ2<<endl;
    cout<<endl<<"en total ganaste : "<<TotalApuestaJ2<<endl;
    cout<<endl<<"fin del juego para jugador #2"<<endl;
    cout<<endl<< "gracias por jugar "<<NombreJ2<< "!!"<<endl;

    system("pause");
    system("cls");

    if(TotalApuestaJ1>TotalApuestaJ2){
        cout<< "felicidades el ganador fue :"<<NombreJ1<<endl;
        cout<< "con un total de puntos de : "<<TotalApuestaJ1<<endl;
    }
    else{
        cout<< "felicidades el ganador fue : "<<NombreJ2<<endl;
        cout<< "con un total de puntos de : "<<TotalApuestaJ2<<endl;
    }
    system("pause");
    system("cls");
    Menu();
}

void puntaje() {
    cout << "hola3";

}

void modoSimulacion() {
    cout << "hola4";

}


