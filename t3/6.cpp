/*
Escriba un programa que lea la nota final de cuatro alumnos y calcule la nota final
media de los cuatro alumnos.
Entrada caso de prueba: Notas: 5.6, 6, 10 y 7.2.
Salida caso de prueba: Nota media: 7.2.


*/

#include <iostream>

using namespace std;

int main() {
    double nota1, nota2, nota3, nota4;

    cout << "Introduce la nota del primer alumno: ";
    cin >> nota1;

    cout << "Introduce la nota del segundo alumno: ";
    cin >> nota2;

    cout << "Introduce la nota del tercer alumno: ";
    cin >> nota3;

    cout << "Introduce la nota del cuarto alumno: ";
    cin >> nota4;

    double notaMedia = (nota1 + nota2 + nota3 + nota4) / 4;

    cout << "Nota media: " << notaMedia << endl;

    return 0;
}
