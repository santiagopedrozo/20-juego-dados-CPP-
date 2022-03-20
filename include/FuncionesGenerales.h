#ifndef FUNCIONESGENERALES_H
#define FUNCIONESGENERALES_H

void mostrarVector(int v[], int tam);

void cargarVector(int v[], int tam);

void cargarAleatorio(int v[], int tam, int limite);///asigna valores aleatorios a cada al vector

int contarNumerosRepetidos(int v[], int tam , int numero);///cuenta la cantidad de veces que se repite un //n�mero en el vector

int maximoVector(int v[], int tam);///devuelve  la posici�n (primera) que ocupa el m�ximo en el vector

///funciones desarrolladas

int tirada(int *dados, int tiros, int sim);

int NumeroGeneradorPuntos(int puntos);

int tiradaPuntos(int nroPtos, int simulado);

int AsignacionPuntos(int cantidad, int apuesta);



#endif // FUNCIONESGENERALES_H
