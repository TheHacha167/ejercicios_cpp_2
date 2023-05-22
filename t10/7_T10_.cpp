/*
Realice un programa que trabaje con una matriz bidimensional de enteros, implemente
funciones que permitan:
 guardar una matriz de enteros en un fichero de texto, almacenando cada fila en
una l´ınea distinta.
 recuperar los datos almacenados en un fichero de texto en una matriz.


*/
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

void guardarMatriz(const std::vector<std::vector<int>>& matriz, const std::string& nombreFichero) {
    std::ofstream archivo(nombreFichero);

    if (!archivo) {
        std::cout << "No se pudo abrir el fichero." << std::endl;
        return;
    }

    for (const auto& fila : matriz) {
        for (int elemento : fila) {
            archivo << elemento << " ";
        }
        archivo << std::endl;
    }

    std::cout << "Matriz guardada en el fichero." << std::endl;
}

std::vector<std::vector<int>> recuperarMatriz(const std::string& nombreFichero) {
    std::ifstream archivo(nombreFichero);
    std::vector<std::vector<int>> matriz;

    if (!archivo) {
        std::cout << "No se pudo abrir el fichero." << std::endl;
        return matriz;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::vector<int> fila;
        std::stringstream ss(linea);
        int elemento;

        while (ss >> elemento && !ss.fail()) {
            fila.push_back(elemento);
        }

        matriz.push_back(fila);
    }

    std::cout << "Datos recuperados del fichero." << std::endl;
    return matriz;
}

void imprimirMatriz(const std::vector<std::vector<int>>& matriz) {
    for (const auto& fila : matriz) {
        for (int elemento : fila) {
            std::cout << elemento << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> matriz = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    std::string nombreFichero = "matriz.txt";

    guardarMatriz(matriz, nombreFichero);

    std::vector<std::vector<int>> matrizRecuperada = recuperarMatriz(nombreFichero);

    imprimirMatriz(matrizRecuperada);

    return 0;
}
