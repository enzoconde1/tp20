#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include"funciones.h"
#include"rlutil.h"

using namespace std;
using namespace rlutil;


int intro(){

    gotoxy(36,16);
    cout<<"BIENVENIDO A GREED";
    gotoxy(26,20);
    cout<<"<presiona cualquier tecla para continuar>";
    getch();
    system("cls");
}

int anotadorPlay2(int puntosJ1,int puntosJ2,int puntosRondaJ1,int puntosRondaJ2,int ronda,char nameJ1[],char nameJ2[]){

    setColor(BLACK);
    gotoxy(44,8);
    cout<<"RONDA "<<ronda;


    gotoxy(5,10);
    cout<<"                  ";
    gotoxy(5,12);
    cout<<"                     ";

    setColor(WHITE);
    gotoxy(9,8);
    cout<<nameJ1;

    setColor(BLACK);
    gotoxy(9,10);
    cout<<"Puntaje total: ";
    setColor(WHITE);
    cout<<puntosJ1;
    setColor(BLACK);
    gotoxy(9,12);
    cout<<"Puntaje de ronda: ";
    setColor(WHITE);
    cout<<puntosRondaJ1;

    setColor(WHITE);
    gotoxy(65,8);
    cout<<nameJ2;
    setColor(BLACK);
    gotoxy(65,10);
    cout<<"Puntaje total: ";
    setColor(WHITE);
    cout<<puntosJ2;
    setColor(BLACK);
    gotoxy(65,12);
    cout<<"Puntaje de ronda: ";
    setColor(WHITE);
    cout<<puntosRondaJ2;
}

int anotadorPlays1(int puntosJ1,int puntosRondaJ1,char jugador[],int ronda){

    setColor(BLACK);
    gotoxy(44,8);
    cout<<"RONDA "<<ronda;

    setColor(WHITE);
    gotoxy(5,8);
    cout<<jugador;

    setColor(BLACK);
    gotoxy(5,10);
    cout<<"Puntaje total: ";
    setColor(WHITE);
    cout<<puntosJ1;

    setColor(BLACK);
    gotoxy(5,12);
    cout<<"Puntaje de ronda: ";
    setColor(WHITE);
    cout<<puntosRondaJ1;

}

void plays1(int puntajeMax,char nombre[]){
    int ronda=1;
    int puntosJ1=0;
    int dado1J,dado2J,dado3J,dado4J,dado5J;
    int block1, block2;
    char jugador[10];


    introducirNombrePlays1(jugador);

    while(ronda<=3){
        int puntosRondaJ1=0;
        bool dado1=true,dado2=true,dado3=true,dado4=true,dado5=true;
        bool finalizar=false;
        bool game_over=false;



        establecerBloqueadores(block1,block2);


        while(finalizar==false && game_over==false){
            char desicion='0';
            char press='0';


            anotadorPlays1(puntosJ1,puntosRondaJ1,jugador,ronda);


            while(press!='1'){
                setColor(BLACK);
                gotoxy(5,22);
                cout<<"<PRESIONE 1 PARA TIRAR DADOS>";
                press=getch();
                if (press=='1'){
                    gotoxy(5,22);
                    cout<<"                             ";
                }
            }
            press='0';


            if (dado5==true){
                setColor(WHITE);
                dado5J=dado(80,20);
                borrarDados(84,22);
                pintarDados(84,22,dado5J);
                if(dado5J==block1 || dado5J==block2){
                    dado5=false;
                    setColor(RED);
                    dado(80,20);
                    pintarDados(84,22,dado5J);
                }
                else{
                    puntosRondaJ1+=dado5J;
                }
            }
            if (dado4==true){
                setColor(WHITE);
                dado4J=dado(70,20);
                borrarDados(74,22);
                pintarDados(74,22,dado4J);
                if(dado4J == block1 || dado4J==block2){
                    dado4=false;
                    setColor(RED);
                    dado(70,20);
                    pintarDados(74,22,dado4J);
                }
                else{
                    puntosRondaJ1+=dado4J;
                }
            }
            if (dado3==true){
                setColor(WHITE);
                dado3J=dado(60,20);
                borrarDados(64,22);
                pintarDados(64,22,dado3J);
                if(dado3J == block1 || dado3J == block2){
                    dado3=false;
                    setColor(RED);
                    dado(60,20);
                    pintarDados(64,22,dado3J);
                }
                else{
                    puntosRondaJ1+=dado3J;
                }
            }
            if (dado2==true){
                setColor(WHITE);
                dado2J=dado(50,20);
                borrarDados(54,22);
                pintarDados(54,22,dado2J);
                if(dado2J==block1 || dado2J == block2){
                    dado2=false;
                    setColor(RED);
                    dado(50,20);
                    pintarDados(54,22,dado2J);
                }
                else{
                    puntosRondaJ1+=dado2J;
                }
            }
            if (dado1==true){
                setColor(WHITE);
                dado1J=dado(40,20);
                borrarDados(44,22);
                pintarDados(44,22,dado1J);
                if(dado1J==block1 || dado1J==block2){
                    dado1=false;
                    setColor(RED);
                    dado(40,20);
                    pintarDados(44,22,dado1J);
                }
                else{
                    puntosRondaJ1+=dado1J;
                }
            }


            anotadorPlays1(puntosJ1,puntosRondaJ1,jugador,ronda);


            if(dado1==false && dado2 ==false && dado3 ==false && dado4==false && dado5==false){
                game_over=true;
                puntosRondaJ1=0;
                getch();
                for(int i=35;i<90;i++){
                        gotoxy(i,19);
                        printf(" ");
                        gotoxy(i,20);
                        printf(" ");
                        gotoxy(i,21);
                        printf(" ");
                        gotoxy(i,22);
                        printf(" ");
                        gotoxy(i,23);
                        printf(" ");
                        gotoxy(i,24);
                        printf(" ");
                        gotoxy(i,25);
                        printf(" ");
                        gotoxy(i,26);
                        printf(" ");
                        gotoxy(i,27);
                        printf(" ");
                }
                gotoxy(40,22);
                cout<<"<GAME OVER>";
                getch();
            }

            while(desicion!='1' && desicion != '2' && game_over==false){

                gotoxy(8,21);
                cout<<"DESEA SEGUIR JUGANDO?";
                gotoxy(8,22);
                cout<<"     1-SI   2- NO     ";
                desicion=getch();
                if(desicion=='2'){
                    finalizar=true;
                    for(int i=35;i<90;i++){
                        gotoxy(i,19);
                        printf(" ");
                        gotoxy(i,20);
                        printf(" ");
                        gotoxy(i,21);
                        printf(" ");
                        gotoxy(i,22);
                        printf(" ");
                        gotoxy(i,23);
                        printf(" ");
                        gotoxy(i,24);
                        printf(" ");
                        gotoxy(i,25);
                        printf(" ");
                        gotoxy(i,26);
                        printf(" ");
                        gotoxy(i,27);
                        printf(" ");


                        gotoxy(8,21);
                        cout<<"                      ";
                        gotoxy(8,22);
                        cout<<"                      ";
                    }

                    gotoxy(38,22);
                    cout<<"<RONDA "<<ronda<<" FINALIZADA>";
                    puntosJ1+=puntosRondaJ1;
                    getch();
                }
                else{
                    if(desicion=='1'){
                        gotoxy(8,21);
                        cout<<"                      ";
                        gotoxy(8,22);
                        cout<<"                      ";
                    }
                }
            }
        }
        ronda++;
    }

    getch();
    system("cls");
    pintarBordes();

    setColor(WHITE);
    for(int i=33;i<63;i++){
        gotoxy(i,17);
        printf("%c",205);
        gotoxy(i,21);
        printf("%c",205);
    }
    for(int i=18;i<21;i++){
        gotoxy(32,i);
        printf("%c",186);
        gotoxy(63,i);
        printf("%c",186);
    }
    gotoxy(32,17);
    printf("%c",201);
    gotoxy(63,17);
    printf("%c",187);
    gotoxy(32,21);
    printf("%c",200);
    gotoxy(63,21);
    printf("%c",188);

    setColor(BLACK);
    gotoxy(34,19);
    cout<<"Tu puntaje es: "<<puntosJ1;
    getch();

    if (puntosJ1>puntajeMax){
        system("cls");

        setColor(YELLOW);
        gotoxy(27,14);
        cout<<"Felicidades tu puntaje es el mas alto";

        setColor(WHITE);
        gotoxy(34,21);
        cout<<"Introduci tu nombre: ";
        puntajeMax=puntosJ1;

        setColor(BLACK);
        gotoxy(55,21);
        cin.getline(nombre,30);
    }


    system("cls");
    menu(puntajeMax,nombre);

}

void play2(int puntajeMax,char nombre[]){
    int puntosJ2=0, puntosJ1=0;
    int dado1J,dado2J,dado3J,dado4J,dado5J;
    int dado1J2,dado2J2,dado3J2,dado4J2,dado5J2;
    int ganador=0;


    int ronda=1;
    int block1, block2;
    char nameJ1[10],nameJ2[10];

    introducirNombres(nameJ1,nameJ2);


    while(ronda<=3){
        bool game_overP1=false, game_overP2=false;
        bool finalizarJ1=false,finalizarJ2=false;
        bool dado1P2=true,dado2P2=true,dado3P2=true,dado4P2=true,dado5P2=true;
        bool dado1=true,dado2=true,dado3=true,dado4=true,dado5=true;
        int puntosRondaJ2=0, puntosRondaJ1=0;
        char desicion='0',desicion2='0';
        char press='0';



        if(game_overP1==false){
            establecerBloqueadores(block1,block2);
            anotadorPlay2(puntosJ1,puntosJ2,puntosRondaJ1,puntosRondaJ2,ronda, nameJ1,nameJ2);
        }



        while(game_overP1==false && finalizarJ1==false){

            while(press!='1'){

                setColor(BLACK);
                gotoxy(5,22);
                cout<<"<PRESIONE 1 PARA TIRAR DADOS>";
                press=getch();
                if (press=='1'){
                    gotoxy(5,22);
                    cout<<"                             ";
                }
            }
            press='0';

            if (dado5==true){
                setColor(WHITE);
                dado5J=dado(80,20);
                borrarDados(84,22);
                pintarDados(84,22,dado5J);
                if(dado5J==block1 || dado5J==block2){
                    dado5=false;
                    setColor(RED);
                    dado(80,20);
                    pintarDados(84,22,dado5J);
                }
                else{
                    puntosRondaJ1+=dado5J;
                }
            }
            if (dado4==true){
                setColor(WHITE);
                dado4J=dado(70,20);
                borrarDados(74,22);
                pintarDados(74,22,dado4J);
                if(dado4J == block1 || dado4J==block2){
                    dado4=false;
                    setColor(RED);
                    dado(70,20);
                    pintarDados(74,22,dado4J);
                }
                else{
                    puntosRondaJ1+=dado4J;
                }
            }
            if (dado3==true){
                setColor(WHITE);
                dado3J=dado(60,20);
                borrarDados(64,22);
                pintarDados(64,22,dado3J);
                if(dado3J == block1 || dado3J == block2){
                    dado3=false;
                    setColor(RED);
                    dado(60,20);
                    pintarDados(64,22,dado3J);
                }
                else{
                    puntosRondaJ1+=dado3J;
                }
            }
            if (dado2==true){
                setColor(WHITE);
                dado2J=dado(50,20);
                borrarDados(54,22);
                pintarDados(54,22,dado2J);
                if(dado2J==block1 || dado2J == block2){
                    dado2=false;
                    setColor(RED);
                    dado(50,20);
                    pintarDados(54,22,dado2J);
                }
                else{
                    puntosRondaJ1+=dado2J;
                }
            }
            if (dado1==true){
                setColor(WHITE);
                dado1J=dado(40,20);
                borrarDados(44,22);
                pintarDados(44,22,dado1J);
                if(dado1J==block1 || dado1J==block2){
                    dado1=false;
                    setColor(RED);
                    dado(40,20);
                    pintarDados(44,22,dado1J);
                }
                else{
                    puntosRondaJ1+=dado1J;
                }
            }


            anotadorPlay2(puntosJ1,puntosJ2,puntosRondaJ1,puntosRondaJ2,ronda,nameJ1,nameJ2);


            if(dado1==false && dado2 ==false && dado3 ==false && dado4==false && dado5==false){
                game_overP1=true;
                puntosRondaJ1=0;
                getch();

               for(int i=35;i<90;i++){
                    gotoxy(i,19);
                    printf(" ");
                    gotoxy(i,20);
                    printf(" ");
                    gotoxy(i,21);
                    printf(" ");
                    gotoxy(i,22);
                    printf(" ");
                    gotoxy(i,23);
                    printf(" ");
                    gotoxy(i,24);
                    printf(" ");
                    gotoxy(i,25);
                    printf(" ");
                    gotoxy(i,26);
                    printf(" ");
                }

                gotoxy(38,22);
                cout<<"JUGADOR 1 GAME OVER";
                getch();
                gotoxy(38,22);
                cout<<"                   ";
            }



            while(desicion!='1' && desicion != '2' && game_overP1==false){
                gotoxy(8,21);
                cout<<"DESEA SEGUIR JUGANDO?";
                gotoxy(8,22);
                cout<<"     1-SI   2- NO     ";
                desicion=getch();
                if(desicion=='2'){
                    finalizarJ1=true;
                    for(int i=35;i<90;i++){
                        gotoxy(i,19);
                        printf(" ");
                        gotoxy(i,20);
                        printf(" ");
                        gotoxy(i,21);
                        printf(" ");
                        gotoxy(i,22);
                        printf(" ");
                        gotoxy(i,23);
                        printf(" ");
                        gotoxy(i,24);
                        printf(" ");
                        gotoxy(i,25);
                        printf(" ");
                        gotoxy(i,26);
                        printf(" ");

                        gotoxy(8,21);
                        cout<<"                      ";
                        gotoxy(8,22);
                        cout<<"                      ";
                    }

                    gotoxy(43,21);
                    cout<<"JUGADOR 1";
                    gotoxy(38,22);
                    cout<<"<RONDA "<<ronda<<" FINALIZADA>";
                    getch();
                    puntosJ1+=puntosRondaJ1;
                    gotoxy(43,21);
                    cout<<"         ";
                    gotoxy(38,22);
                    cout<<"                              ";
                }
                else{
                    if(desicion=='1'){
                        gotoxy(8,21);
                        cout<<"                      ";
                        gotoxy(8,22);
                        cout<<"                      ";
                    }

                }
            }
            desicion='0';
        }






        if(game_overP2==false){
            establecerBloqueadores(block1,block2);
            anotadorPlay2(puntosJ1,puntosJ2,puntosRondaJ1,puntosRondaJ2,ronda,nameJ1,nameJ2);
        }


        while(game_overP2==false && finalizarJ2==false){

            while(press!='1'){

                setColor(BLACK);
                gotoxy(5,30);
                cout<<"<PRESIONE 1 PARA TIRAR DADOS>";
                press=getch();
                if (press=='1'){
                    gotoxy(5,30);
                    cout<<"                             ";
                }
            }
            press='0';

            if (dado5P2==true){
                setColor(WHITE);
                dado5J2=dado(80,28);
                borrarDados(84,30);
                pintarDados(84,30,dado5J2);
                if(dado5J2==block1 || dado5J2==block2){
                    dado5P2=false;
                    setColor(RED);
                    dado(80,28);
                    pintarDados(84,30,dado5J2);
                }
                else{
                    puntosRondaJ2+=dado5J2;
                }
            }
            if (dado4P2==true){
                setColor(WHITE);
                dado4J2=dado(70,28);
                borrarDados(74,30);
                pintarDados(74,30,dado4J2);
                if(dado4J2 == block1 || dado4J2==block2){
                    dado4P2=false;
                    setColor(RED);
                    dado(70,28);
                    pintarDados(74,30,dado4J2);
                }
                else{
                    puntosRondaJ2+=dado4J2;
                }
            }
            if (dado3P2==true){
                setColor(WHITE);
                dado3J2=dado(60,28);
                borrarDados(64,30);
                pintarDados(64,30,dado3J2);
                if(dado3J2 == block1 || dado3J2 == block2){
                    dado3P2=false;
                    setColor(RED);
                    dado(60,28);
                    pintarDados(64,30,dado3J2);
                }
                else{
                    puntosRondaJ2+=dado3J2;
                }
            }
            if (dado2P2==true){
                setColor(WHITE);
                dado2J2=dado(50,28);
                borrarDados(54,30);
                pintarDados(54,30,dado2J2);
                if(dado2J2==block1 || dado2J2 == block2){
                    dado2P2=false;
                    setColor(RED);
                    dado(50,28);
                    pintarDados(54,30,dado2J2);
                }
                else{
                    puntosRondaJ2+=dado2J2;
                }
            }
            if (dado1P2==true){
                setColor(WHITE);
                dado1J2=dado(40,28);
                borrarDados(44,30);
                pintarDados(44,30,dado1J2);
                if(dado1J2==block1 || dado1J2==block2){
                    dado1P2=false;
                    setColor(RED);
                    dado(40,28);
                    pintarDados(44,30,dado1J2);
                }
                else{
                    puntosRondaJ2+=dado1J2;
                }
            }


            anotadorPlay2(puntosJ1,puntosJ2,puntosRondaJ1,puntosRondaJ2,ronda,nameJ1,nameJ2);



            if(dado1P2==false && dado2P2 ==false && dado3P2 ==false && dado4P2==false && dado5P2==false){
                game_overP2=true;
                puntosRondaJ2=0;
                getch();
                for(int i=35;i<90;i++){
                        gotoxy(i,27);
                        printf(" ");
                        gotoxy(i,28);
                        printf(" ");
                        gotoxy(i,29);
                        printf(" ");
                        gotoxy(i,30);
                        printf(" ");
                        gotoxy(i,31);
                        printf(" ");
                        gotoxy(i,32);
                        printf(" ");
                        gotoxy(i,33);
                        printf(" ");
                        gotoxy(i,34);
                        printf(" ");
                }
                gotoxy(38,30);
                cout<<"JUGADOR 2 GAME OVER";
                getch();
            }

            while(desicion2!='1' && desicion2 != '2' && game_overP2==false){
                gotoxy(8,29);
                cout<<"DESEA SEGUIR JUGANDO?";
                gotoxy(8,30);
                cout<<"     1-SI   2- NO     ";
                desicion2=getch();
                if(desicion2=='2'){
                    finalizarJ2=true;
                    for(int i=35;i<90;i++){
                        gotoxy(i,27);
                        printf(" ");
                        gotoxy(i,28);
                        printf(" ");
                        gotoxy(i,29);
                        printf(" ");
                        gotoxy(i,30);
                        printf(" ");
                        gotoxy(i,31);
                        printf(" ");
                        gotoxy(i,32);
                        printf(" ");
                        gotoxy(i,33);
                        printf(" ");
                        gotoxy(i,34);
                        printf(" ");


                        gotoxy(8,29);
                        cout<<"                      ";
                        gotoxy(8,30);
                        cout<<"                      ";
                    }
                    gotoxy(43,29);
                    cout<<"JUGADOR 2";
                    gotoxy(38,30);
                    cout<<"<RONDA "<<ronda<<" FINALIZADA>";
                    getch();
                    puntosJ2+=puntosRondaJ2;
                    gotoxy(43,29);
                    cout<<"         ";
                    gotoxy(38,30);
                    cout<<"                              ";
                }
                else{
                    if(desicion2=='1'){
                        gotoxy(8,29);
                        cout<<"                      ";
                        gotoxy(8,30);
                        cout<<"                      ";
                    }

                }
            }
            desicion2='0';
        }
        ronda++;

        if(ronda>3){
            getch();
            system("cls");
            pintarBordes();
            setColor(WHITE);
            if(puntosJ1>puntosJ2){
                ganador=puntosJ1;
                gotoxy(35,19);
                cout<<"EL GANADOR ES "<<nameJ1;
            }
            else{
                if(puntosJ2>puntosJ1){
                    ganador=puntosJ2;
                    gotoxy(35,19);
                    cout<<"EL GANADOR ES "<<nameJ2;
                }
                else{
                    gotoxy(30,19);
                    cout<<"EL RESULTADO ES UN EMPATE, BIEN JUGADO!!!";
                }
            }
            getch();
            system("cls");

            if (ganador>puntajeMax){

                setColor(YELLOW);
                gotoxy(27,14);
                cout<<"Felicidades tu puntaje es el mas alto";

                setColor(WHITE);
                gotoxy(34,21);
                cout<<"Introduci tu nombre: ";
                puntajeMax=puntosJ1;

                setColor(BLACK);
                gotoxy(55,21);
                cin.getline(nombre,30);
            }
        }
    }
    system("cls");
    menu(puntajeMax,nombre);

}

void introducirNombres(char nameJ1[],char nameJ2[]){

    setColor(WHITE);
    gotoxy(35,8);
    cout<<"--INTRODUCIR NOMBRE--";

    gotoxy(10,18);
    cout<<"JUGADOR 1: ";
    setColor(BLACK);
    cin.getline(nameJ1,10);

    setColor(WHITE);
    gotoxy(10,21);
    cout<<"JUGADOR 2: ";
    setColor(BLACK);
    cin.getline(nameJ2,10);
}

void introducirNombrePlays1(char jugador[]){


    setColor(WHITE);
    gotoxy(35,8);
    cout<<"--INTRODUCIR NOMBRE--";


    gotoxy(10,20);
    cout<<"INTRODUCI TU NOMBRE: ";
    setColor(BLACK);
    cin.getline(jugador,10);
    gotoxy(10,18);
}

void establecerBloqueadores(int&block1, int&block2){
    char tecla;

    system("cls");
    tecla='8';
    pintarBordes();

    setColor(YELLOW);
    gotoxy(36,6);
    cout<<"--DADOS BLOQUEADORES--";

    setColor(BLACK);
    gotoxy(30,20);
    cout<<"1- Para recibir dados bloqueadores";

    while(tecla!='1'){
        if(kbhit){
            tecla=getch();
        }
    }
    setColor(WHITE);
    block1=dado(36,10);
    block2=dado(49,10);

    if(tecla=='1'){


        pintarDados(40,12,block1);
        pintarDados(53,12,block2);


        gotoxy(30,20);
        cout<<"                                   ";

        setColor(BLACK);
        gotoxy(31,18);
        cout<<"-DADOS BLOQUEADORES ESTABLECIDOS-";
        gotoxy(27,20);
        cout<<"<presiona cualquier tecla para continuar>";
        getch();


        setColor(LIGHTCYAN);
        gotoxy(31,18);
        cout<<"                                  ";
        gotoxy(27,20);
        cout<<"                                         ";

        for(int i=4;i<90;i++){
            gotoxy(i,16);
            printf("%c",205);
        }
        for(int i=5;i<16;i++){
            gotoxy(34,i);
            printf("%c",186);
            gotoxy(59,i);
            printf("%c",186);
        }

    }



}

void estadisticas(char tecla,int puntajeMax,char nombre[]){

pintarBordes();

setColor(WHITE);
gotoxy(34,7);
cout<<"-----MAYOR PUNTAJE-----";


setColor(YELLOW);
gotoxy(25,17);
cout<<nombre;

setColor(BLACK);
gotoxy(25,20);
cout<<" PUNTAJE: "<<puntajeMax;

setColor(WHITE);
gotoxy(34,34);
cout<<"0- para volver al menu";


while(tecla!='0'){
    if(kbhit){
        tecla=getch();
    }

    if(tecla=='0'){
        system("cls");
        menu(puntajeMax,nombre);
    }
}

}

int dado(int x,int y){
    int numero;


    for(int i=x;i<x+9;i++){
        gotoxy(i,y-1);
        printf("%c",205);
        gotoxy(i,y+5);
        printf("%c",205);
    }
    for(int i=y;i<y+5;i++){
        gotoxy(x,i);
        printf("%c",186);
        gotoxy(x+8,i);
        printf("%c",186);
    }

    gotoxy(x,y-1);
    printf("%c",201);
    gotoxy(x+8,y-1);
    printf("%c",187);
    gotoxy(x,y+5);
    printf("%c",200);
    gotoxy(x+8,y+5);
    printf("%c",188);


    numero=1+rand()%(6-1+1);

    return numero;
}

void pintarDados(int x, int y, int num){

    switch(num){

        case 1: gotoxy(x,y);cout<<"o" ;break;

        case 2: gotoxy(x-2,y+2);cout<<"o";
                gotoxy(x+2,y-2);cout<<"o";break;

        case 3:
                gotoxy(x-2,y+2);cout<<"o";
                gotoxy(x+2,y-2);cout<<"o";
                gotoxy(x,y);cout<<"o";break;

        case 4: gotoxy(x-2,y-2);cout<<"o";
                gotoxy(x-2,y+2);cout<<"o";
                gotoxy(x+2,y-2);cout<<"o";
                gotoxy(x+2,y+2);cout<<"o";break;

        case 5: gotoxy(x-2,y-2);cout<<"o";
                gotoxy(x-2,y+2);cout<<"o";
                gotoxy(x+2,y-2);cout<<"o";
                gotoxy(x,y);cout<<"o";
                gotoxy(x+2,y+2);cout<<"o"; ;break;

        case 6: gotoxy(x-2,y-2);cout<<"o";
                gotoxy(x-2,y);cout<<"o";
                gotoxy(x-2,y+2);cout<<"o";
                gotoxy(x+2,y-2);cout<<"o";
                gotoxy(x+2,y);cout<<"o";
                gotoxy(x+2,y+2);cout<<"o";break;

    }


}

void borrarDados(int x,int y){

    gotoxy(x-3,y-2);
    cout<<"      ";
    gotoxy(x-3,y-1);
    cout<<"      ";
    gotoxy(x-3,y);
    cout<<"      ";
    gotoxy(x-3,y+1);
    cout<<"      ";
    gotoxy(x-3,y+2);
    cout<<"      ";
}

void creditos(char tecla, int puntajeMax, char nombre[]){

    pintarBordes();

    setColor(WHITE);
    gotoxy(38,8);
    cout<<"--Creditos--";

    setColor(YELLOW);
    gotoxy(10,15);
    cout<<"Mete tu nombre aca padre";

    setColor(WHITE);
    gotoxy(34,34);
    cout<<"0- para volver al menu";


    while(tecla!='0'){
        if(kbhit){
            tecla=getch();
        }
    }
    if(tecla=='0'){
        system("cls");
        menu(puntajeMax,nombre);
    }
}

void menu(int puntajeMax,char nombre[]){
    char tecla='8';
    system("color 31");


    pintarBordes();
    setColor(BLACK);

    gotoxy(13,12);
    cout<<"(1)   1 Jugador";
    gotoxy(13,16);
    cout<<"(2)   2 jugadores";
    gotoxy(13,20);
    cout<<"(3)   Estadisticas";
    gotoxy(13,24);
    cout<<"(4)   Creditos";
    gotoxy(13,28);
    cout<<"(0)   Salir";

    while(tecla!='0'){
        if(kbhit){
            tecla=getch();
            if(tecla=='1' || tecla=='2'|| tecla=='3' || tecla== '4'){
                system("cls");
            }

            switch(tecla){
                case '1': plays1(puntajeMax,nombre);break;
                case '2': play2(puntajeMax,nombre);break;
                case '3': estadisticas(tecla,puntajeMax,nombre);break;
                case '4': creditos(tecla,puntajeMax,nombre);break;
            }
        }
    }
}

void pintarBordes(){

    setColor(LIGHTCYAN);

    for(int i=4;i<90;i++){
        gotoxy(i,4);
        printf("%c",205);
        gotoxy(i,36);
        printf("%c",205);
    }
    for(int i=5;i<36;i++){
        gotoxy(3,i);
        printf("%c",186);
        gotoxy(90,i);
        printf("%c",186);
    }
    gotoxy(3,4);
    printf("%c",201);
    gotoxy(90,4);
    printf("%c",187);
    gotoxy(3,36);
    printf("%c",200);
    gotoxy(90,36);
    printf("%c",188);
};
