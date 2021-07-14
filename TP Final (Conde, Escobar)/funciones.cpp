#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h> /* para el random dado */
#include"rlutil.h" /* graphic */
#include <cstring> /* copiar array nombre */

using namespace std;
#include"funciones.h" /* recuadro */
#include"ascii.h" /* dados */

int unJugador(char nombre[]);
int dosJugadores(char NombreJ1[], char NombreJ2[]);
void puntaje(int puntajeMax, char nombreMax[]);
int modoSimulacion(char Nombre[]);

int TiroDePuntajeSimulacion(int Apostar, int TotalDados){
    int v[5],i, valor, contador=0, apuesta_mult, agregarX=35;

    system("color 8F");
    recuadro(6, 2, 109, 27, 15, 4);

     switch (TotalDados){
        case 20: valor=1; break;
        case 21: valor=2; break;
        case 22: valor=3; break;
        case 23: valor=4; break;
        case 24: valor=5; break;
        default: valor=6; break;
    }

    for(i=0;i<5;i++){

        gotoxy(48,6);
        cout<< "<< Tiro de puntaje >>"<<endl;
        gotoxy(40,8);
        cout<< "<< El numero que se repetiria es el "<<valor<<" >> "<<endl;
        gotoxy(48,10);
        cout<< "Ingrese el dado >> "<<i+1<< " >> ";
        cin >> v[i];

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


    for(i=0;i<5;i++){
        if (v[i]==valor){
            contador++;
        }
    }

    if(contador!=0){
        apuesta_mult = Apostar * contador;
    }
    else{
        apuesta_mult = Apostar;
    }

    return apuesta_mult;

}

int tiroDePuntajeDosJugadores(int ApostarJ1, int ApostarJ2, int Puestos, int  TotalDados){
    int v[5],i, valor, contador=0, apuesta_mult, agregarX=35;

    system("color 8F");
    recuadro(6, 2, 109, 27, 15, 4);

 switch (TotalDados){
        case 20: valor=1; break;
        case 21: valor=2; break;
        case 22: valor=3; break;
        case 23: valor=4; break;
        case 24: valor=5; break;
        default: valor=6; break;
    }

    for(i=0;i<5;i++){
        v[i]= (rand()%6)+1;

        gotoxy(48,7);
        cout<< "<< Tiro de puntaje >>"<<endl;
        gotoxy(40,9);
        cout<< "<< El numero que se repetiria es el "<<valor<<" >> "<<endl;

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



    for(i=0;i<5;i++){
        if (v[i]==valor){
            contador++;
        }
    }

    if(Puestos%2==0){

            apuesta_mult = ApostarJ2 * contador;

    }
    else {
        apuesta_mult = ApostarJ1 * contador;
    }

    return apuesta_mult;
}

int tiroDePuntaje(int Total, int apuesta, int TotalApuesta){
    int v[5],i, valor, contador=0, apuesta_mult, agregarX=35;

    system("color 8F");
    recuadro(6, 2, 109, 27, 15, 4);
    switch (Total){
        case 20: valor=1;break;
        case 21: valor=2; break;
        case 22: valor=3; break;
        case 23: valor=4; break;
        case 24: valor=5; break;
        default: valor=6; break;
    }
    for(i=0;i<5;i++){

        gotoxy(49,7);
        cout<< "<< Tiro de puntaje >>"<<endl;
        gotoxy(40,9);
        cout<< "<< El numero que se repetiria es el "<<valor<<" >> "<<endl;

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



    for(i=0;i<5;i++){
        if (v[i]==valor){
            contador++;
        }
    }


        apuesta_mult = apuesta * contador;


    gotoxy(55,22);
    cout << "Ganaste >> " << apuesta_mult;
    gotoxy(40,25);
    system("pause");

    return apuesta_mult;
}

void Inicio(){
    recuadro(6, 2, 109, 27, 15, 4);

    recuadro(42, 9, 30, 4, 15, 4);
    gotoxy(45,11);
    cout<< "BIENVENIDO AL JUEGO DE 20";
    gotoxy(40,25);
    system("pause");
    system("cls");
}

int Menu(){
    int puntajeUnJugador,
    puntajeDosJugadores,
    puntajeSimulacion,
    puntajeMax=0;
    char input,
    nombre[15],
    Nombre[15],
    NombreJ1[15],
    NombreJ2[15],
    nombreMax[15]={ };

    while (true) {
        system("color 4F");
        recuadro(6, 2, 109, 27, 15, 4);

        recuadro(42, 9, 30, 4, 15, 4);
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
        gotoxy(47,19);
        cout << "5. SALIR";

        gotoxy(38,21);
        cout<< "Ingrese uno de los numeros para empezar :";
        input = getch();

        while(input!='1' && input!='2' && input!='3' && input!='4' && input!='5'){
                system("cls");
                system("color F4");
                recuadro(6, 2, 109, 27, 4, 15);
                gotoxy(52,10);
                cout << "<< Atencion >>";
                gotoxy(43,12);
                cout << "Ha ingresado un numero incorrecto";
                gotoxy(40,25);
                system("pause");
                Menu();
        }

        switch(input){
                case '1':
                    recuadro(6, 2, 109, 27, 15, 4);
                    recuadro(42, 9, 30, 4, 15, 4);
                    gotoxy(50,11);
                    cout << "Modo UN JUGADOR";
                    gotoxy(44,15);
                    cout<< "Ingrese su nombre >> ";
                    fflush(stdin);
                    cin.getline(nombre,15);
                    gotoxy(40,25);
                    system("pause");
                    system("cls");
                    puntajeUnJugador = unJugador(nombre);
                    if(puntajeUnJugador>puntajeMax){
                        strcpy(nombreMax,nombre);
                        puntajeMax=puntajeUnJugador;
                    }
                    break;
                case '2':
                    recuadro(6, 2, 109, 27, 15, 4);
                    recuadro(42, 9, 30, 4, 15, 4);
                    gotoxy(49,11);
                    cout << "Modo DOS JUGADORES";
                    gotoxy(39,15);
                    cout<< "Jugador 1, ingrese su nombre >> ";
                    fflush(stdin);
                    cin.getline(NombreJ1,15);
                    gotoxy(39,17);
                    cout<< "Jugador 2, ingrese su nombre >> ";
                    cin.getline(NombreJ2,15);
                    gotoxy(40,25);
                    system("pause");
                    system("cls");
                    puntajeDosJugadores = dosJugadores(NombreJ1, NombreJ2);
                    if (puntajeDosJugadores < 0) {
                        strcpy(nombreMax,NombreJ1);
                        puntajeDosJugadores = -puntajeDosJugadores;
                    }
                    else {
                        strcpy(nombreMax,NombreJ2);
                    }
                    if(puntajeDosJugadores>puntajeMax){
                        puntajeMax=puntajeDosJugadores;
                    }
                    break;
                case '3':
                    puntaje(puntajeMax, nombreMax);
                    break;
                case '4':
                    recuadro(6, 2, 109, 27, 15, 4);
                    recuadro(42, 9, 30, 4, 15, 4);
                    gotoxy(50,11);
                    cout << "Modo SIMULACION";
                    gotoxy(44,15);
                    cout<< "Ingrese el nombre >> ";
                    fflush(stdin);
                    cin.getline(Nombre,15);
                    gotoxy(40,25);
                    system("pause");
                    system("cls");
                    puntajeSimulacion = modoSimulacion(Nombre);
                    if(puntajeSimulacion>puntajeMax){
                        strcpy(nombreMax,Nombre);
                        puntajeMax=puntajeSimulacion;
                    }
                    break;
                case '5':
                    system("cls");
                    exit(EXIT_SUCCESS);
        }
    }

    return puntajeMax;
}

int unJugador(char nombre[]) {
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

    srand(time(NULL));

    system("color 4F");

    recuadro(6, 2, 109, 27, 15, 4);

    recuadro(42, 9, 30, 4, 15, 4);
    gotoxy(50,11);
    cout << "Modo UN JUGADOR";
    gotoxy(42,15);
    cout<< "Cantidad de rondas a jugar >> ";
    cin>> rondas;
    gotoxy(46,17);
    cout<< "Ingrese apuesta >> ";
    cin>> apuesta;
    gotoxy(40,25);
    system("pause");
    system("cls");

    recuadro(6, 2, 109, 27, 15, 4);

    for(vueltas=1;vueltas<=rondas;vueltas++){

        for(tirada=0;tirada<5;tirada++){

            recuadro(6, 2, 109, 27, 15, 4);
            gotoxy(54,5);
            cout<< "Jugador >> "<<nombre;
            gotoxy(55,7);
            cout<< "Ronda >> "<<vueltas;
            gotoxy(54,9);
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
            system("color 4F");
            recuadro(6, 2, 109, 27, 15, 4);

            recuadro(41, 9, 35, 4, 15, 4);
            gotoxy(45,11);
            cout<< "Obtuviste el tiro de puntaje";
            gotoxy(40,25);
            system("pause");
            system("cls");
            resultado = tiroDePuntaje(Total, apuesta, TotalApuesta);
            TotalApuesta+=resultado;
            system("cls");
        }
        else{
            recuadro(6, 2, 109, 27, 15, 4);

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
            system("color 4F");
            recuadro(6, 2, 109, 27, 15, 4);

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

    system("color 4F");
    recuadro(6, 2, 109, 27, 15, 4);

    recuadro(42, 9, 30, 4, 15, 4);
    gotoxy(52,11);
    cout<<"FIN DE JUEGO";
    gotoxy(44,15);
    cout<< "Gracias por jugar >> "<<nombre;
    gotoxy(46,17);
    cout<<"Puntaje acumulado >> "<<TotalApuesta;

    if(RondasSinPuntos!=0){
        gotoxy(40,19);
        cout<< "Cantidad de rondas sin puntos >> "<<RondasSinPuntos;
    }
    else {
        gotoxy(45,19);
        cout<< "No hubo rondas sin puntos";
    }

    if(RondasPerdidas!=0){
        gotoxy(39,21);
        cout<<"Cantidad de rondas con perdidas >> "<<RondasPerdidas;
    }
    else {
        gotoxy(44,21);
        cout<<"No hubo rondas sin perdidas";
    }

    gotoxy(40,25);
    system("pause");
    system("cls");

    return TotalApuesta;
}

int dosJugadores(char NombreJ1[], char NombreJ2[]) {
    int Rondas,
    Puestos,
    RondasPerdidasJ1=0,
    RondasPerdidasJ2=0,
    Max[5],
    RondasSinPuntosJ1=0,
    RondasSinPuntosJ2=0,
    TirarDados,
    totalDosJugadores,
    ApostarJ1,
    ApostarJ2,
    agregarX=35,
    MenosDados=5,
    Resultado=0,
    Tiradas,
    Dados=0,
    TotalDados=0,
    TotalApuestaJ1=0,
    TotalApuestaJ2=0,
    Vueltas=5;

    srand(time(NULL));

    system("color 4F");

    recuadro(6, 2, 109, 27, 15, 4);

    recuadro(42, 9, 30, 4, 15, 4);
    gotoxy(49,11);
    cout<< "Modo DOS JUGADORES";
    gotoxy(42,15);
    cout<< "Cantidad de rondas a jugar >> ";
    cin>> Rondas;
    gotoxy(43,17);
    cout<< "Ingrese apuesta de " << NombreJ1 << " >> ";
    cin>>  ApostarJ1;
    gotoxy(43,19);
    cout<< "Ingrese apuesta de " << NombreJ2 << " >> ";
    cin>> ApostarJ2;
    gotoxy(40,25);
    system("pause");
    system("cls");

    for(Vueltas=1;Vueltas<=Rondas;Vueltas++){

        for(Tiradas=0;Tiradas<5;Tiradas++){

            recuadro(6, 2, 109, 27, 15, 4);
            gotoxy(53,5);
            cout<< "Turno de >> "<<NombreJ1;
            gotoxy(55,7);
            cout<< "Ronda >> "<<Vueltas;
            gotoxy(54,9);
            cout<< "Tirada >>> "<<Tiradas+1;

            for(TirarDados=0;TirarDados<MenosDados;TirarDados++){

                Max[TirarDados]= (rand()%6)+1;

                if(Max[TirarDados]==1){
                    dado1(agregarX,12);
                    agregarX=agregarX+10;
                }
                if(Max[TirarDados]==2){
                    dado2(agregarX,12);
                    agregarX=agregarX+10;
                }
                if(Max[TirarDados]==3){
                    dado3(agregarX,12);
                    agregarX=agregarX+10;
                }
                if(Max[TirarDados]==4){
                    dado4(agregarX,12);
                    agregarX=agregarX+10;
                }
                if(Max[TirarDados]==5){
                    dado5(agregarX,12);
                    agregarX=agregarX+10;
                }
                if(Max[TirarDados]==6){
                    dado6(agregarX,12);
                    agregarX=agregarX+10;
                }

                if(Max[TirarDados]>Dados){
                    Dados=Max[TirarDados];
                }

                Sleep(250);
            }

            gotoxy(45,20);
            cout<< "Maximo dado de esta tirada >> "<<Dados;
            TotalDados+=Dados;
            gotoxy(50,22);
            cout << "Total de puntos >> "<< TotalDados;
            Dados=0;
            MenosDados=MenosDados-1;
            agregarX=35;
            gotoxy(40,25);
            system("pause");
            system("cls");
        }

        Puestos+=1;

        if(TotalDados>=20){

            system("color 4F");
            recuadro(6, 2, 109, 27, 15, 4);

            recuadro(41, 9, 35, 4, 15, 4);
            gotoxy(45,11);
            cout<< "Obtuviste el tiro de puntaje";
            gotoxy(40,25);
            system("pause");
            system("cls");
            Resultado=tiroDePuntajeDosJugadores(ApostarJ1, ApostarJ2, Puestos,  TotalDados);
            TotalApuestaJ1+=Resultado;
            gotoxy(48,22);
            cout<< NombreJ1 << " ganaste "<<Resultado << " puntos";
            gotoxy(40,25);
            system("pause");
            TotalDados=0;
            system("cls");
        }
        else{
            recuadro(6, 2, 109, 27, 15, 4);

            gotoxy(49,11);
            cout<< "Total de puntos >> "<< TotalDados;
            gotoxy(47,13);
            cout<< "<< No superaste los 20 >>";
            gotoxy(45,15);
            cout<< "Perdiste los "<<ApostarJ1<< " puntos apostados";
            RondasPerdidasJ1=RondasPerdidasJ1+1;
            TotalApuestaJ1=TotalApuestaJ1-ApostarJ1;
            ApostarJ1=0;
            TotalDados=0;
            gotoxy(40,25);
            system("pause");
            system("cls");
        }

        if(Resultado==0){
            RondasSinPuntosJ1=RondasSinPuntosJ1+1;
        }

        TotalDados=0;
        MenosDados=5;

        for(Tiradas=0;Tiradas<5;Tiradas++){

            recuadro(6, 2, 109, 27, 15, 4);
            gotoxy(53,5);
            cout<< "Turno de >> "<<NombreJ2;
            gotoxy(55,7);
            cout<< "Ronda >> "<<Vueltas;
            gotoxy(54,9);
            cout<< "Tirada >>> "<<Tiradas+1;

            for(TirarDados=0;TirarDados<MenosDados;TirarDados++){

                Max[TirarDados]= (rand()%6)+1;

                if(Max[TirarDados]==1){
                    dado1(agregarX,12);
                    agregarX=agregarX+10;
                }
                if(Max[TirarDados]==2){
                    dado2(agregarX,12);
                    agregarX=agregarX+10;
                }
                if(Max[TirarDados]==3){
                    dado3(agregarX,12);
                    agregarX=agregarX+10;
                }
                if(Max[TirarDados]==4){
                    dado4(agregarX,12);
                    agregarX=agregarX+10;
                }
                if(Max[TirarDados]==5){
                    dado5(agregarX,12);
                    agregarX=agregarX+10;
                }
                if(Max[TirarDados]==6){
                    dado6(agregarX,12);
                    agregarX=agregarX+10;
                }

                if(Max[TirarDados]>Dados){
                    Dados=Max[TirarDados];
                }

                Sleep(250);
            }

            gotoxy(45,20);
            cout<< "Maximo dado de esta tirada >> "<< Dados;
            TotalDados+=Dados;
            gotoxy(50,22);
            cout<< "Total de puntos >> "<< TotalDados;
            Dados=0;
            MenosDados=MenosDados-1;
            gotoxy(40,25);
            system("pause");
            system("cls");
            agregarX=35;
        }

       Puestos+=1;

        if(TotalDados>=20){
            system("color 4F");
            recuadro(6, 2, 109, 27, 15, 4);

            recuadro(41, 9, 35, 4, 15, 4);
            gotoxy(45,11);
            cout<< "Obtuviste el tiro de puntaje";
            gotoxy(40,25);
            system("pause");
            system("cls");
            Resultado=tiroDePuntajeDosJugadores(ApostarJ1, ApostarJ2, Puestos,  TotalDados);
            TotalApuestaJ2+=Resultado;
            gotoxy(48,22);
            cout<< NombreJ2 << " ganaste "<<Resultado << " puntos";
            TotalDados=0;
            gotoxy(40,25);
            system("pause");
            system("cls");
        }
        else{
            recuadro(6, 2, 109, 27, 15, 4);

            gotoxy(49,11);
            cout<< "Total de puntos >> "<< TotalDados;
            gotoxy(47,13);
            cout<< "<< No superaste los 20 >>";
            gotoxy(45,15);
            cout<< "Perdiste los "<<ApostarJ2<< " puntos apostados";
            RondasPerdidasJ2=RondasPerdidasJ2+1;
            TotalApuestaJ2=TotalApuestaJ2-ApostarJ2;
            ApostarJ2=0;
            TotalDados=0;
            gotoxy(40,25);
            system("pause");
            system("cls");
        }

        if(Resultado==0){
            RondasSinPuntosJ2=RondasSinPuntosJ2+1;
        }

        if(Vueltas != Rondas){
            system("color 4F");
            recuadro(6, 2, 109, 27, 15, 4);

            gotoxy(30,11);
            cout<< "Ingrese apuesta de " << NombreJ1 << " para la siguiente ronda >> ";
            cin>> ApostarJ1;
            gotoxy(30,13);
            cout<< "Ingrese apuesta de " << NombreJ2 << " para la siguiente ronda >> ";
            cin>> ApostarJ2;
            gotoxy(40,25);
            system("pause");
            system("cls");
        }

        MenosDados=5;
   }

    system("color 4F");
    recuadro(6, 2, 109, 27, 15, 4);

    recuadro(42, 9, 30, 4, 15, 4);
    gotoxy(52,11);
    cout<<"FIN DE JUEGO";

    gotoxy(44,15);
    cout<< "Gracias por jugar >> "<<NombreJ1;

    gotoxy(46,17);
    cout<<"Puntaje acumulado >> "<<TotalApuestaJ1;

     if(RondasSinPuntosJ1!=0){
        gotoxy(40,19);
        cout<< "Cantidad de rondas sin puntos >> "<<RondasSinPuntosJ1;
    }
    else {
        gotoxy(44,19);
        cout<< "No hubo rondas sin puntos";
    }

    if(RondasPerdidasJ1!=0){
        gotoxy(39,21);
        cout<<"Cantidad de rondas con perdidas >> "<<RondasPerdidasJ1;
    }
    else {
        gotoxy(43,21);
        cout<<"No hubo rondas sin perdidas";
    }

    gotoxy(40,25);
    system("pause");
    system("cls");

    recuadro(6, 2, 109, 27, 15, 4);

    recuadro(42, 9, 30, 4, 15, 4);
    gotoxy(52,11);
    cout<<"FIN DE JUEGO";

    gotoxy(44,15);
    cout<< "Gracias por jugar >> "<<NombreJ2;

    gotoxy(46,17);
    cout<<"Puntaje acumulado >> "<<TotalApuestaJ2;

     if(RondasSinPuntosJ2!=0){
        gotoxy(40,19);
        cout<< "Cantidad de rondas sin puntos >> "<<RondasSinPuntosJ2;
    }
    else {
        gotoxy(44,19);
        cout<< "No hubo rondas sin puntos";
    }

    if(RondasPerdidasJ2!=0){
        gotoxy(39,21);
        cout<<"Cantidad de rondas con perdidas >> "<<RondasPerdidasJ2;
    }
    else {
        gotoxy(43,21);
        cout<<"No hubo rondas sin perdidas";
    }

    gotoxy(40,25);
    system("pause");
    system("cls");

    recuadro(6, 2, 109, 27, 15, 4);

    if(TotalApuestaJ1==TotalApuestaJ2) {
        recuadro(42, 9, 30, 4, 15, 4);
        gotoxy(47,11);
        cout<< "Ha ocurrido un empate";
        gotoxy(48,16);
        cout<< "Ambos con >> "<<TotalApuestaJ1 << " puntos";
    }
    else if(TotalApuestaJ1>TotalApuestaJ2) {
        recuadro(42, 9, 30, 4, 15, 4);
        gotoxy(46,11);
        cout<< "El ganador fue >> "<<NombreJ1;
        gotoxy(49,16);
        cout<< "Con >> "<<TotalApuestaJ1 << " puntos";
        totalDosJugadores = -TotalApuestaJ1;
    }
    else{
        recuadro(42, 9, 30, 4, 15, 4);
        gotoxy(46,11);
        cout<< "El ganador fue >> "<<NombreJ2;
        gotoxy(49,16);
        cout<< "Con >> "<<TotalApuestaJ2 << " puntos";
        totalDosJugadores = TotalApuestaJ2;
    }

    gotoxy(40,25);
    system("pause");
    system("cls");

    return totalDosJugadores;
}

void puntaje(int puntajeMax, char nombreMax[]) {

    system("color 4F");

    recuadro(6, 2, 109, 27, 15, 4);

    recuadro(42, 9, 30, 4, 15, 4);
    gotoxy(50,11);
    cout << "Puntaje mas alto";
    gotoxy(48,15);
    cout<< "Lo obtuvo >> " << nombreMax;
    gotoxy(49,17);
    cout<< "Con >> "<< puntajeMax << " puntos";
    gotoxy(40,25);
    system("pause");
    system("cls");
}

int modoSimulacion(char Nombre[]) {
    int Apostar=0,
    Rondas,
    Vueltas=0,
    RondasPerdidas=0,
    Max[5],
    RondasSinPuntos=0,
    TirarDados,
    Resultado=0,
    Tiradas,
    Dados=0,
    TotalDados=0,
    agregarX=35,
    TotalApuesta=0,
    MenosDados=5;

    system("color 4F");

    recuadro(6, 2, 109, 27, 15, 4);

    recuadro(42, 9, 30, 4, 15, 4);
    gotoxy(50,11);
    cout<< "Modo SIMULACION";
    gotoxy(42,15);
    cout<< "Cantidad de rondas a jugar >> ";
    cin>> Rondas;
    gotoxy(46,17);
    cout<< "Ingrese apuesta >> ";
    cin>>  Apostar;
    gotoxy(40,25);
    system("pause");
    system("cls");

    recuadro(6, 2, 109, 27, 15, 4);

    for(Vueltas=1;Vueltas<=Rondas;Vueltas++){

        for(Tiradas=0;Tiradas<5;Tiradas++){

            recuadro(6, 2, 109, 27, 15, 4);
            gotoxy(52,5);
            cout<< "Jugador >> "<<Nombre;
            gotoxy(55,7);
            cout<< "Ronda >> "<<Vueltas;
            gotoxy(54,9);
            cout<< "Tirada >> "<<Tiradas+1;

            for(TirarDados=0;TirarDados<MenosDados;TirarDados++){

                gotoxy(47,11);
                cout<< "Ingrese el dado >> "<<TirarDados+1<< " >> ";
                cin>>Max[TirarDados];

                if(Max[TirarDados]==1){
                    dado1(agregarX,14);
                    agregarX=agregarX+10;
                }
                if(Max[TirarDados]==2){
                    dado2(agregarX,14);
                    agregarX=agregarX+10;
                }
                if(Max[TirarDados]==3){
                    dado3(agregarX,14);
                    agregarX=agregarX+10;
                }
                if(Max[TirarDados]==4){
                    dado4(agregarX,14);
                    agregarX=agregarX+10;
                }
                if(Max[TirarDados]==5){
                    dado5(agregarX,14);
                    agregarX=agregarX+10;
                }
                if(Max[TirarDados]==6){
                    dado6(agregarX,14);
                    agregarX=agregarX+10;
                }

                if(Max[TirarDados]>Dados){
                Dados=Max[TirarDados];
                }

                Sleep(250);
            }

            gotoxy(45,20);
            cout<< "Maximo dado de esta tirada >> "<<Dados;
            TotalDados+=Dados;
            gotoxy(50,22);
            cout<< "Total de puntos >> "<<   TotalDados <<endl;
            Dados=0;
            MenosDados=MenosDados-1;
            gotoxy(40,25);
            system("pause");
            system("cls");
            agregarX=35;
        }

        MenosDados=5;

        if(TotalDados>=20){
            system("color 4F");
            recuadro(6, 2, 109, 27, 15, 4);

            recuadro(41, 9, 35, 4, 15, 4);
            gotoxy(45,11);
            cout<< "Obtuviste el tiro de puntaje";
            gotoxy(40,25);
            system("pause");
            system("cls");
            Resultado=TiroDePuntajeSimulacion(Apostar, TotalDados);
            TotalApuesta+=Resultado;
            gotoxy(48,22);
            cout<< Nombre << " ganaste >> "<<Resultado<< " puntos";
            TotalDados=0;
            gotoxy(40,25);
            system("pause");
            system("cls");
        }
        else{
            recuadro(6, 2, 109, 27, 15, 4);
            gotoxy(49,11);
            cout<< "Total de puntos >> "<< TotalDados;
            gotoxy(47,13);
            cout<< "<< No superaste los 20 >>";
            gotoxy(46,15);
            cout<< "Perdiste lo apostado >> "<<Apostar;
            RondasPerdidas=RondasPerdidas+1;
            TotalApuesta=TotalApuesta-Apostar;
            Apostar=0;
            TotalDados=0;
            gotoxy(40,25);
            system("pause");
        }

        if(Resultado==0){
            RondasSinPuntos=RondasSinPuntos+1;
        }

        if(Vueltas!=Rondas){
            system("color 4F");
            recuadro(6, 2, 109, 27, 15, 4);

            gotoxy(40,11);
            cout<< "Apuesta para la siguiente ronda >> ";
            cin>> Apostar;
            gotoxy(40,25);
            system("pause");
            system("cls");
        }
    }

    system("cls");

    system("color 4F");
    recuadro(6, 2, 109, 27, 15, 4);

    recuadro(42, 9, 30, 4, 15, 4);
    gotoxy(52,11);
    cout<<"FIN DE JUEGO";
    gotoxy(44,15);
    cout<< "Gracias por jugar >> "<<Nombre;
    gotoxy(46,17);
    cout<<"Puntaje acumulado >> "<<TotalApuesta;

    if(RondasSinPuntos!=0){
        gotoxy(44,19);
        cout<< "Cantidad de rondas sin puntos >> "<<RondasSinPuntos;
    }
    else {
        gotoxy(45,19);
        cout<< "No hubo rondas sin puntos";
    }

    if(RondasPerdidas!=0){
        gotoxy(43,21);
        cout<<"Cantidad de rondas con perdidas >> "<<RondasPerdidas;
    }
    else{
        gotoxy(44,21);
        cout<<"No hubo rondas sin perdidas";
    }

    gotoxy(40,25);
    system("pause");
    system("cls");

    return TotalApuesta;
}


