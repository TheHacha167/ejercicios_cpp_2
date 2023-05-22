/*
Realice un programa que calcule la descomposici´on en factores primos de un n´umero
entero.

*/
#include <iostream>
#include <vector>

using namespace std;

void descomposicionFactoresPrimos(int numero) {
    vector<int> factoresPrimos;

    // Calcular los factores primos del número
    for (int i = 2; i <= numero; i++) {
        while (numero % i == 0) {
            factoresPrimos.push_back(i);
            numero /= i;
        }
    }

    // Mostrar la descomposición en factores primos
    cout << "La descomposición en factores primos de " << numero << " es: ";
    for (int i = 0; i < factoresPrimos.size(); i++) {
        cout << factoresPrimos[i];
        if (i != factoresPrimos.size() - 1) {
            cout << " x ";
        }
    }
    cout << endl;
}

int main() {
    int numero;

    cout << "Ingrese un número entero positivo: ";
    cin >> numero;

    // Verificar si el número es positivo
    if (numero <= 0) {
        cout << "El número ingresado no es válido. Debe ser un entero positivo." << endl;
        return 1;
    }

    // Calcular la descomposición en factores primos
    descomposicionFactoresPrimos(numero);

    return 0;
}
