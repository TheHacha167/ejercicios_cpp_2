/*

Escriba una funci´on void escribeNumeros(int ini, int fin) que muestre en la salida est´andar
los n´umeros del ini al fin. Escriba una versi´on que escriba los n´umeros en orden ascendente
y otra en orden descendente.
*/
#include <iostream>

void escribeNumerosAscendente(int ini, int fin) {
    for (int i = ini; i <= fin; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void escribeNumerosDescendente(int ini, int fin) {
    for (int i = fin; i >= ini; i--) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    int inicio = 1;
    int fin = 10;

    std::cout << "Números en orden ascendente: ";
    escribeNumerosAscendente(inicio, fin);

    std::cout << "Números en orden descendente: ";
    escribeNumerosDescendente(inicio, fin);

    return 0;
}
