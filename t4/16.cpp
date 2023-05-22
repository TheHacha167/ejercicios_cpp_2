/*
En una clase de 5 alumnos se han realizado tres ex´amenes y se requiere determinar el
n´umero de:
(a) Alumnos que aprobaron todos los ex´amenes.
(b) Alumnos que aprobaron al menos un examen.
(c) Alumnos que aprobaron ´ unicamente el ´ ultimo examen.
Realice un programa que permita la lectura de los datos y el c´alculo de las estad´ısticas.

*/
#include <iostream>

using namespace std;

int main() {
    const int NUM_ALUMNOS = 5;
    int notas[NUM_ALUMNOS][3];
    int aprobadosTodos = 0;
    int aprobadosAlMenosUno = 0;
    int aprobadosUltimo = 0;

    // Lectura de las notas de los alumnos
    cout << "Introduce las notas de los alumnos (0 para no aprobado, 1 para aprobado):" << endl;
    for (int i = 0; i < NUM_ALUMNOS; i++) {
        cout << "Alumno " << i + 1 << ": ";
        for (int j = 0; j < 3; j++) {
            cin >> notas[i][j];
        }
    }

    // Cálculo de las estadísticas
    for (int i = 0; i < NUM_ALUMNOS; i++) {
        bool aproboTodos = true;
        bool aproboAlMenosUno = false;
        bool aproboUltimo = false;

        for (int j = 0; j < 3; j++) {
            if (notas[i][j] == 0) {
                aproboTodos = false;
            } else {
                aproboAlMenosUno = true;
            }

            if (j == 2 && notas[i][j] == 1) {
                aproboUltimo = true;
            }
        }

        if (aproboTodos) {
            aprobadosTodos++;
        }

        if (aproboAlMenosUno) {
            aprobadosAlMenosUno++;
        }

        if (aproboUltimo) {
            aprobadosUltimo++;
        }
    }

    // Resultados
    cout << "Estadísticas:" << endl;
    cout << "Alumnos que aprobaron todos los exámenes: " << aprobadosTodos << endl;
    cout << "Alumnos que aprobaron al menos un examen: " << aprobadosAlMenosUno << endl;
    cout << "Alumnos que aprobaron únicamente el último examen: " << aprobadosUltimo << endl;

    return 0;
}
