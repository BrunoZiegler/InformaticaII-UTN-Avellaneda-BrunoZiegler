#include <stdio.h>
#include <string.h>
#include "funciones.h"


void mostrarArticulos(articulos_t *articulos) {

    int i = 0;

    printf("\nArticulo\tSucursal 1\tSucursal 2\tSucursal 3\tTotal\n");
    
    while(i < CANT_ARTICULOS && articulos[i].descripcion[0] != '\0') {
        printf("%s\t%9d\t%4d\t%3d\t%8d\n", 
               articulos[i].descripcion, 
               articulos[i].cantidad_sucursal[SUCURSAL_1], 
               articulos[i].cantidad_sucursal[SUCURSAL_2], 
               articulos[i].cantidad_sucursal[SUCURSAL_3],
               articulos[i].total);
        i++;
    }
}

int buscarArticulo(articulos_t *articulos, char *descripcion_buscada) {
    int i = 0;

    while (articulos[i].descripcion[0] != '\0' && strcmp(descripcion_buscada, articulos[i].descripcion) != 0) {
        i++;
    }

    return i; 
}


void cargarDatos(articulos_t *articulos) {
    int opc = 0, i, articulo_index, sucursal;
    char articulo[90]; 

    do {

        printf("\nIngrese la descripcion del articulo: ");
        scanf("%s", articulo); 
        articulo_index = buscarArticulo(articulos, articulo);
        strcpy(articulos[articulo_index].descripcion, articulo);
        printf("%s, Indice: %d\n", articulos[articulo_index].descripcion, articulo_index);
        printf("Para que sucursal va a realizar la carga? (1, 2, 3): ");
        scanf("%d", &sucursal);

        if (sucursal >= 1 && sucursal <= 3) {

            printf("Ingrese la cantidad del articulo para la sucursal %d: ", sucursal);
            int cantidad_ingresada;
            scanf("%d", &cantidad_ingresada);
            articulos[articulo_index].cantidad_sucursal[sucursal - 1] += cantidad_ingresada;
            articulos[articulo_index].total = 0;

            for(i = 0; i < 3; i++) {

                articulos[articulo_index].total += articulos[articulo_index].cantidad_sucursal[i];

            }
        } else {

            printf("Sucursal incorrecta. Debe ser 1, 2 o 3.\n");
        }

        printf("Desea ingresar otro articulo? 1-Si, 2-No: ");
        scanf("%d", &opc);

    } while (opc == 1); 
}


void ordenarArticulos(articulos_t *articulos) {
    int i, j;
    articulos_t aux; 
    for (i = 0; i < CANT_ARTICULOS - 1; i++) {

        for (j = 0; j < CANT_ARTICULOS - 1 - i; j++) {

            if (articulos[j].descripcion[0] != '\0' && articulos[j+1].descripcion[0] != '\0') {

                if (articulos[j].total < articulos[j+1].total) {

                    aux = articulos[j];
                    articulos[j] = articulos[j+1];
                    articulos[j+1] = aux;
                    
                }
            }
        }
    }
}
