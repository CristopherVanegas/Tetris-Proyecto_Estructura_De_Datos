#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    char car;
    int posX, posY;
    struct nodo *bonus, *ant, *sig;
};

struct nodo* matrizDeForma[4][2];    // matriz para darle forma a los nodos
struct nodo* matriz[20][10];         // matriz como tablero donde caen las fichas

void crear()
{
    int c = 0; // + rand() % 5;

    switch (c)
    {
    // cuadrado
    case 0:
    {
        // Se inicia con el nodo *inicio
        struct nodo *inicio = NULL;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {

                if ((i == 0) && (j == 0)) matrizDeForma[i][j]->bonus = inicio;
                else
                {
                    struct nodo *nuevoNodo = malloc(sizeof(struct nodo));
                    nuevoNodo->car = '\xFE';
                    nuevoNodo->sig = inicio;
                    inicio = nuevoNodo;

                    matrizDeForma[i][j]->bonus = nuevoNodo;
                }
            }
        }
    }
    break;
    }
}


void mostrar() {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%c", matrizDeForma[i][j]->bonus->car);
        }
        printf("\n");
    }
}


int main()
{
    crear();
    mostrar();
    return 0;
}
