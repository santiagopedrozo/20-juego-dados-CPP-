#include "FuncionesGenerales.h"
#include "FuncionesVisuales.h"

#include"rlutil.h"
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

/// Desarrollo de funciones / Definiciones

void cargarAleatorio(int v[], int tam, int limite){
  int i;
  srand(time(NULL));
  for( i=0; i<tam; i++ ){
        v[i]=(rand()%limite)+1;
  }
}

int maximoVector(int v[], int tam){
    int i, posMax=0;
    for(i=1;i<tam;i++){
        if(v[i]>v[posMax]) {
                posMax=i;
        }
    }
    return posMax;
}


void mostrarVector(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<v[i]<<"\n";
    }
    cout<<endl;
}

int contarNumerosRepetidos(int v[], int numero, int tam){
    int i, cant=0;
    for(i=0;i<tam;i++){
        if(v[i]==numero) cant++;
        }
    return cant;
}

void cargarVector(int v[], int tam){
    int i, y=14;
    for(i=0;i<tam;i++){
        gotoxy(46, y);
        cout<<"INGRESE "<<tam<<" NUMEROS: ";
        cin>>v[i];
    }
}

int tirada(int *dados, int tiros, int sim){
        int maxi;

        if(sim==0){
            cargarAleatorio(dados, tiros, 6);
        }
        else{
            cargarVector(dados, tiros);
        }

        return maxi=maximoVector(dados, tiros);

}

int NumeroGeneradorPuntos(int puntos){
     int numero;
     numero=puntos-19;
     if(numero>6) numero=6;

     return numero;

}

int tiradaPuntos(int nroPtos, int simulado){
    int repetido, dados[5];
    if(simulado==0) cargarAleatorio(dados, 5, 6);
    else cargarVector(dados, 5);

    MostrarDados(5, dados, 20);
    repetido=contarNumerosRepetidos(dados, nroPtos, 5);

    return repetido;

}

int AsignacionPuntos(int cantidad, int apuesta){
    int Ronda;

    if(cantidad>0)
    {
         Ronda=cantidad*apuesta;
         gotoxy(45, 17);
         cout<<"La apuesta se multiplico por: "<<cantidad<<endl;
    }
    else if(cantidad==0)
    {
        gotoxy(44, 17);
        cout<<"los puntos fueron reiniciados a 0."<<endl;
        Ronda=0;
    }

    return Ronda;
}
