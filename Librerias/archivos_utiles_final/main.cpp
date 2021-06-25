#include<iostream>
using namespace std;
#include "funciones.h"

void cargarVector(int, float*);
void menuCalculos(int, float*);
float sumarVector(int, float *);
float promediarVector(int, float *);

int main(void){
    char opc;
    const int vTAM = 5;
    float v[vTAM];
    bool vectorCargado = false;

    while(true){
        textcolor(0,0);
        clrscr();
        recuadro(8, 1, 30, 16, cAMARILLO, cGRIS);
        textcolor(cAMARILLO, cGRIS);
        gotoxy(10,3);
        cout << "A - Cargar vector";
        gotoxy(10,4);
        cout << "B - Calculos con el vector";
        gotoxy(10, 5);
        cout << "S - Salir";
        gotoxy(10, 7);
        cout << "Ingresar opcion: ";
        cin >> opc;
        switch(opc){
            case 'A':
            case 'a':
                cargarVector(vTAM, v);
                vectorCargado=true;
                pause();
            break;
            case 'B':
            case 'b':
                if(vectorCargado){
                    menuCalculos(vTAM, v);
                }
                else{
                    gotoxy(9, 15);
                    textcolor(cROJO_CLARO);
                    cout << "Debe cargar valores al vector";
                    pause();
                }
            break;
            case 'S':
            case 's':
                return 0;
            break;
            default:
                gotoxy(12, 15);
                textcolor(cROJO_CLARO);
                cout << "Opcion de menu invalida";
                pause();
            break;
        }
    }
    pause();
}

void menuCalculos(int tam, float *v){
    char opc;
    clrscr();
    while(true){
        textcolor(0,0);
        clrscr();
        recuadro(8, 1, 30, 16, cVERDE_CLARO, cGRIS);
        textcolor(cVERDE_CLARO, cGRIS);
        gotoxy(10,3);
        cout << "A - Sumar vector";
        gotoxy(10,4);
        cout << "B - Promediar vector";
        gotoxy(10, 5);
        cout << "S - Volver al menu anterior";
        gotoxy(10, 7);
        cout << "Ingresar opcion: ";
        cin >> opc;
        switch(opc){
            case 'A':
            case 'a':
                gotoxy(10, 9);
                cout << "SUMA: " << sumarVector(tam, v);
                pause();
            break;
            case 'B':
            case 'b':
                gotoxy(10, 9);
                cout << "PROMEDIO: " << promediarVector(tam, v);
                pause();
            break;
            case 'S':
            case 's':
                return;
            break;
            default:
                gotoxy(12, 15);
                textcolor(cROJO_CLARO);
                cout << "Opcion de menu invalida";
                pause();
            break;
        }
    }
}
float sumarVector(int tam, float *v){
    int i;
    float suma=0.0;
    for(i=0; i<tam; i++){
        suma+=v[i];
    }
    return suma;
}
float promediarVector(int tam, float *v){
    return sumarVector(tam, v) / tam;
}
void cargarVector(int tam, float *v){
    int i;
    textcolor(cBLANCO);
    clrscr();
    for(i=0; i<tam; i++){
        cout << "Ingresar valor: ";
        cin >> v[i];
    }
}

