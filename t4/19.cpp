/*

El algoritmo de Euclides es un procedimiento para calcular el m´aximo com´un divisor
de dos n´umeros naturales. Los pasos son:
(a) Se divide el n´umero mayor (M) entre el menor (m).
(b) Si:
i. La divisi ´on es exacta, entonces m es el m´aximo com´un divisor.
ii. La divisi ´on no es exacta, entonces mcd(M;m) = mcd(m;M%m).
Por ejemplo, vamos a calcular el m´aximo com´un divisor de 93164 y 5826:
(a) 93164 entre 5826 es 15 y sobran 5774, luego mcd(93164; 5826) = mcd(5826; 5774).
(b) 5826 entre 5774 es 1 y sobran 52, luego mcd(5826; 5774) = mcd(5774; 52).
(c) 52 entre 2 es 26 y sobran 0, luego mcd(52; 2) = 2 = mcd(93164; 5826).
Escribe un programa que implemente este algoritmo.


*/
#include <iostream>

using namespace std;

int calcularMCD(int a, int b) {
    // Aplicar el algoritmo de Euclides
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a; // Retornar el máximo común divisor
}

int main() {
    int num1, num2;

    cout << "Ingrese el primer número: ";
    cin >> num1;

    cout << "Ingrese el segundo número: ";
    cin >> num2;

    // Calcular el MCD utilizando el algoritmo de Euclides
    int mcd = calcularMCD(num1, num2);

    // Mostrar el resultado
    cout << "El máximo común divisor (MCD) de " << num1 << " y " << num2 << " es: " << mcd << endl;

    return 0;
}
