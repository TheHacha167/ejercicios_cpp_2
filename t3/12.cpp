/*

Escriba un programa que calcule la desviaci´on est´andar de cinco n´umeros:
Entrada caso de prueba: 1, 4.5, 7, 3 y 15.
Salida caso de prueba: Desviaci´on est´andar: 5.436.

*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    vector<double> numeros(5);
    double sum = 0.0, mean, standardDeviation = 0.0;

    for(int i = 0; i < 5; ++i) {
        cout << "Introduce el número " << (i + 1) << ": ";
        cin >> numeros[i];
        sum += numeros[i];
    }

    mean = sum/5;

    for(int i = 0; i < 5; ++i)
        standardDeviation += pow(numeros[i] - mean, 2);

    cout << "Desviación estándar: " << sqrt(standardDeviation / 5) << endl;

    return 0;
}
