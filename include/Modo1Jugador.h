#ifndef MODO1JUGADOR_H
#define MODO1JUGADOR_H

#include "funcionesGenerales.h"

void IngresoDatos1(char nombre[], int& ronda, int& simulado);

int tiradas(char nombre[], int apuesta, int simulado, int rondaActual);

int TiradaDePuntos(int PuntosRonda, int apuesta, int& Ptos0, int simulado);

int Descuento(int& RonPerd, int apuesta, int PuntosRonda);

void IngresoRonda(char nombre[], int rondaActual, int& apuesta);

void finalRonda(char nombre[], int PtosFinal, int rondas, int RonPerd, int Ptos0);

void modo1jugador(char Nombre[], int& Puntos);

#endif // MODO1JUGADOR_H
