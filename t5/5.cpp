/*

La calificaci ´on final de un estudiante es la media ponderada de tres notas: la nota de
pr´acticas que cuenta un 30% del total, la nota te ´orica que cuenta un 60% y la nota de
participaci´on que cuenta el 10% restante. Escriba un programa que lea de la entrada
est´andar las tres notas de un alumno y escriba en la salida est´andar su nota final.

Entrada caso de prueba: Nota de pr´acticas (6), nota de teor´ıa (8) y nota de participaci
´on (10).
Salida caso de prueba: Nota final (7.6).

*/
#include <iostream>

using namespace std;

int main() {
    double notaPracticas, notaTeoria, notaParticipacion;

    cout << "Introduce la nota de prácticas: ";
    cin >> notaPracticas;

    cout << "Introduce la nota de teoría: ";
    cin >> notaTeoria;

    cout << "Introduce la nota de participación: ";
    cin >> notaParticipacion;

    double notaFinal = notaPracticas * 0.3 + notaTeoria * 0.6 + notaParticipacion * 0.1;

    cout << "Nota final: " << notaFinal << endl;

    return 0;
}
