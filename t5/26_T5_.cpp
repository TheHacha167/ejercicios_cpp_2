/*
Realice un programa que solicite al usuario los elementos de una matriz. La dimensi´on
de la matriz la decide el usuario, aunque el n´umero m´aximo de filas es 20 y el de
columnas 10. El programa debe almacenar en un vector el m´ınimo de los elementos
de cada columna. Una vez calculados se debe mostrar en la salida el contenido de la
matriz y los m´ınimos de cada columna almacenados en el vector.
*/
#include <iostream>
#include <vector>

const int MAX_FILAS = 20;
const int MAX_COLUMNAS = 10;

void obtenerElementosMatriz(std::vector<std::vector<int>>& matriz, int filas, int columnas) {
    std::cout << "Ingrese los elementos de la matriz:" << std::endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            std::cin >> matriz[i][j];
        }
    }
}

void obtenerMinimosColumna(const std::vector<std::vector<int>>& matriz, std::vector<int>& minimosColumna, int filas, int columnas) {
    for (int j = 0; j < columnas; j++) {
        int minimo = matriz[0][j];
        for (int i = 1; i < filas; i++) {
            if (matriz[i][j] < minimo) {
                minimo = matriz[i][j];
            }
        }
        minimosColumna[j] = minimo;
    }
}

void mostrarMatriz(const std::vector<std::vector<int>>& matriz, int filas, int columnas) {
    std::cout << "Matriz:" << std::endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void mostrarMinimosColumna(const std::vector<int>& minimosColumna, int columnas) {
    std::cout << "Mínimos de cada columna:" << std::endl;
    for (int j = 0; j < columnas; j++) {
        std::cout << minimosColumna[j] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int filas, columnas;

    std::cout << "Ingrese el número de filas (máximo " << MAX_FILAS << "): ";
    std::cin >> filas;

    std::cout << "Ingrese el número de columnas (máximo " << MAX_COLUMNAS << "): ";
    std::cin >> columnas;

    std::vector<std::vector<int>> matriz(filas, std::vector<int>(columnas));
    std::vector<int> minimosColumna(columnas);

    obtenerElementosMatriz(matriz, filas, columnas);
    obtenerMinimosColumna(matriz, minimosColumna, filas, columnas);
    mostrarMatriz(matriz, filas, columnas);
    mostrarMinimosColumna(minimosColumna, columnas);

    return 0;
}
