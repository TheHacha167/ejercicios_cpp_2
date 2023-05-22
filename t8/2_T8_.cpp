/*
La serie de Fibonacci est´a formada por la secuencia de n´umeros: 0, 1, 1, 2, 3, 5, 8, 13,
21, 34, . . . Por definici´on, los dos primeros n´umeros de la serie son 0 y 1 y los n´umeros
siguientes se calculan como la suma de los dos n´umeros previos de la secuencia. Realice
un programa que solicite al usuario un n´umero n y calcule y muestre en la pantalla
los primeros n n´umeros de la serie de Fibonacci. Almacena los n´umeros de la serie en
un vector din´amico.
*/
#include <iostream>

int* calcularFibonacci(int n) {
    int* fibonacci = new int[n];

    fibonacci[0] = 0;
    if (n > 1) {
        fibonacci[1] = 1;
        for (int i = 2; i < n; ++i) {
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        }
    }

    return fibonacci;
}

void mostrarVector(int* vector, int tamaño) {
    for (int i = 0; i < tamaño; ++i) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "Ingrese el número de elementos de la serie de Fibonacci a calcular: ";
    std::cin >> n;

    int* fibonacci = calcularFibonacci(n);

    std::cout << "Serie de Fibonacci de " << n << " elementos: ";
    mostrarVector(fibonacci, n);

    delete[] fibonacci;

    return 0;
}
