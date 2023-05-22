/*

Existen muchosm´etodos num´ericos capaces de proporcionar aproximaciones al n´umero
pi. Uno de ellos es el siguiente:

Cree un programa que lea el grado de aproximaci´on—n´umero de t´erminos de la sumatoria—
y devuelva un valor aproximado de —con 10 t´erminos se obtiene 3.04936 y con 100
t´erminos 3.13208.

*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    double piAprox = 0;

    cout << "Introduce el grado de aproximación (número de términos de la sumatoria): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        double termino = pow(-1, i) / (2 * i + 1);
        piAprox += termino;
    }

    piAprox *= 4;

    cout << "El valor aproximado de pi con " << n << " términos es: " << piAprox << endl;

    return 0;
}
