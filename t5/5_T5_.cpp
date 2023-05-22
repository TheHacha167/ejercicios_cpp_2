/*
Enunciado:
Desarrolle un programa que inicie un vector de enteros con valores leídos de la entrada
estándar y, a continuación, calcule el mayor elemento del vector.
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

    int mayor = numeros[0];
    for (int i = 1; i < n; i++) {
        if (numeros[i] > mayor) {
            mayor = numeros[i];
        }
    }

    cout << "El mayor elemento del vector es: " << mayor << endl;

    return 0;
}
