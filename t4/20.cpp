/*
Realice un programa que solicite al usuario un entero positivo e indique en la salida
est´andar si el entero le´ıdo es una potencia de dos.

*/
#include <iostream>

using namespace std;

bool esPotenciaDeDos(int n) {
    // Verificar si n es una potencia de dos
    return (n & (n - 1)) == 0;
}

int main() {
    int numero;

    cout << "Ingrese un entero positivo: ";
    cin >> numero;

    // Verificar si el número es una potencia de dos
    if (numero > 0 && esPotenciaDeDos(numero)) {
        cout << numero << " es una potencia de dos." << endl;
    } else {
        cout << numero << " no es una potencia de dos." << endl;
    }

    return 0;
}
