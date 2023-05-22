/*
Realiza un programa que defina una matriz de 3x3 y escriba un ciclo para que muestre
la diagonal principal de la matriz.
*/
#include <iostream>

int main() {
    int matriz[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};

    std::cout << "Diagonal principal: ";

    for (int i = 0; i < 3; i++) {
        std::cout << matriz[i][i] << " ";
    }

    std::cout << std::endl;

    return 0;
}
