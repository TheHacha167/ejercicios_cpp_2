/*

Escriba un programa que calcule las soluciones de una ecuaci´on de segundo grado de
la forma ax2 + bx + c = 0, teniendo en cuenta que:

Entrada caso de prueba: 2x2 + 9x + 3 = 0.
Salida caso de prueba: Ra´ıces: -0.36 y -4.14.

*/
#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

int main() {
    double a, b, c;

    cout << "Introduce el valor de a: ";
    cin >> a;

    cout << "Introduce el valor de b: ";
    cin >> b;

    cout << "Introduce el valor de c: ";
    cin >> c;

    complex<double> x1, x2;
    double discriminante = pow(b, 2) - 4*a*c;

    if(discriminante >= 0) {
        x1 = (-b + sqrt(discriminante)) / (2*a);
        x2 = (-b - sqrt(discriminante)) / (2*a);
    } else {
        x1 = complex<double>(-b / (2*a), sqrt(-discriminante) / (2*a));
        x2 = complex<double>(-b / (2*a), -sqrt(-discriminante) / (2*a));
    }

    cout << "Raíces: " << x1 << " y " << x2 << endl;

    return 0;
}
