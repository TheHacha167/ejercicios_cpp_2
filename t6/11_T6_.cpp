/*
Realice una funci´on que tome como par´ametros un vector y su tama˜no y diga si el vector
est´a ordenado crecientemente. Sugerencia: un vector est´a ordenado crecientemente
si para todas las posiciones del vector, salvo para la 0, el elemento del vector es mayor
o igual que el elemento que le precede en el vector—equivalentemente, est´a desordenado
si para alguna posici´on del vector el elemento en dicha posici´on es menor que el
elemento que le precede en el vector.

*/
#include <iostream>
#include <vector>

bool estaOrdenado(const std::vector<int>& vec, int tam) {
    for (int i = 1; i < tam; i++) {
        if (vec[i] < vec[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<int> numeros = {1, 2, 3, 4, 5};

    int tam = numeros.size();

    bool ordenado = estaOrdenado(numeros, tam);

    if (ordenado) {
        std::cout << "El vector está ordenado crecientemente." << std::endl;
    } else {
        std::cout << "El vector no está ordenado crecientemente." << std::endl;
    }

    return 0;
}
