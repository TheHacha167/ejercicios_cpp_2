/*
Escriba un programa que lea de la entrada est´andar los dos catetos de un tri´angulo
rect´angulo y escriba en la salida est´andar su hipotenusa.
Entrada caso de prueba: Logitud de los catetos: 3 y 4.
Salida caso de prueba: Longitud de la hipotenusa: 5.

*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double cateto1, cateto2;

    cout << "Introduce la longitud del primer cateto: ";
    cin >> cateto1;

    cout << "Introduce la longitud del segundo cateto: ";
    cin >> cateto2;

    double hipotenusa = sqrt(pow(cateto1, 2) + pow(cateto2, 2));

    cout << "Longitud de la hipotenusa: " << hipotenusa << endl;

    return 0;
}
