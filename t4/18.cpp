/*
Modifique el programa del ejercicio anterior de manera que s ´olo se acepten edades en
el rango [18,100] o la edad 0, s ´olo se acepte como sexo las letras M y F y s ´olo se acepte
como c´odigo 0 ´o 1.

*/
#include <iostream>

using namespace std;

int main() {
    int edad;
    char sexo;
    int codigoRegistro;
    int totalConductores = 0;
    int menores25 = 0;
    int femenino = 0;
    int masculino18_25 = 0;

    cout << "Introduce los datos de los conductores (edad, sexo, código de registro):" << endl;

    while (true) {
        cout << "Edad (18-100, 0 para terminar): ";
        cin >> edad;

        if (edad == 0 || (edad >= 18 && edad <= 100)) {
            if (edad == 0) {
                break;
            }

            cout << "Sexo (M/F): ";
            cin >> sexo;

            if (sexo == 'M' || sexo == 'F') {
                cout << "Código de registro (0 para fuera de Jaén, 1 para Jaén): ";
                cin >> codigoRegistro;

                if (codigoRegistro == 0 || codigoRegistro == 1) {
                    totalConductores++;

                    if (edad < 25) {
                        menores25++;
                    }

                    if (sexo == 'F') {
                        femenino++;
                    }

                    if (sexo == 'M' && edad >= 18 && edad <= 25) {
                        masculino18_25++;
                    }
                } else {
                    cout << "Código de registro inválido. Introduce nuevamente los datos." << endl;
                }
            } else {
                cout << "Sexo inválido. Introduce nuevamente los datos." << endl;
            }
        } else {
            cout << "Edad inválida. Introduce nuevamente los datos." << endl;
        }
    }

    cout << "Estadísticas:" << endl;
    cout << "Porcentaje de conductores menores de 25 años: " << (static_cast<double>(menores25) / totalConductores) * 100 << "%" << endl;
    cout << "Porcentaje de conductores de sexo femenino: " << (static_cast<double>(femenino) / totalConductores) * 100 << "%" << endl;
    cout << "Porcentaje de conductores masculinos de 18 a 25 años: " << (static_cast<double>(masculino18_25) / totalConductores) * 100 << "%" << endl;

    return 0;
}
