/*

6. Escriba un programa que lea tres n´umeros y determine cu´al de ellos es el mayor.
*/
#include <iostream>

using namespace std;

int main() {
    double num1, num2, num3;

    cout << "Introduce el primer número: ";
    cin >> num1;
    cout << "Introduce el segundo número: ";
    cin >> num2;
    cout << "Introduce el tercer número: ";
    cin >> num3;

    if (num1 >= num2 && num1 >= num3) {
        cout << "El número mayor es: " << num1 << endl;
    } else if (num2 >= num1 && num2 >= num3) {
        cout << "El número mayor es: " << num2 << endl;
    } else {
        cout << "El número mayor es: " << num3 << endl;
    }

    return 0;
}
