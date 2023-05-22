/*
Escribe un programa que defina un vector de n´umeros y calcule si existe alg ´un n´umero
en el vector cuyo valor equivale a la suma del resto de n´umeros del vector.
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

    bool existe = false;

    for (int i = 0; i < n; i++) {
        int sumaResto = 0;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                sumaResto += numeros[j];
            }
        }
        if (numeros[i] == sumaResto) {
            existe = true;
            break;
        }
    }

    if (existe) {
        cout << "Existe al menos un número en el vector cuyo valor equivale a la suma del resto de números." << endl;
    } else {
        cout << "No existe ningún número en el vector cuyo valor equivale a la suma del resto de números." << endl;
    }

    return 0;
}
