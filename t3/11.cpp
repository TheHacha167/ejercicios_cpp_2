/*

Suponiendo que el recibo de la luz sube un 3% cada a˜ no, realice un programa que
solicite una factura de este a˜no y una cantidad de a˜nos y muestre en la salida est´andar
cu´anto valdr´ıa la factura dentro del n´umero de a˜nos introducidos.
Entrada caso de prueba: Factura: 100 euros. N´umero de a˜ nos: 3.
Salida caso de prueba: Factura: 109.273.

*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double factura;
    int anos;

    cout << "Introduce el valor de la factura de este año: ";
    cin >> factura;

    cout << "Introduce el número de años: ";
    cin >> anos;

    double facturaFutura = factura * pow(1.03, anos);

    cout << "Factura: " << facturaFutura << " euros." << endl;

    return 0;
}
