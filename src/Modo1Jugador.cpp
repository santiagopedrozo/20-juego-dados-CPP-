#include "Modo1Jugador.h"
#include "FuncionesVisuales.h"
#include<iostream>
using namespace std;

#include "rlutil.h"

void IngresoDatos1(char nombre[], int& ronda, int& simulado){
        recuadroSimple(3,2,114,27);

        gotoxy(52, 4);
        cout<<"UN JUGADOR."<<endl;

        recuadroSimple(29,5,61, 2);
        gotoxy(45,6);
        cout<<"ingrese los siguientes datos.";

        recuadroSimple(34,8,51, 2);             ///NOMBRE CON INGRESO
        gotoxy(51,9);
        cout<<"NOMBRE: ";
        gotoxy(59, 9);
        cin>>nombre;

        recuadroSimple(34,11,51, 2);            ///RONDAS
        gotoxy(46,12);
        cout<<"RONDAS QUE DESEA JUGAR: ";
        gotoxy(69, 12);
        cin>>ronda;

        recuadroSimple(34,14,51, 2);
        gotoxy(36, 15);
        cout<<"¿DESEA JUGAR MODO SIMULADO? PRESIONE 1, SINO 0."<<endl;
        gotoxy(84,15);
        cin>>simulado;

        gotoxy(51,21);
        cout<<"muy buena suerte!!";
        pausacls();
}

int tiradas(char nombre[], int apuesta, int simulado, int rondaActual){
    int tiros=5, sumaronda=0, dados[5], MaxIndice;

    for(int j=1; j<=5; j++)
    {
        system("cls");
        recuadroSimple(3,2,114, 27);        //recuadro exterior
        recuadroSimple(5, 6, 110, 2);       //recuadro de informacion

        gotoxy(55, 4);
        cout<<"TIRADAS!."<<endl;
        gotoxy(12, 7);
        cout<<"APUESTA: "<<apuesta<<endl;
        gotoxy(100, 7);
        cout<<"RONDA: "<<rondaActual<<endl;
        gotoxy(38, 7);
        cout<<"TURNO DE "<<nombre;

        MaxIndice=tirada(dados, tiros, simulado);
        MostrarDados(tiros, dados, 20);
        tiros--;

        recuadroSimple(50,16,18,2);         //recuadro de maximo
        gotoxy(55, 17);
        dado(54, 19, 11, 4, dados[MaxIndice]);
        gotoxy(55, 17);
        cout<<"MAXIMO: "<<dados[MaxIndice];

        sumaronda+=dados[MaxIndice];
        gotoxy(67, 7);
        cout<<"SUMA ACUMULADA: "<<sumaronda<<endl;
        pausacls();

    }

    return sumaronda;

}

int TiradaDePuntos(int PuntosRonda, int apuesta, int& Ptos0, int simulado){
    int NroGptos, cant;

    system("cls");
    recuadroSimple(3,2,114, 27);
    gotoxy(51, 15);
    cout<<"TIRADA DE PUNTOS."<<endl;
    pausacls();
    system("cls");

    recuadroSimple(3,2,114, 27);
    recuadroSimple(5, 6, 110, 2);

    if(simulado==0) NroGptos=NumeroGeneradorPuntos(PuntosRonda);
    else{
        gotoxy(42, 3);
        cout<<"ingresar numero generador de puntos: ";
        cin>>NroGptos;
    }


    gotoxy(46, 4);
    cout<<"Numero generador de puntos: "<<NroGptos<<endl;

    cant=tiradaPuntos(NroGptos, simulado);

    gotoxy(30, 7);
    cout<<"cantidad de veces que se presento el numero generador de puntos: "<<cant<<endl;

    gotoxy(44, 19);
    gotoxy(44, 19);
    cout<<"-obtuvo: "<<AsignacionPuntos(cant, apuesta)<<" en esta ronda";
    if(AsignacionPuntos(cant, apuesta) == 0) Ptos0++;

    pausacls();

    return AsignacionPuntos(cant, apuesta);
}

int Descuento(int& RonPerd, int apuesta, int PuntosRonda){
    system("cls");
    recuadroSimple(3,2,114, 27);

    gotoxy(48, 15);
    cout<<"la apuesta fue descontada: "<<apuesta<<endl;

    RonPerd++;
    pausacls();

    return apuesta * -1;
}



void IngresoRonda(char nombre[], int rondaActual, int& apuesta){

    system("cls");
    recuadroSimple(3,2,114, 27);
    recuadroSimple(5, 6, 110, 2);

    gotoxy(52, 4);
    cout<<"UN JUGADOR."<<endl;
    gotoxy(105, 7);
    cout<<"ronda "<<rondaActual<<endl;
    gotoxy(9, 7);
    cout<<nombre<<endl;
    gotoxy(45, 7);
    cout<<"cuanto desea apostar: "<<endl;
    gotoxy(69, 7);
    cin>>apuesta;


}

void finalRonda(char nombre[], int PtosFinal, int rondas, int RonPerd, int Ptos0){
    system("cls");
    recuadroSimple(23, 8, 75, 12);

    gotoxy(26, 11);
    cout<<"-el jugador "<<nombre<<" obtuvo un total de "<<PtosFinal<<" acumulados. ";
    cout<<"durante "<<rondas<<" rondas"<<endl;
    gotoxy(26, 14);
    cout<<"-obtuvo "<<RonPerd<<" rondas con perdida de puntos."<<endl;
    gotoxy(26, 17);
    cout<<"-obtuvo "<<Ptos0<<" rondas sin puntos"<<endl;

    pausacls();

}


void modo1jugador(char Nombre[], int& Puntos){
    int Ronda, simulado, apuesta,  SumaRonda, PuntosRonda;
    int RonPerd=0, Ptos0=0;
    Puntos=0;
    IngresoDatos1(Nombre, Ronda, simulado);

    for(int i=1; i<=Ronda; i++){

        IngresoRonda(Nombre, i, apuesta);
        SumaRonda=tiradas(Nombre, apuesta, simulado, i);

        if(SumaRonda>19){
            PuntosRonda=TiradaDePuntos(SumaRonda, apuesta, Ptos0, simulado);
        }
        else{
            PuntosRonda=Descuento(RonPerd, apuesta, SumaRonda);
        }

        Puntos+=PuntosRonda;
    }

    finalRonda(Nombre, Puntos, Ronda, RonPerd, Ptos0);

}
