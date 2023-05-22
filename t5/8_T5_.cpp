/*

Desarrolle un programa que determine el primer y segundo elementos mayores de un
vector de enteros.

*/
#include <iostream>
#include <vector>
#include <algorithm>

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

    // Ordenar el vector en orden descendente
    sort(numeros.begin(), numeros.end(), greater<int>());

    int primerMayor = numeros[0];
    int segundoMayor = numeros[1];

    cout << "El primer elemento mayor es: " << primerMayor << endl;
    cout << "El segundo elemento mayor es: " << segundoMayor << endl;

    return 0;
}
