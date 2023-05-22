/*

Realiza una funci´on que tome como par´ametros un vector de n´umeros y su tama˜no y
cambie el signo de los elementos del vector.
*/
#include <iostream>
#include <vector>

void cambiarSigno(std::vector<int>& vec, int tam) {
    for (int i = 0; i < tam; i++) {
        vec[i] = -vec[i];
    }
}

int main() {
    std::vector<int> numeros = {1, -2, 3, -4, 5};

    int tam = numeros.size();

    cambiarSigno(numeros, tam);

    std::cout << "Vector modificado: ";
    for (int i = 0; i < tam; i++) {
        std::cout << numeros[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
