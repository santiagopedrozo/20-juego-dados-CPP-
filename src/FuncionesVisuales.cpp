#include "FuncionesVisuales.h"
#include<iostream>
using namespace std;

#include "rlutil.h"

void dado(int x, int y, int ancho, int alto, int cant){
        int i, j, t;

        //superior
        gotoxy(x,y);
        for(i=0; i<ancho; i++){
            if(i==0) cout<<(char)201;
            else{
                if(i==ancho-1) cout<<(char)187;
                else{
                    gotoxy(i+x,y);
                    cout<<(char)205;
                }
            }
        }

        //laterales
        for(j=1; j<=alto; j++){
            gotoxy(x, j+y);
                cout<<(char)186;
            gotoxy((x-1)+ancho, j+y);
                cout<<(char)186;
        }

        //inferior
        gotoxy(x, y+alto);
        for(t=0; t<ancho; t++){
            if(t==0){
                cout<<(char)200;
            }
            else{
                if(t==ancho-1){
                    cout<<(char)188;
                }
                else{
                    gotoxy(t+x,y+alto);
                    cout<<(char)205;
                }
            }
        }

        //NUMERO DE DADOS
        switch(cant){
            case 0:
                break;

            case 1:
                gotoxy(x+5, y+2);
                    cout<<(char)254;
                break;

            case 2:
                gotoxy(x+3, y+1);
                    cout<<(char)254;
                gotoxy(x+7, y+3);
                    cout<<(char)254;
                break;

            case 3:
                gotoxy(x+3, y+1);
                    cout<<(char)254;
                gotoxy(x+5, y+2);
                    cout<<(char)254;
                gotoxy(x+7, y+3);
                    cout<<(char)254;
                break;

            case 4:
                gotoxy(x+3, y+1);
                    cout<<(char)254;
                gotoxy(x+7, y+3);
                    cout<<(char)254;
                gotoxy(x+7, y+1);
                    cout<<(char)254;
                gotoxy(x+3, y+3);
                    cout<<(char)254;
                break;

            case 5:
                gotoxy(x+3, y+1);
                    cout<<(char)254;
                gotoxy(x+5, y+2);
                    cout<<(char)254;
                gotoxy(x+7, y+3);
                    cout<<(char)254;
                gotoxy(x+7, y+1);
                    cout<<(char)254;
                gotoxy(x+3, y+3);
                    cout<<(char)254;
                break;

            case 6:
                gotoxy(x+3, y+1);
                    cout<<(char)254;
                gotoxy(x+7, y+3);
                    cout<<(char)254;
                gotoxy(x+3, y+2);
                    cout<<(char)254;
                gotoxy(x+7, y+1);
                    cout<<(char)254;
                gotoxy(x+3, y+3);
                    cout<<(char)254;
                gotoxy(x+7, y+2);
                    cout<<(char)254;
                break;

        }

}

void MostrarDados(int tiros, int dados[], int x){
    for(int q=0; q<tiros; q++){
        dado(x, 9, 11, 4, dados[q]);
        x+=17;
    }

}



void recuadroSimple(int iniX, int iniY, int ancho, int alto){
    int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            gotoxy(i, j);
            //Arriba izquierda
            if(i==iniX && j==iniY){
                cout << (char) 201;
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY){
                cout << (char) 187;
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                cout << (char) 200;
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
                cout << (char) 188;
            }
            //Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto){
                cout << (char) 205;
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                cout << (char) 186;
            }

        }
    }
}

void LogoUTN(){

            printf("XXXXXXX         XXXXXX         XXXXXXX");

            printf("\nXXXXXXXX        XXXXXX        XXXXXXXX");

            printf("\nXXXXXXXXX       XXXXXX       XXXXXXXXX");

            printf("\nXXXXXXXXXX      XXXXXX      XXXXXXXXXX");

            printf("\nXXXXXXXXXXXX    XXXXXX    XXXXXXXXXXXX");

            printf("\n    XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX    ");

            printf("\n     XXXXXXXXXXXXXXXXXXXXXXXXXXXX     ");

            printf("\n        XXXXXXXXXXXXXXXXXXXXXX        ");

            printf("\n            XXXXXXXXXXXXXX            ");

            printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");

            printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");

            printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");

            printf("\n            XXXXXXXXXXXXXX            ");

            printf("\n        XXXXXXXXXXXXXXXXXXXXXX        ");

            printf("\n      XXXXXXXXXXXXXXXXXXXXXXXXXXX     ");

            printf("\n    XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX   ");

            printf("\n  XXXXXXXXXX    XXXXXX    XXXXXXXXXX  ");

            printf("\n XXXXXXXXX      XXXXXX      XXXXXXXXX ");

            printf("\nXXXXXXXXX       XXXXXX       XXXXXXXXX");

            printf("\nXXXXXXXX        XXXXXX        XXXXXXXX");

            printf("\nXXXXXXX         XXXXXX         XXXXXXX");

}

void pausacls(){
    gotoxy(35, 25);
    cout<<"Ingrese cualquier tecla para continuar al siguiente panel.";
    gotoxy(43, 26);
    system("pause");

}

void Fin(){
    LogoUTN();
    gotoxy(50, 10);
    cout<<"¡GRACIAS POR PROBAR NUESTRO PROYECTO <3!"<<endl;
    gotoxy(60, 20);

}
