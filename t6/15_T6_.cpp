/*
Realice una funci´on con las siguientes caracter´ısticas:
 Entradas: un entero positivo n.
 Salidas: un vector de enteros con los primeros n n´umeros perfectos. Un n´umero
perfecto es un n´umero natural que es igual a la suma de sus divisores positivos,
sin incluirse ´el mismo. As´ı, 6 es un n´umero perfecto, porque sus divisores positivos
son 1, 2 y 3; y 6 = 1 + 2 + 3. El siguiente n´umero perfecto es el 28.
Sugerencia: puede implementar una funci´on auxiliar que dado un entero positivo devuelva
si es perfecto.
*/
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
