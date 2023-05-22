/*
Realice una funci´on que determine si un entero positivo es primo
*/
#include <iostream>

bool esPrimo(int numero) {
    if (numero <= 1) {
        return false;
    }

    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int numero;

    std::cout << "Ingrese un numero entero positivo: ";
    std::cin >> numero;

    if (esPrimo(numero)) {
        std::cout << numero << " es primo." << std::endl;
    } else {
        std::cout << numero << " no es primo." << std::endl;
    }

    return 0;
}
