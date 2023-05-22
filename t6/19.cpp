/*
Realice una funci´on que calcule el producto de dos matrices cuadradas de 3x3.
*/
#include <iostream>
#include <vector>

// Función para imprimir una matriz
void imprimirMatriz(const std::vector<std::vector<int>>& matriz) {
    for (const auto& fila : matriz) {
        for (int elemento : fila) {
            std::cout << elemento << " ";
        }
        std::cout << std::endl;
    }
}

// Función para multiplicar dos matrices cuadradas de 3x3
std::vector<std::vector<int>> multiplicarMatrices(const std::vector<std::vector<int>>& matriz1, const std::vector<std::vector<int>>& matriz2) {
    std::vector<std::vector<int>> resultado(3, std::vector<int>(3, 0));

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    return resultado;
}

int main() {
    std::vector<std::vector<int>> matriz1 = {{1, 2, 3},
                                             {4, 5, 6},
                                             {7, 8, 9}};

    std::vector<std::vector<int>> matriz2 = {{9, 8, 7},
                                             {6, 5, 4},
                                             {3, 2, 1}};

    std::vector<std::vector<int>> resultado = multiplicarMatrices(matriz1, matriz2);

    std::cout << "Matriz 1:" << std::endl;
    imprimirMatriz(matriz1);

    std::cout << "Matriz 2:" << std::endl;
    imprimirMatriz(matriz2);

    std::cout << "Resultado de la multiplicación:" << std::endl;
    imprimirMatriz(resultado);

    return 0;
}
