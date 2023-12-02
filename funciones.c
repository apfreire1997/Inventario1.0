#include <stdio.h>
#include "funciones.h"

void ingresarProducto(char nombres[][100], int cantidades[], float precios[], int *numProductos) {
    if (*numProductos < 100) {
        printf("Ingrese el nombre del producto: ");
        scanf("%s", nombres[*numProductos]);

        printf("Ingrese la cantidad del producto: ");
        scanf("%d", &cantidades[*numProductos]);

        printf("Ingrese el precio del producto: ");
        scanf("%f", &precios[*numProductos]);

        (*numProductos)++;
        printf("Producto ingresado exitosamente.\n");
    } else {
        printf("No se pueden ingresar más productos, límite alcanzado.\n");
    }
}

void editarProducto(char nombres[][100], int cantidades[], float precios[], int numProductos) {
    if (numProductos > 0) {
        char nombreBuscado[100];
        printf("Ingrese el nombre del producto que desea editar: ");
        scanf("%s", nombreBuscado);

        int encontrado = 0;
        for (int i = 0; i < numProductos; i++) {
            if (strcmp(nombres[i], nombreBuscado) == 0) {
                printf("Ingrese la nueva cantidad del producto: ");
                scanf("%d", &cantidades[i]);

                printf("Ingrese el nuevo precio del producto: ");
                scanf("%f", &precios[i]);

                printf("Producto editado exitosamente.\n");
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("Producto no encontrado.\n");
        }
    } else {
        printf("No hay productos para editar.\n");
    }
}

void eliminarProducto(char nombres[][100], int cantidades[], float precios[], int *numProductos) {
    if (*numProductos > 0) {
        char nombreBuscado[100];
        printf("Ingrese el nombre del producto que desea eliminar: ");
        scanf("%s", nombreBuscado);

        int encontrado = 0;
        for (int i = 0; i < *numProductos; i++) {
            if (strcmp(nombres[i], nombreBuscado) == 0) {

                for (int j = i; j < *numProductos - 1; j++) {
                    strcpy(nombres[j], nombres[j + 1]);
                    cantidades[j] = cantidades[j + 1];
                    precios[j] = precios[j + 1];
                }

                (*numProductos)--;
                printf("Producto eliminado exitosamente.\n");
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("Producto no encontrado.\n");
        }
    } else {
        printf("No hay productos para eliminar.\n");
    }
}

void mostrarInventario(char nombres[][100], int cantidades[], float precios[], int numProductos) {
    if (numProductos > 0) {
       printf("-------------------------------------------------------\n");
      printf("|                     Inventario                      | \n");
        printf("-------------------------------------------------------\n");
        printf("%-20s %-10s %-10s\n", "Nombre", "Cantidad", "Precio");
       printf("-------------------------------------------------------\n");
        for (int i = 0; i < numProductos; i++) {
            printf("%-20s %-10d %-10.2f\n", nombres[i], cantidades[i], precios[i]);
       printf("-------------------------------------------------------\n");
        }
    } else {
        printf("El inventario está vacío.\n");
    }
}
