/*

Escribe un programa que lea de la entrada est´andar el precio de un producto y muestre
en la salida est´andar el precio del producto al aplicarle el IVA.
Entrada caso de prueba: Precio 100.
Salida caso de prueba: Precio con IVA: 121—se supone un IVA del 21%

*/

#include <iostream>

int main() {
    double precio;
    double iva = 0.21;

    std::cout << "Introduce el precio del producto: ";
    std::cin >> precio;

    double precioConIva = precio + (precio * iva);

    std::cout << "Precio con IVA: " << precioConIva << std::endl;

    return 0;
}
