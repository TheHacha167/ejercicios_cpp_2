/*
Escribe un programa que defina un vector de n´umeros y muestre en la salida est´andar
el vector en orden inverso—del ´ ultimo al primer elemento. Nota: tendr´as que generar
los ´ındices en orden inverso para resolver el ejercicio.
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

    cout << "El vector en orden inverso es:" << endl;
    for (int i = n - 1; i >= 0; i--) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    return 0;
}
