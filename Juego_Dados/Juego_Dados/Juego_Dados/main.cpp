#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include"funciones.h"
#include"rlutil.h"

using namespace std;
using namespace rlutil;



int main(){
int puntajeMax;
char nombre[30]={"Empty"};

system("color F1");

hidecursor();

intro();

menu(puntajeMax,nombre);

return 0;
}
