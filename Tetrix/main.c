//     PROYECTO - ESTRUCTURA DE DATOS     //
//  Integrantes:                          //
//          > Jose Munioz                 //
//          > Kevin Santana               //
//          > Sergio Balarezo             //
//          > Yelena Urinia               //
//          > Cristopher Vanegas          //

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdbool.h>

#define FILAS 18
#define COLUMNAS 25

int fondo[FILAS][COLUMNAS];

void gotoxy(int x, int y)
{
    HANDLE hCon;
    hCon=GetStdHandle(STD_OUTPUT_HANDLE);

    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

void imprimirFichas();
//void generadorFichas();
void imprimirTabla();

int shape[7][4][4] = {
            {{0,1,0,0},{0,1,0,0},{0,1,0,0},{0,1,0,0}},
            {{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}},
            {{0,0,0,0},{0,1,0,0},{1,1,1,0},{0,0,0,0}},
            {{0,0,1,0},{0,1,1,0},{0,1,0,0},{0,0,0,0}},
            {{0,1,0,0},{0,1,1,0},{0,0,1,0},{0,0,0,0}},
            {{0,0,0,0},{0,1,0,0},{0,1,1,1},{0,0,0,0}},
            {{0,0,0,0},{0,1,1,1},{0,1,0,0},{0,0,0,0}}
    };

void imprimirTabla()
{
    int i, j;
    for (i=0; i<FILAS; i++)
    {
        for (j=0; j<COLUMNAS; j++)
        {
            gotoxy (20+i, 10+j);
            printf("0");
        }
    }
}

void imprimirFicha()
{
    int l, m, n, ii;
    int max = 6;
    int num = (rand() % max);
    int x = FILAS / 2 - 1;
    int y = COLUMNAS / 2 - 1;

    // Imprimir la ficha inicial
    for (n = 0; n < 4; n++) {
        for (ii = 0; ii < 4; ii++) {
            if (shape[num][n][ii]) {
                gotoxy(20 + x + n, 10 + y + ii);
                printf("1");
            }
        }
    }

    bool fichaEnMovimiento = true;
    while (fichaEnMovimiento) {
        // Esperar un tiempo antes de mover la ficha
        Sleep(500);

        // Borrar la ficha actual
        for (n = 0; n < 4; n++) {
            for (ii = 0; ii < 4; ii++) {
                if (shape[num][n][ii]) {
                    gotoxy(20 + x + n, 10 + y + ii);
                    printf("0");
                }
            }
        }

        // Mover la ficha hacia abajo
        if (y + 4 < COLUMNAS) {
            bool puedeMoverse = true;
            for (n = 0; n < 4; n++) {
                for (ii = 0; ii < 4; ii++) {
                    if (shape[num][n][ii]) {
                        if (fondo[x + n][y + ii + 1]) {
                            puedeMoverse = false;
                        }
                    }
                }
            }
            if (puedeMoverse) {
                y++;
            } else {
                // Agregar la ficha al fondo
                for (n = 0; n < 4; n++) {
                    for (ii = 0; ii < 4; ii++) {
                        if (shape[num][n][ii]) {
                            fondo[x + n][y + ii] = 1;
                        }
                    }
                }
                fichaEnMovimiento = false;
            }
        } else {
            fichaEnMovimiento = false;
        }

        // Imprimir la ficha en la nueva posición
        for (n = 0; n < 4; n++) {
            for (ii = 0; ii < 4; ii++) {
                if (shape[num][n][ii]) {
                    gotoxy(20 + x + n, 10 + y + ii);
                    printf("1");
                }
            }
        }
    }
}

int main()
{
    // Configura la semilla del generador de números aleatorios
    srand(time(NULL));
    imprimirTabla();
    bool terminarJuego= true;
    while (terminarJuego){
        imprimirFicha();
    }
    gotoxy(50,1);
    return 0;
}
