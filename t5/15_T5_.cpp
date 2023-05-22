/*
Realice un programa que defina un vector de enteros y sit ´ue al principio del vector los
enteros pares y despu´es los impares. Sugerencia: utilice dos vectores auxiliares.
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> ordenarParesImpares(const vector<int>& numeros) {
    vector<int> pares;
    vector<int> impares;

    // Separar los enteros pares de los impares
    for (int i = 0; i < numeros.size(); i++) {
        if (numeros[i] % 2 == 0) {
            pares.push_back(numeros[i]);
        } else {
            impares.push_back(numeros[i]);
        }
    }

    // Combinar los vectores de pares e impares
    vector<int> resultado;
    resultado.insert(resultado.end(), pares.begin(), pares.end());
    resultado.insert(resultado.end(), impares.begin(), impares.end());

    return resultado;
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
