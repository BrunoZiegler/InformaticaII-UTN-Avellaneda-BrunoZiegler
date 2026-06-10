#include <stdio.h>
#include "funciones.h"

int main(void) {

    articulos_t articulos[CANT_ARTICULOS] = {0}; 

    printf("Bienvenido\n");

    cargarDatos(articulos);

    printf("\n--- Fichas Cargadas ---\n");

    mostrarArticulos(articulos);
    ordenarArticulos(articulos);


    printf("\n\n----------------ORDENADO----------------\n\n");

    mostrarArticulos(articulos);

    return 0;

}