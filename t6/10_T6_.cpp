/*
Realice una funci´on que tome como par´ametros un vector de n´umeros y devuelva la
suma de sus elementos.

*/
#include <iostream>
#include <vector>

int sumaVector(const std::vector<int>& vec) {
    int suma = 0;
    for (int num : vec) {
        suma += num;
    }
    return suma;
}

int main() {
    std::vector<int> numeros = {1, 2, 3, 4, 5};

    int resultado = sumaVector(numeros);

    std::cout << "La suma de los elementos del vector es: " << resultado << std::endl;

    return 0;
}
