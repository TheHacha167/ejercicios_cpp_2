/*

5. Escriba un programa que lea dos n´umeros y determine cu´al de ellos es el mayor.

*/
#include <iostream>

using namespace std;

int main() {
    double num1, num2;

    cout << "Introduce el primer número: ";
    cin >> num1;
    cout << "Introduce el segundo número: ";
    cin >> num2;

    if (num1 > num2) {
        cout << "El número mayor es: " << num1 << endl;
    } else if (num2 > num1) {
        cout << "El número mayor es: " << num2 << endl;
    } else {
        cout << "Los números son iguales." << endl;
    }

    return 0;
}
