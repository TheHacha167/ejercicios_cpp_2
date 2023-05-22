/*
Una matriz nxmse dice que es sim´etrica si n = my aij = aji8i; j : 1  i  n; 1  j  n.
Desarrollar un programa que determine si una matriz es sim´etrica o no.
*/
#include <iostream>

const int MAX_FILAS = 3;
const int MAX_COLUMNAS = 3;

bool esSimetrica(int matriz[MAX_FILAS][MAX_COLUMNAS]) {
    // Verificar si la matriz es simétrica
    for (int i = 0; i < MAX_FILAS; i++) {
        for (int j = i + 1; j < MAX_COLUMNAS; j++) {
            if (matriz[i][j] != matriz[j][i]) {
                return false; // La matriz no es simétrica
            }
        }
    }

    return true; // La matriz es simétrica
}

int main() {
    int matriz[MAX_FILAS][MAX_COLUMNAS];

    std::cout << "Ingrese los elementos de la matriz de " << MAX_FILAS << "x" << MAX_COLUMNAS << ":" << std::endl;

    // Leer los elementos de la matriz
    for (int i = 0; i < MAX_FILAS; i++) {
        for (int j = 0; j < MAX_COLUMNAS; j++) {
            std::cin >> matriz[i][j];
        }
    }

    // Verificar si la matriz es simétrica
    if (esSimetrica(matriz)) {
        std::cout << "La matriz es simétrica." << std::endl;
    } else {
        std::cout << "La matriz no es simétrica." << std::endl;
    }

    return 0;
}
