/*

Escriba un programa que lea de la entrada est´andar un car´acter e indique en la salida
est´andar si el car´acter es una vocal min´ uscula o no.

*/
#include <iostream>

using namespace std;

int main() {
    char c;

    cout << "Introduce un carácter: ";
    cin >> c;

    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        cout << "El carácter " << c << " es una vocal minúscula." << endl;
    } else {
        cout << "El carácter " << c << " no es una vocal minúscula." << endl;
    }

    return 0;
}
