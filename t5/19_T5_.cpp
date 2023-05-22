/*
Realizar un programa que lea los datos de un array de 3x3 desde la entrada est´andar y
calcule su determinante.
*/
#include <iostream>

int calcularDeterminante(int matriz[3][3]) {
    int determinante = 0;

    determinante = (matriz[0][0] * matriz[1][1] * matriz[2][2]) +
                   (matriz[0][1] * matriz[1][2] * matriz[2][0]) +
                   (matriz[0][2] * matriz[1][0] * matriz[2][1]) -
                   (matriz[0][2] * matriz[1][1] * matriz[2][0]) -
                   (matriz[0][0] * matriz[1][2] * matriz[2][1]) -
                   (matriz[0][1] * matriz[1][0] * matriz[2][2]);

    return determinante;
}

int main() {
    int matriz[3][3];

    std::cout << "Ingrese los elementos de la matriz de 3x3:" << std::endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> matriz[i][j];
        }
    }

    int determinante = calcularDeterminante(matriz);

    std::cout << "El determinante de la matriz es: " << determinante << std::endl;

    return 0;
}
