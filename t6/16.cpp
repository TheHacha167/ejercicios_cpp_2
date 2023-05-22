/*
Realice una funci´on que implemente un men´u de opciones. La funci´on debe mostrar
en la salida est´andar una serie de opciones precedidas por un n´umero. Por ejemplo:
0 - Introducir palabra
1 - Adivinar palabra
2 - Salir
Introduzca la opcion elegida:
La funci´on debe leer de la entrada est´andar la opci´on elegida por el usuario, hasta que
se lea un valor de opci´on*/
#include <iostream>
#include <vector>

bool esNumeroPerfecto(int num) {
    int suma = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            suma += i;
        }
    }
    return suma == num;
}

std::vector<int> obtenerNumerosPerfectos(int n) {
    std::vector<int> perfectos;
    int num = 1;
    while (perfectos.size() < n) {
        if (esNumeroPerfecto(num)) {
            perfectos.push_back(num);
        }
        num++;
    }
    return perfectos;
}

int main() {
    int n;
    std::cout << "Ingrese el valor de n: ";
    std::cin >> n;

    std::vector<int> numerosPerfectos = obtenerNumerosPerfectos(n);

    std::cout << "Los primeros " << n << " numeros perfectos son: ";
    for (int num : numerosPerfectos) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
