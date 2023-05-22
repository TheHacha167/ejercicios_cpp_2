/*
Una compa˜n´ıa de seguros est´a preparando un estudio concerniente a todos los accidentes
ocurridos en la provincia de Ja´en en el ´ ultimo a˜ no. Para cada conductor involucrado
en un accidente se tienen los siguientes datos: edad del conductor, sexo—’M’
o ’F’—y c´odigo de registro—1 para los registrados en la ciudad de Ja´en, 0 para los
registrados fuera de la ciudad de Ja´en. Realice un programa que lea los datos de conductores
hasta que se introduzca una edad de 0 y muestre las siguientes estad´ısticas:
(a) Porcentaje de conductores menores de 25 a˜nos
(b) Porcentaje de conductores de sexo femenino.
(c) De los conductores de sexo masculino porcentaje de conductores con edades comprendidas
entre 18 y 25 a˜ nos.

*/#include <iostream>

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
        cout << "Edad (0 para terminar): ";
        cin >> edad;

        if (edad == 0) {
            break;
        }

        cout << "Sexo (M/F): ";
        cin >> sexo;

        cout << "Código de registro (1 para Jaén, 0 para fuera de Jaén): ";
        cin >> codigoRegistro;

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
    }

    cout << "Estadísticas:" << endl;
    cout << "Porcentaje de conductores menores de 25 años: " << (static_cast<double>(menores25) / totalConductores) * 100 << "%" << endl;
    cout << "Porcentaje de conductores de sexo femenino: " << (static_cast<double>(femenino) / totalConductores) * 100 << "%" << endl;
    cout << "Porcentaje de conductores masculinos de 18 a 25 años: " << (static_cast<double>(masculino18_25) / totalConductores) * 100 << "%" << endl;

    return 0;
}
