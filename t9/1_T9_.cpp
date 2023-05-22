/*

Realice una funci´on recursiva que sume los primeros n enteros positivos. Nota: para
plantear la funci´on recursiva tenga en cuenta que la suma puede expresarse mediante
la siguiente recurrencia:
suma(n) =
(
1 si n = 1
n + suma(n 􀀀 1) si n > 1
*/

#include <iostream>

int sumaRecursiva(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n + sumaRecursiva(n - 1);
    }
}

int main() {
    int n;
    std::cout << "Ingrese un número entero positivo: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "El número debe ser positivo." << std::endl;
        return 0;
    }

    int resultado = sumaRecursiva(n);

    std::cout << "La suma de los primeros " << n << " enteros positivos es: " << resultado << std::endl;

    return 0;
}
