/*
Realice un programa que dado un vector de n´umeros reales obtenga la menor diferencia
absoluta entre dos elementos consecutivos del vector. Puedes usar la funci´on abs
de la biblioteca cmath para calcular el valor absoluto de una expresi ´on—por ejemplo,
abs(􀀀2) vale 2.
Entrada caso de prueba: vector f2; 10; 20; 7; 34:2; 5:4;􀀀1:2; 8:8; 90:0; 2:0g
Salida caso de prueba: 6.6


*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double calcularMenorDiferencia(const vector<double>& numeros) {
    double menorDiferencia = abs(numeros[1] - numeros[0]);

    for (int i = 2; i < numeros.size(); i++) {
        double diferencia = abs(numeros[i] - numeros[i-1]);
        if (diferencia < menorDiferencia) {
            menorDiferencia = diferencia;
        }
    }

    return menorDiferencia;
}

int main() {
    vector<double> numeros = {2.0, 10.0, 20.0, 7.0, 34.2, 5.4, -1.2, 8.8, 90.0, 2.0};

    double menorDiferencia = calcularMenorDiferencia(numeros);

    cout << "La menor diferencia absoluta entre elementos consecutivos es: " << menorDiferencia << endl;

    return 0;
}
