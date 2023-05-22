/*

Los reglamentos de pesca imponen un l´ımite a la cantidad total de kilos permitida en
un d´ıa de pesca. Dise ˜ne un programa que, en primer lugar, lea el l´ımite diario—en
kilos. A continuaci´on el programa debe leer los pesos de las presas seg ´un el orden
en que se pescaron—un valor de cero indica el final de las presas. El programa debe
mostrar tras cada presa introducida el peso total acumulado. Si en un momento dado
se excede la cantidad total de kilos permitida, entonces el programa debe mostrar un
mensaje indicativo y terminar.

*/
#include <iostream>

using namespace std;

int main() {
    double limiteDiario;
    double pesoPresa;
    double pesoTotal = 0;

    cout << "Introduce el límite diario de kilos permitido: ";
    cin >> limiteDiario;

    cout << "Introduce los pesos de las presas (0 para terminar): ";

    while (cin >> pesoPresa && pesoPresa != 0) {
        pesoTotal += pesoPresa;

        if (pesoTotal > limiteDiario) {
            cout << "¡Has excedido el límite diario de kilos permitido!" << endl;
            return 0;
        }

        cout << "Peso total acumulado: " << pesoTotal << " kg" << endl;
    }

    cout << "Fin del programa. Peso total acumulado: " << pesoTotal << " kg" << endl;

    return 0;
}
