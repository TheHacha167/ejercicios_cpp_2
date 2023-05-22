/*

Realice un programa que lea de la entrada est´andar 10 n´umeros e indique en la salida
est´andar si el n´umero cero estaba entre los n´umeros le´ıdos.

*/
#include <iostream>

using namespace std;

int main() {
    const int NUM_NUMEROS = 10;
    int numero;
    bool ceroEncontrado = false;

    cout << "Introduce 10 números enteros: ";

    for (int i = 0; i < NUM_NUMEROS; i++) {
        cin >> numero;
        if (numero == 0) {
            ceroEncontrado = true;
        }
    }

    if (ceroEncontrado) {
        cout << "El número cero estaba entre los números leídos." << endl;
    } else {
        cout << "El número cero no estaba entre los números leídos." << endl;
    }

    return 0;
}
