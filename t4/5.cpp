/*

Realice un programa que lea de la entrada est´andar n´umeros hasta que se introduzca
un cero–es decir, es una lectura con centinela donde el centinela es el valor 0. En ese
momento el programa debe terminar y mostrar en la salida est´andar la cantidad de
valores mayores que cero le´ıdos.

*/
#include <iostream>

using namespace std;

int main() {
    int numero;
    int cantidadMayoresCero = 0;

    cout << "Introduce números enteros (0 para terminar): ";

    do {
        cin >> numero;
        if (numero > 0) {
            cantidadMayoresCero++;
        }
    } while (numero != 0);

    cout << "Cantidad de valores mayores que cero leídos: " << cantidadMayoresCero << endl;

    return 0;
}
