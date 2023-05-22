/*
Escribe un programa que defina un vector de n´umeros y calcule la suma de sus elementos.
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Ingrese la cantidad de números: ";
    cin >> n;

    vector<int> numeros(n);

    cout << "Ingrese los números:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> numeros[i];
    }

    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += numeros[i];
    }

    cout << "La suma de los elementos del vector es: " << suma << endl;

    return 0;
}
