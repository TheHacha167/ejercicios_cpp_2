/*
Una matriz nxmse dice que es sim´etrica si n = my aij = aji8i; j : 1  i  n; 1  j  n.
Desarrollar una funci´on que determine si una matriz es sim´etrica o no.
*/
#include <iostream>
#include <vector>

bool esSimetrica(const std::vector<std::vector<int>>& matriz) {
    int filas = matriz.size();
    int columnas = matriz[0].size();

    if (filas != columnas) {
        return false;  // La matriz no es cuadrada, por lo tanto no puede ser simétrica
    }

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (matriz[i][j] != matriz[j][i]) {
                return false;  // Los elementos no coinciden en la posición simétrica, la matriz no es simétrica
            }
        }
    }

    return true;  // Todos los elementos coinciden en sus posiciones simétricas, la matriz es simétrica
}

int main() {
    std::vector<std::vector<int>> matriz = {{1, 2, 3},
                                            {2, 4, 5},
                                            {3, 5, 6}};

    if (esSimetrica(matriz)) {
        std::cout << "La matriz es simétrica." << std::endl;
    } else {
        std::cout << "La matriz no es simétrica." << std::endl;
    }

    return 0;
}
