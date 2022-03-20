#include <iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>
using namespace std;
#include "rlutil.h"
#include"FuncionesVisuales.h"
#include "funcionesGenerales.h"
#include "Modo1jugador.h"
#include "Maximo.h"


int main(){

    rlutil::setConsoleTitle("20 - pedrozo");
    system("color BD");
    rlutil::setColor(rlutil::WHITE);

    int opc, PuntosJuego, MaxPuntos=-99999;
    char Jugador[30], MaxJugador[30];

	while(true) {
        system("cls");

        recuadroSimple(10,5,99,21);

        gotoxy(45,13);
		cout<<"1.Juego nuevo modo un jugador."<<endl;
		gotoxy(45,15);
		cout<<"2.Tabla de posiciones."<<endl;
		gotoxy(45,17);
		cout<<"0.Fin del programa."<<endl;

		gotoxy(56,23);
		cout<<(char)175<<(char)175;
		gotoxy(59,23);
		cout<<(char)174<<(char)174;

		gotoxy(58,23);
		cin>>opc;
		system("cls");

		switch(opc){

            case 0:
                Fin();
                return 0;
                break;

            case 1:
                modo1jugador(Jugador, PuntosJuego);
                PrimerJugador(PuntosJuego, Jugador, MaxPuntos, MaxJugador);

                break;
            case 2:
                Maximo(MaxPuntos, MaxJugador);
                break;
        }

    }

}
