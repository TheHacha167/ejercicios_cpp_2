/*
Realice una funci´on que dada una matriz y un n´umero de fila de la matriz devuelva el
m´ınimo de los elementos almacenados en dicha fila.
*/
#include <iostream>
#include <vector>
#include <limits>

// Función para encontrar el mínimo elemento de una fila en una matriz
int encontrarMinimoFila(const std::vector<std::vector<int>>& matriz, int fila) {
    int minimo = std::numeric_limits<int>::max(); // Valor máximo para inicializar el mínimo

    for (int elemento : matriz[fila]) {
        if (elemento < minimo) {
            minimo = elemento;
        }
    }

    return minimo;
}

int main() {
    std::vector<std::vector<int>> matriz = {{3, 4, 1},
                                            {2, 8, 6},
                                            {5, 9, 7}};

    int fila = 1;

    int minimo = encontrarMinimoFila(matriz, fila);

    std::cout << "Mínimo elemento de la fila " << fila << ": " << minimo << std::endl;

    return 0;
}
