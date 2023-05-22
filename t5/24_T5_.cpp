/*
Dada una matriz notas cuyo elemento notas[i ][ j ] contiene la calificaci ´on del j -´esimo
problema de un examen del i-´esimo estudiante, y un factor de ponderaci´on pesos,
cuyo elemento pesos[j ] denota la ponderaci´on correspondiente al j -´esimo problema de
un examen, formule un programa que construya un vector alumno, de tal forma que
alumno[i] contenga la calificaci ´on final del i-´esimo estudiante.
*/
#include <iostream>
#include <vector>

const int NUM_ESTUDIANTES = 5;
const int NUM_PROBLEMAS = 3;

void calcularCalificacionesFinales(const std::vector<std::vector<double>>& notas, const std::vector<double>& pesos, std::vector<double>& alumno) {
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        double calificacionFinal = 0.0;
        for (int j = 0; j < NUM_PROBLEMAS; j++) {
            calificacionFinal += notas[i][j] * pesos[j];
        }
        alumno[i] = calificacionFinal;
    }
}

void mostrarCalificacionesFinales(const std::vector<double>& alumno) {
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        std::cout << "Estudiante " << i + 1 << ": " << alumno[i] << std::endl;
    }
}

int main() {
    std::vector<std::vector<double>> notas(NUM_ESTUDIANTES, std::vector<double>(NUM_PROBLEMAS));
    std::vector<double> pesos(NUM_PROBLEMAS);
    std::vector<double> alumno(NUM_ESTUDIANTES);

    // Leer las notas de los estudiantes
    std::cout << "Ingrese las notas de los estudiantes:" << std::endl;
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        std::cout << "Estudiante " << i + 1 << ":" << std::endl;
        for (int j = 0; j < NUM_PROBLEMAS; j++) {
            std::cin >> notas[i][j];
        }
    }

    // Leer las ponderaciones de los problemas
    std::cout << "Ingrese las ponderaciones de los problemas:" << std::endl;
    for (int j = 0; j < NUM_PROBLEMAS; j++) {
        std::cin >> pesos[j];
    }

    calcularCalificacionesFinales(notas, pesos, alumno);

    std::cout << "Calificaciones finales:" << std::endl;
    mostrarCalificacionesFinales(alumno);

    return 0;
}
