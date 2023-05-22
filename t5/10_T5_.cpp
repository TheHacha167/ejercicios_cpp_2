/*

Escriba un programa que lea el nombre y la nota de 10 alumnos y calcule la calificaci ´on
promedio. El programa debe mostrar en la salida est´andar el nombre de aquellos
alumnos cuya nota supera la media. Haga dos versiones del programa. En la primera
versi´on utilice dos vectores: uno para almacenar las notas de los alumnos y otro para
almacenar sus nombres. En la segunda versi´on del programa utilice un ´ unico vector
de estructuras de tipo alumno con dos campos: nota y nombre.
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    const int numAlumnos = 10;

    vector<string> nombres(numAlumnos);
    vector<double> notas(numAlumnos);

    double sumaNotas = 0.0;

    cout << "Ingrese el nombre y la nota de los " << numAlumnos << " alumnos:" << endl;

    for (int i = 0; i < numAlumnos; i++) {
        cout << "Alumno " << i + 1 << ":" << endl;
        cin >> nombres[i] >> notas[i];
        sumaNotas += notas[i];
    }

    double promedio = sumaNotas / numAlumnos;

    cout << "Alumnos con nota superior al promedio:" << endl;

    for (int i = 0; i < numAlumnos; i++) {
        if (notas[i] > promedio) {
            cout << nombres[i] << endl;
        }
    }

    return 0;
}
