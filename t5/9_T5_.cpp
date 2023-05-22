/*
9. Escribe un programa que calcule la desviaci´on t´ıpica de n n´umeros. El valor de n se lee
de la entrada est´andar. 
Entrada caso de prueba: 2.3, 4, 7, 1.2, 10, 5
Salida caso de prueba: 3.21522


*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double calcularMedia(const vector<double>& numeros) {
    double suma = 0.0;
    for (double num : numeros) {
        suma += num;
    }
    return suma / numeros.size();
}

double calcularDesviacionTipica(const vector<double>& numeros) {
    double media = calcularMedia(numeros);
    double sumaCuadrados = 0.0;
    for (double num : numeros) {
        sumaCuadrados += pow(num - media, 2);
    }
    double varianza = sumaCuadrados / numeros.size();
    return sqrt(varianza);
}

int main() {
    int n;
    cout << "Ingrese la cantidad de números: ";
    cin >> n;

    vector<double> numeros(n);

    cout << "Ingrese los números:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> numeros[i];
    }

    double desviacionTipica = calcularDesviacionTipica(numeros);

    cout << "La desviación típica es: " << desviacionTipica << endl;

    return 0;
}
