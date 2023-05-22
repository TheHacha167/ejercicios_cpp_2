/*
Escriba un programa que defina un vector de n´umeros enteros, solicite al usuario un
entero y muestre un mensaje en la salida est´andar indicando si el entero introducido
por el usuario se encuentra en el vector
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

    int numeroBuscado;
    cout << "Ingrese el número a buscar: ";
    cin >> numeroBuscado;

    bool encontrado = false;
    for (int i = 0; i < n; i++) {
        if (numeros[i] == numeroBuscado) {
            encontrado = true;
            break;
        }
    }

    if (encontrado) {
        cout << "El número " << numeroBuscado << " se encuentra en el vector." << endl;
    } else {
        cout << "El número " << numeroBuscado << " no se encuentra en el vector." << endl;
    }

    return 0;
}
