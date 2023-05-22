/*
Escriba un programa que lea cuatro n´umeros y determine cu´al de ellos es el mayor.

*/
#include <iostream>

using namespace std;

int main() {
    double num1, num2, num3, num4;

    cout << "Introduce el primer número: ";
    cin >> num1;
    cout << "Introduce el segundo número: ";
    cin >> num2;
    cout << "Introduce el tercer número: ";
    cin >> num3;
    cout << "Introduce el cuarto número: ";
    cin >> num4;

    double maxNum = num1;

    if (num2 > maxNum) {
        maxNum = num2;
    } 
    if (num3 > maxNum) {
        maxNum = num3;
    } 
    if (num4 > maxNum) {
        maxNum = num4;
    } 

    cout << "El número mayor es: " << maxNum << endl;

    return 0;
}
