/*
Realice un programa como el del ejercicio anterior pero sin utilizar vectores auxiliares.
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> ordenarParesImpares(vector<int>& numeros) {
    int paresIndex = 0;

    // Mover los enteros pares al principio del vector
    for (int i = 0; i < numeros.size(); i++) {
        if (numeros[i] % 2 == 0) {
            swap(numeros[i], numeros[paresIndex]);
            paresIndex++;
        }
    }

    return numeros;
}

int main() {
    vector<int> numeros = {1, 4, 2, 3, 6, 5, 8, 7};

    vector<int> numerosOrdenados = ordenarParesImpares(numeros);

    cout << "Vector ordenado: ";
    for (int i = 0; i < numerosOrdenados.size(); i++) {
        cout << numerosOrdenados[i] << " ";
    }
    cout << endl;

    return 0;
}
