/*
Escribe un programa que asigne valores a dos variables del mismo tipo y despu´es
intercambie los valores de las dos variables. Sugerencia: ap´oyese en una variable auxiliar.
*/
#include <iostream>

using namespace std;

int main() {
    int variable1, variable2, aux;

    cout << "Introduce el valor de la primera variable: ";
    cin >> variable1;

    cout << "Introduce el valor de la segunda variable: ";
    cin >> variable2;

    // Se muestra los valores iniciales
    cout << "Valores iniciales:" << endl;
    cout << "Primera variable: " << variable1 << endl;
    cout << "Segunda variable: " << variable2 << endl;

    // Se intercambian los valores usando una variable auxiliar
    aux = variable1;
    variable1 = variable2;
    variable2 = aux;

    // Se muestran los valores después del intercambio
    cout << "Valores después del intercambio:" << endl;
    cout << "Primera variable: " << variable1 << endl;
    cout << "Segunda variable: " << variable2 << endl;

    return 0;
}
