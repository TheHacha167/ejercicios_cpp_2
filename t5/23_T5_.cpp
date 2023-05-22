/*
Realice un programa que calcule el producto de dos matrices cuadradas de 3x3.
*/
#include <iostream>

const int FILAS = 3;
const int COLUMNAS = 3;

void productoMatrices(int matrizA[FILAS][COLUMNAS], int matrizB[FILAS][COLUMNAS], int resultado[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < COLUMNAS; k++) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

void imprimirMatriz(int matriz[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int matrizA[FILAS][COLUMNAS];
    int matrizB[FILAS][COLUMNAS];
    int resultado[FILAS][COLUMNAS];

    std::cout << "Ingrese los elementos de la matriz A de " << FILAS << "x" << COLUMNAS << ":" << std::endl;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            std::cin >> matrizA[i][j];
        }
    }

    std::cout << "Ingrese los elementos de la matriz B de " << FILAS << "x" << COLUMNAS << ":" << std::endl;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            std::cin >> matrizB[i][j];
        }
    }

    productoMatrices(matrizA, matrizB, resultado);

    std::cout << "El resultado del producto de las matrices A y B es:" << std::endl;
    imprimirMatriz(resultado);

    return 0;
}
