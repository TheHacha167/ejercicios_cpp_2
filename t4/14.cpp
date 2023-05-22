/*

Escribe un programa que lea un n´umero entero no negativo n y dibuje un tri´angulo
rect´angulo con base y altura n como el que se muestra a continuaci´on para n = 4.
Observa que debe aparecer un espacio entre cada asterisco situado en la misma l´ınea:
*
* *
* * *
* * * *

*/
#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Introduce un número entero no negativo: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}
