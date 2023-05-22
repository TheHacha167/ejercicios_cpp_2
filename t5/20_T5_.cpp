/*
Realice un programa que lea una matriz de 3x3 y cree su matriz traspuesta. La matriz
traspuesta es aquella en la que la columna i era la fila i de la matriz original.
*/
#include <iostream>

int main() {
    int matriz[3][3];
    int matrizTraspuesta[3][3];

    std::cout << "Ingrese los elementos de la matriz de 3x3:" << std::endl;

    // Leer la matriz original
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> matriz[i][j];
        }
    }

    // Crear la matriz traspuesta
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrizTraspuesta[i][j] = matriz[j][i];
        }
    }

    // Mostrar la matriz traspuesta
    std::cout << "Matriz traspuesta:" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrizTraspuesta[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
