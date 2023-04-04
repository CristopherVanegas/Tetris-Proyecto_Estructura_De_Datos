//  Animacion de la pieza cayendo  //

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>


typedef struct
{
    char car;
    int posX, posY;
} Pieza;



char tablero[9][9];


void gotoxy(int x,int y);
void inicializarTablero();
void animacion( Pieza pieza);
void inicializoForma();
void continuar();


int main()
{
    srand(time(NULL));
    printf("Experimento 3 - Pieza cayendo!\n");
    inicializarTablero();
    continuar();

    do
    {
        inicializoForma();
    }
    while (getch() != 'n');

    printf("\n\n\n\n");

    return 0;
}

void animacion( Pieza pieza)
{
    // system("cls");

    /*  Bucle de la animacion  */
    for (int k = 0; k < 9; k++)
    {
        /*
        for (int i = 3; i >= 0; i--)
        {
            for (int j = 0; j < 2; j++)
            {
                gotoxy(tableroForma[i][j].posX, tableroForma[i][j].posY);
                printf("%c", tableroForma[i][j].car);
                tableroForma[i][j].posY++;
            }

            Sleep(250);
        }
        */

        /*
        gotoxy(tableroForma[3][0].posX, tableroForma[3][0].posY);
        printf("%c", tableroForma[3][0].car);
        gotoxy(tableroForma[3][1].posX, tableroForma[3][1].posY);
        printf("%c", tableroForma[3][1].car);
        */

        // tableroForma[3][1].posX++;   // se modifica solo si presionan 'a' o 'd'
        gotoxy(pieza.posX, pieza.posY);
        printf("%c", pieza.car);
        tablero[pieza.posY][pieza.posX] = pieza.car;    // asigna en el tablero el caracter

        Sleep(250);
        gotoxy(pieza.posX, pieza.posY);
        if (k != 8) printf(" ");
        if (tablero[pieza.posY][pieza.posX+1] == ' ') pieza.posY++;
        else break;
    }
}

void inicializoForma()
{
    //  inicializa el cuadrado  //
    Pieza tableroForma[4][2], pieza;

    pieza.car = '\xFE';
    pieza.posX = rand() % 9;
    pieza.posY = 0;

    tableroForma[3][0] = pieza;

    /*
    //  inicializo los demas "nodos"  //
    //  nodo [3][1]  //
    tableroForma[3][1].posX = tableroForma[3][0].posX+1;
    tableroForma[3][1].posY = tableroForma[3][0].posY;
    tableroForma[3][1].car = pieza.car;

    //  nodo [2][0]  //
    tableroForma[2][0].posX = tableroForma[3][0].posX;
    tableroForma[2][0].posY = tableroForma[3][0].posY-1;
    tableroForma[3][1].car = pieza.car;

    //  nodo [2][1]  //
    tableroForma[2][1].posX = tableroForma[3][0].posX+1;
    tableroForma[2][1].posY = tableroForma[3][0].posY-1;
    tableroForma[3][1].car = pieza.car;

    */

    animacion(pieza);

}


void inicializarTablero()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            tablero[i][j] = ' ';
        }
    }
}

void continuar()
{
    printf("\n\nPresione cualquier tecla para continuar...");
    getch();
    system("cls");
}

void gotoxy(int x,int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}
