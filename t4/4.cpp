/*

Realice un programa que solicite de la entrada est´andar un entero del 1 al 10 y muestre
en la salida est´andar su tabla de multiplicar.

*/
#include <iostream>

using namespace std;

int main() {
    int numero;

    cout << "Introduce un número entero del 1 al 10: ";
    cin >> numero;

    if (numero >= 1 && numero <= 10) {
        cout << "Tabla de multiplicar del " << numero << ":" << endl;
        for (int i = 1; i <= 10; i++) {
            cout << numero << " x " << i << " = " << numero * i << endl;
        }
    } else {
        cout << "El número introducido está fuera del rango permitido." << endl;
    }

    return 0;
}
