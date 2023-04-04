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


void gotoxy(int x,int y);
void animacion( Pieza tableroForma[4][2]);
void inicializoForma();
void continuar();


int main()
{
    printf("Experimento 2 - Matriz de Structs!\n");
    continuar();
    inicializoForma();

    printf("\n\n\n\n");

    return 0;
}

void animacion( Pieza tableroForma[4][2])
{
    system("cls");

    /*  Bucle de la animacion  */
    for (int k = 0; k < 10; k++)
    {
        gotoxy(tableroForma[3][1].posX, tableroForma[3][1].posY);
        printf("%c", tableroForma[3][1].car);
        // tableroForma[3][1].posX++;
        tableroForma[3][1].posY++;
        Sleep(250);
    }
}

void inicializoForma()
{
    Pieza tableroForma[4][2], pieza;

    pieza.car = '\xFE';
    pieza.posX = 0;
    pieza.posY = 0;

    tableroForma[3][1] = pieza;

    animacion(tableroForma);

}

void continuar()
{
    printf("\n\nPresione cualquier tecla para continuar...");
    getch();
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
