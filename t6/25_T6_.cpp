/*
Dado un vector de n n´umeros enteros, construya un programa que calcule el n´umero
de veces que aparece cada entero en el vector.
*/
#include <iostream>
#include <vector>
#include <unordered_map>

void contarApariciones(const std::vector<int>& numeros) {
    std::unordered_map<int, int> apariciones;

    // Contar apariciones de cada entero en el vector
    for (int num : numeros) {
        apariciones[num]++;
    }

    // Imprimir el número de apariciones de cada entero
    for (const auto& par : apariciones) {
        std::cout << "El entero " << par.first << " aparece " << par.second << " veces" << std::endl;
    }
}

int main() {
    std::vector<int> numeros = {1, 2, 3, 2, 4, 1, 2, 3, 4, 5, 1};

    contarApariciones(numeros);

    return 0;
}
