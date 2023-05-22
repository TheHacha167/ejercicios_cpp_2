/*

Escriba un programa que lea de la entrada est´andar tres n´umeros. Despu´es debe leer
un cuarto n´umero e indicar si el n´umero coincide con alguno de los introducidos con
anterioridad. Utiliza una ´ unica instrucci´on if con una expresi ´on l ´ogica compuesta.

*/
#include <iostream>

using namespace std;

int main() {
    int num1, num2, num3, num4;

    cout << "Introduce el primer número: ";
    cin >> num1;
    cout << "Introduce el segundo número: ";
    cin >> num2;
    cout << "Introduce el tercer número: ";
    cin >> num3;
    cout << "Introduce el cuarto número: ";
    cin >> num4;

    if (num4 == num1 || num4 == num2 || num4 == num3) {
        cout << "El cuarto número coincide con alguno de los introducidos anteriormente." << endl;
    } else {
        cout << "El cuarto número no coincide con ninguno de los introducidos anteriormente." << endl;
    }

    return 0;
}

