/*

Escriba un programa que solicite una edad (un entero) e indique en la salida est´andar
si la edad introducida est´a en el rango [18; 25].

*/
#include <iostream>

using namespace std;

int main() {
    int edad;

    cout << "Introduce una edad: ";
    cin >> edad;

    if (edad >= 18 && edad <= 25) {
        cout << "La edad introducida está en el rango [18; 25]." << endl;
    } else {
        cout << "La edad introducida no está en el rango [18; 25]." << endl;
    }

    return 0;
}
