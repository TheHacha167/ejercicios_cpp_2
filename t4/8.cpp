/*
Realice un programa que calcule el valor que toma la siguiente funci´on para unos
valores dados de x e y:
f(x; y) = sqrt(x^2)/y^2-1
Entrada caso de prueba: x = 10, y = 3.
Salida caso de prueba: f(x; y) = 0:395.

*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x, y;

    cout << "Introduce el valor de x: ";
    cin >> x;

    cout << "Introduce el valor de y: ";
    cin >> y;

    double resultado = sqrt(pow(x, 2)) / pow(y, 2) - 1;

    cout << "f(x; y) = " << resultado << endl;

    return 0;
}
