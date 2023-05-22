/*
En un congreso cuya duraci´on es de 5 d´ıas, tienen lugar conferencias en 5 salas. Se
desea saber:
(a) El total de congresistas que asisten a cada una de las salas.
(b) El total de congresistas asistentes cada d´ıa al congreso.
(c) La media de asistencia a cada sala.
(d) La media de asistencia diaria.
Como datos de entrada tenemos el n´umero de asistentes para las diferentes salas, para
cada uno de los d´ıas del congreso. Realice un programa que calcule estos datos.
*/
#include <iostream>
#include <vector>

const int NUM_DIAS = 5;
const int NUM_SALAS = 5;

void calcularTotalCongresistasSala(const std::vector<std::vector<int>>& asistencia, std::vector<int>& totalCongresistasSala) {
    for (int i = 0; i < NUM_SALAS; i++) {
        int total = 0;
        for (int j = 0; j < NUM_DIAS; j++) {
            total += asistencia[j][i];
        }
        totalCongresistasSala[i] = total;
    }
}

void calcularTotalCongresistasDia(const std::vector<std::vector<int>>& asistencia, std::vector<int>& totalCongresistasDia) {
    for (int i = 0; i < NUM_DIAS; i++) {
        int total = 0;
        for (int j = 0; j < NUM_SALAS; j++) {
            total += asistencia[i][j];
        }
        totalCongresistasDia[i] = total;
    }
}

double calcularMediaSala(const std::vector<int>& totalCongresistasSala) {
    double suma = 0;
    for (int i = 0; i < NUM_SALAS; i++) {
        suma += totalCongresistasSala[i];
    }
    return suma / NUM_SALAS;
}

double calcularMediaDia(const std::vector<int>& totalCongresistasDia) {
    double suma = 0;
    for (int i = 0; i < NUM_DIAS; i++) {
        suma += totalCongresistasDia[i];
    }
    return suma / NUM_DIAS;
}

int main() {
    std::vector<std::vector<int>> asistencia(NUM_DIAS, std::vector<int>(NUM_SALAS));
    std::vector<int> totalCongresistasSala(NUM_SALAS);
    std::vector<int> totalCongresistasDia(NUM_DIAS);

    // Leer la asistencia de los congresistas
    std::cout << "Ingrese la asistencia de los congresistas por sala y día:" << std::endl;
    for (int i = 0; i < NUM_DIAS; i++) {
        std::cout << "Día " << i + 1 << ":" << std::endl;
        for (int j = 0; j < NUM_SALAS; j++) {
            std::cin >> asistencia[i][j];
        }
    }

    calcularTotalCongresistasSala(asistencia, totalCongresistasSala);
    calcularTotalCongresistasDia(asistencia, totalCongresistasDia);

    std::cout << "Total de congresistas por sala:" << std::endl;
    for (int i = 0; i < NUM_SALAS; i++) {
        std::cout << "Sala " << i + 1 << ": " << totalCongresistasSala[i] << std::endl;
    }

    std::cout << "Total de congresistas por día:" << std::endl;
    for (int i = 0; i < NUM_DIAS; i++) {
        std::cout << "Día " << i + 1 << ": " << totalCongresistasDia[i] << std::endl;
    }

    std::cout << "Media de asistencia por sala: " << calcularMediaSala(totalCongresistasSala) << std::endl;
    std::cout << "Media de asistencia por día: " << calcularMediaDia(totalCongresistasDia) << std::endl;

    return 0;
}
