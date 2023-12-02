#include <stdio.h>
#include "menu.h"
#include "funciones.h"

int main() {
    char nombres[100][100];
    int cantidades[100];
    float precios[100];
    int numProductos = 0;

    int opcion;
    do {
        mostrarMenu();
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarProducto(nombres, cantidades, precios, &numProductos);
                break;
            case 2:
                editarProducto(nombres, cantidades, precios, numProductos);
                break;
            case 3:
                eliminarProducto(nombres, cantidades, precios, &numProductos);
                break;
            case 4:
                mostrarInventario(nombres, cantidades, precios, numProductos);
                break;
            case 5:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no valida. Por favor, ingrese una opcion valida.\n");
        }
    } while (opcion != 5);

    return 0;
}
