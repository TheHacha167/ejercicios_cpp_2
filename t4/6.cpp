/*
Realice un programa que calcule y muestre en la salida est´andar la suma de los cuadrados
de los n´umeros enteros del 1 al 10—la soluci´on es 385 = 12 + 22 + : : : + 102.


*/
#include <iostream>

using namespace std;

int main() {
    int suma = 0;

    for (int i = 1; i <= 10; i++) {
        suma += i * i;
    }

    cout << "La suma de los cuadrados de los números del 1 al 10 es: " << suma << endl;

    return 0;
}

