/*

Realice un programa que lea un valor entero y determine si se trata de un n´umero
par o impar. Sugerencia: un n´umero es par si el resto de dividirlo entre dos es cero.
Generalice el programa para que lea dos enteros, n y m, y determine si n divide a m.

*/
#include <iostream>

using namespace std;

int main() {
    int num;
    int n, m;

    // Parte 1: Determinar si un número es par o impar
    cout << "Introduce un número entero: ";
    cin >> num;

    if (num % 2 == 0) {
        cout << num << " es un número par." << endl;
    } else {
        cout << num << " es un número impar." << endl;
    }

    // Parte 2: Determinar si n divide a m
    cout << "Introduce dos números enteros (n y m): ";
    cin >> n >> m;

    if (m % n == 0) {
        cout << n << " divide a " << m << "." << endl;
    } else {
        cout << n << " no divide a " << m << "." << endl;
    }

    return 0;
}
