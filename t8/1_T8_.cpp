/*

Realice un programa que solicite al usuario un tama˜no de vector y reserve memoria
din´amica para un vector de enteros con el tama˜no indicado. A continuaci´on rellene
el vector con valores solicitados al usuario. Realice tambi´en una funci´on que muestre
el contenido de un vector y util´ıcela para comprobar que los valores solicitados al
usuario se han le´ıdo correctamente.
*/

#include <iostream>

void mostrarVector(int* vector, int tamaño) {
    for (int i = 0; i < tamaño; ++i) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int tamaño;
    std::cout << "Ingrese el tamaño del vector: ";
    std::cin >> tamaño;

    int* vector = new int[tamaño];

    std::cout << "Ingrese " << tamaño << " valores para el vector:" << std::endl;
    for (int i = 0; i < tamaño; ++i) {
        std::cin >> vector[i];
    }

    std::cout << "Contenido del vector: ";
    mostrarVector(vector, tamaño);

    delete[] vector;

    return 0;
}
