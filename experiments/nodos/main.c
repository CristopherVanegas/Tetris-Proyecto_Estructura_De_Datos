//     Formas de Tetris     //

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>


typedef struct
{
    char car;
    int posX, posY;

    struct nodo *bonus;
    struct nodo *anterior;
    struct nodo *siguiente;
} nodo;

nodo *superior = NULL;


int mForma[4][2];


void agregar(int caracter);
void eliminarUltimo(void);
void imprimir(void);
void continuar();


/*  Funciones Definidas  */
void crear();
void mostrar();
void continuar();

int main()
{
    srand(time(NULL));
    printf("Prueba de nodos para formar figuras del Tetris\n");
    do {
        printf("\nDesea agregar un nodo? (y / n) ");
        if (getche() == 'y') {
            crear();
        }

        mostrar();
        // continuar();
        printf(" >> Presione 'n' si desea terminar el programa! ");

    } while (getch() != 'n');

    return 0;
}

void crear()
{
    int c = 1;// + rand() % 5;

    switch(c)
    {
    case 1:
    {
        system("cls");
        printf("creando nueva forma\n");
        nodo *nuevoNodo = malloc(sizeof(nodo));
        nuevoNodo->car = '\xFE';
        nuevoNodo->siguiente = superior;
        superior = nuevoNodo;
    }
    break;
    }
}

void mostrar()
{
    if (superior == NULL) printf("\n\nLa pila esta vacia!\n\n");
    else
    {
        printf("\n\n     Imprimiendo...\n");
        nodo *temp = superior;
        while (temp != NULL)
        {
            printf("%c\n", temp->car);
            temp = temp->siguiente;
        }
    }
}

void continuar()
{
    printf(" > Presione cualquier tecla para continuar... ");
    getch();
}
