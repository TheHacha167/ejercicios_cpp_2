/*
Defina una estructura que indique el tiempo empleado por un ciclista en una etapa. La
estructura debe tener tres campos: horas, minutos y segundos. Escriba un programa
que dado un vector con los tiempos que un ciclista ha empleado en cada etapa calcule
el tiempo total empleado en correr todas las etapas.
*/
#include <iostream>
#include <vector>

struct Tiempo {
    int horas;
    int minutos;
    int segundos;
};

Tiempo sumarTiempos(const Tiempo& tiempo1, const Tiempo& tiempo2) {
    Tiempo resultado;
    resultado.horas = tiempo1.horas + tiempo2.horas;
    resultado.minutos = tiempo1.minutos + tiempo2.minutos;
    resultado.segundos = tiempo1.segundos + tiempo2.segundos;

    if (resultado.segundos >= 60) {
        resultado.minutos += resultado.segundos / 60;
        resultado.segundos %= 60;
    }
    if (resultado.minutos >= 60) {
        resultado.horas += resultado.minutos / 60;
        resultado.minutos %= 60;
    }

    return resultado;
}

Tiempo calcularTiempoTotal(const std::vector<Tiempo>& tiempos) {
    Tiempo tiempoTotal = {0, 0, 0};
    for (const auto& tiempo : tiempos) {
        tiempoTotal = sumarTiempos(tiempoTotal, tiempo);
    }
    return tiempoTotal;
}

int main() {
    std::vector<Tiempo> tiempos = {
        {2, 30, 45},
        {1, 20, 15},
        {0, 45, 30}
    };

    Tiempo tiempoTotal = calcularTiempoTotal(tiempos);

    std::cout << "Tiempo total empleado: "
              << tiempoTotal.horas << " horas, "
              << tiempoTotal.minutos << " minutos, "
              << tiempoTotal.segundos << " segundos" << std::endl;

    return 0;
}
