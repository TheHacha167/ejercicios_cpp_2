/*

Escriba un programa que lea valores enteros hasta que se introduzca un valor en el
rango [20; 30] o se introduzca el valor 0.

*/
#include <iostream>

using namespace std;

int main() {
    int valor;

    cout << "Introduce valores enteros (0 para terminar): ";

    do {
        cin >> valor;
    } while (valor != 0 && (valor < 20 || valor > 30));

    cout << "Se introdujo un valor en el rango [20; 30] o se introdujo el valor 0." << endl;

    return 0;
}
