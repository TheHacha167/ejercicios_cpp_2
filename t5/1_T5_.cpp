    /*

Escribe un programa que lea de la entrada est´andar una serie de n´umeros, almacen
´andolos en un vector. Una vez rellenado el vector con los n´umeros le´ıdos, muestre
en la salida est´andar los n´umeros del vector con sus ´ındices asociados.
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Ingrese la cantidad de números a leer: ";
    cin >> n;

    vector<int> numeros(n);

    cout << "Ingrese los números:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> numeros[i];
    }

    cout << "Los números del vector con sus índices asociados son:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Índice " << i << ": " << numeros[i] << endl;
    }

    return 0;
}
