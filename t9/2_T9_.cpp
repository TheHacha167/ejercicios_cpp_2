/*
Escriba una funci´on recursiva que calcule un n´umero elevado a una potencia entera
mayor o igual que cero: xy. Exprese el c´alculo mediante una recurrencia y despu´es
escriba la funci´on recursiva.
*/
#include <iostream>

double potenciaRecursiva(double x, int y) {
    if (y == 0) {
        return 1;
    } else {
        return x * potenciaRecursiva(x, y - 1);
    }
}

int main() {
    double base;
    int exponente;
    std::cout << "Ingrese la base: ";
    std::cin >> base;
    std::cout << "Ingrese el exponente (mayor o igual a cero): ";
    std::cin >> exponente;

    if (exponente < 0) {
        std::cout << "El exponente debe ser mayor o igual a cero." << std::endl;
        return 0;
    }

    double resultado = potenciaRecursiva(base, exponente);

    std::cout << base << " elevado a la potencia " << exponente << " es igual a " << resultado << std::endl;

    return 0;
}
