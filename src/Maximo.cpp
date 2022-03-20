#include "Maximo.h"
#include "rlutil.h"
#include<cstring>
#include<cstdlib>
#include<iostream>
#include "FuncionesVisuales.h"
void PrimerJugador(int PuntosJuego, char Jugador[], int& MaxPuntos, char MaxJugador[]){

    if(PuntosJuego > MaxPuntos){
        MaxPuntos = PuntosJuego;
        strcpy(MaxJugador, Jugador);
    }

}

void Maximo(int& MaxPuntos, char MaxJugador[]){
    system("cls");
    recuadroSimple(23, 8, 75, 12);

    gotoxy(40, 13);
    std::cout<<"EL JUGADOR "<<MaxJugador<<" ES TOP 1 CON "<<MaxPuntos<<" PUNTOS!"<<std::endl;

    pausacls();

}


