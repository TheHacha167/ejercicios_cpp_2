/*

Escriba un programa que calcule x^y, donde tanto x como y son enteros positivos, sin
utilizar la funci´on pow.

*/
#include <iostream>

using namespace std;

int main() {
    int x, y;
    int resultado = 1;

    cout << "Introduce el valor de x: ";
    cin >> x;
    cout << "Introduce el valor de y: ";
    cin >> y;

    if (y >= 0) {
        for (int i = 0; i < y; i++) {
            resultado *= x;
        }
    } else {
        cout << "El valor de y debe ser un entero positivo." << endl;
        return 1;
    }

    cout << "El resultado de " << x << "^" << y << " es: " << resultado << endl;

    return 0;
}
