/*
Escribe un programa que defina un vector de n´umeros y calcule la suma acumulada
de sus elementos. Por ejemplo, si el vector contiene los n´umeros f1; 3; 2; 7g su suma
acumulada es 1; 4; 6; 13.
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

    vector<int> sumaAcumulada(n);
    sumaAcumulada[0] = numeros[0];

    for (int i = 1; i < n; i++) {
        sumaAcumulada[i] = sumaAcumulada[i - 1] + numeros[i];
    }

    cout << "La suma acumulada de los elementos del vector es: ";
    for (int i = 0; i < n; i++) {
        cout << sumaAcumulada[i] << " ";
    }
    cout << endl;

    return 0;
}
