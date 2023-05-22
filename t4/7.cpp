/*

Escriba un programa que tome cada 4 horas la temperatura exterior, ley´endola durante
un per´ıodo de 24 horas. Es decir, debe leer 6 temperaturas. Calcule la temperatura
media del d´ıa, la temperatura m´as alta y la m´as baja.

*/
#include <iostream>

using namespace std;

int main() {
    const int NUM_TEMPERATURAS = 6;
    const int INTERVALO_HORAS = 4;
    int INT_MIN = 0, INT_MAX = 0;
    int temperatura;
    int sumaTemperaturas = 0;
    int temperaturaMaxima = INT_MIN;
    int temperaturaMinima = INT_MAX;

    for (int i = 1; i <= NUM_TEMPERATURAS; i++) {
        cout << "Introduce la temperatura exterior después de " << (i - 1) * INTERVALO_HORAS << " horas: ";
        cin >> temperatura;

        sumaTemperaturas += temperatura;

        if (temperatura > temperaturaMaxima) {
            temperaturaMaxima = temperatura;
        }

        if (temperatura < temperaturaMinima) {
            temperaturaMinima = temperatura;
        }
    }

    double temperaturaMedia = static_cast<double>(sumaTemperaturas) / NUM_TEMPERATURAS;

    cout << "Temperatura media del día: " << temperaturaMedia << endl;
    cout << "Temperatura más alta del día: " << temperaturaMaxima << endl;
    cout << "Temperatura más baja del día: " << temperaturaMinima << endl;

    return 0;
}
