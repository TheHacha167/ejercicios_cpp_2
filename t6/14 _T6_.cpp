/*
Realiza una funci´on que tome como par´ametros un vector de enteros y su tama˜no y
devuelva un vector con los elementos impares del vector recibido.
*/
#include <iostream>
#include <vector>

std::vector<int> obtenerElementosImpares(const std::vector<int>& vec) {
    std::vector<int> impares;
    for (int num : vec) {
        if (num % 2 != 0) {
            impares.push_back(num);
        }
    }
    return impares;
}

int main() {
    std::vector<int> numeros = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::vector<int> impares = obtenerElementosImpares(numeros);

    std::cout << "Elementos impares: ";
    for (int num : impares) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
