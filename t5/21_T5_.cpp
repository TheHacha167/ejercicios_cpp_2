/*
Realice un programa que calcule la suma de dos matrices cuadradas de 3x3.
*/
#include <iostream>

int main() {
    int matriz1[3][3];
    int matriz2[3][3];
    int matrizSuma[3][3];

    std::cout << "Ingrese los elementos de la primera matriz de 3x3:" << std::endl;

    // Leer la primera matriz
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> matriz1[i][j];
        }
    }

    std::cout << "Ingrese los elementos de la segunda matriz de 3x3:" << std::endl;

    // Leer la segunda matriz
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> matriz2[i][j];
        }
    }

    // Calcular la suma de las matrices
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrizSuma[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    // Mostrar la matriz suma
    std::cout << "Matriz suma:" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrizSuma[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
