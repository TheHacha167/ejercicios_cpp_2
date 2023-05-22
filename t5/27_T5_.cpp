/*
Realice un programa que defina o solicite al usuario una matriz y despu´es permute sus
filas. Es decir, la primera fila se debe intercambiar con la ´ ultima, la segunda fila con al
pen´ ultima y as´ı sucesivamente. Muestre la matriz original y, una vez intercambiadas
las filas, vuelva a mostrar la matriz para comprobar que el intercambio de filas se
realiz ´o con ´exito
*/
#include <iostream>
#include <vector>

void solicitarMatriz(std::vector<std::vector<int>>& matriz, int filas, int columnas) {
    std::cout << "Ingrese los elementos de la matriz:" << std::endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            std::cin >> matriz[i][j];
        }
    }
}

void intercambiarFilas(std::vector<std::vector<int>>& matriz) {
    int filas = matriz.size();
    int columnas = matriz[0].size();
    int filaTemporal[columnas];

    for (int i = 0; i < filas / 2; i++) {
        for (int j = 0; j < columnas; j++) {
            filaTemporal[j] = matriz[i][j];
            matriz[i][j] = matriz[filas - 1 - i][j];
            matriz[filas - 1 - i][j] = filaTemporal[j];
        }
    }
}

void mostrarMatriz(const std::vector<std::vector<int>>& matriz) {
    std::cout << "Matriz:" << std::endl;
    for (const auto& fila : matriz) {
        for (int elemento : fila) {
            std::cout << elemento << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int filas, columnas;

    std::cout << "Ingrese el número de filas: ";
    std::cin >> filas;

    std::cout << "Ingrese el número de columnas: ";
    std::cin >> columnas;

    std::vector<std::vector<int>> matriz(filas, std::vector<int>(columnas));

    solicitarMatriz(matriz, filas, columnas);

    std::cout << "Matriz original:" << std::endl;
    mostrarMatriz(matriz);

    intercambiarFilas(matriz);

    std::cout << "Matriz con filas intercambiadas:" << std::endl;
    mostrarMatriz(matriz);

    return 0;
}
