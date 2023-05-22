/*
Realice un programa que defina un vector con varios caracteres. El programa debe
calcular el car´acter que ocurre m´as veces en el vector. Si el m´aximo es compartido por
m´as de un car´acter se puede mostrar cualquiera de ellos.
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

char encontrarCaracterFrecuente(const vector<char>& caracteres) {
    unordered_map<char, int> contador;

    // Contar la frecuencia de cada carácter
    for (char c : caracteres) {
        contador[c]++;
    }

    char caracterFrecuente = caracteres[0];
    int maxFrecuencia = contador[caracteres[0]];

    // Encontrar el carácter más frecuente
    for (char c : caracteres) {
        if (contador[c] > maxFrecuencia) {
            caracterFrecuente = c;
            maxFrecuencia = contador[c];
        }
    }

    return caracterFrecuente;
}

int main() {
    vector<char> caracteres = {'a', 'b', 'c', 'a', 'b', 'c', 'd', 'e', 'a', 'b', 'c'};

    char caracterFrecuente = encontrarCaracterFrecuente(caracteres);

    cout << "El carácter más frecuente es: " << caracterFrecuente << endl;

    return 0;
}
