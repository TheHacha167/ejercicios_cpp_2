/*
Implementa un programa que solicite el n´umero de esca ˜nos a repartir y el n´umero
de votos obtenido por los distintos partidos y calcule cu´antos esca ˜nos obtendr´ıa cada
partido siguiendo el sistema D’Hont.
*/
#include <iostream>
#include <vector>
#include <algorithm>

struct Partido {
    std::string nombre;
    int votos;
    int escaños;
};

bool compararVotos(const Partido& partido1, const Partido& partido2) {
    return partido1.votos > partido2.votos;
}

void calcularEscaños(std::vector<Partido>& partidos, int numEscanos) {
    std::sort(partidos.begin(), partidos.end(), compararVotos);

    for (int i = 0; i < numEscanos; ++i) {
        partidos[i].escaños++;
        partidos[i].votos /= (partidos[i].escaños + 1);
    }
}

int main() {
    int numPartidos;
    int numEscanos;

    std::cout << "Ingrese el número de partidos: ";
    std::cin >> numPartidos;

    std::cout << "Ingrese el número de escaños a repartir: ";
    std::cin >> numEscanos;

    std::vector<Partido> partidos(numPartidos);

    for (int i = 0; i < numPartidos; ++i) {
        std::cout << "Partido #" << i + 1 << std::endl;
        std::cout << "Nombre: ";
        std::cin >> partidos[i].nombre;
        std::cout << "Número de votos: ";
        std::cin >> partidos[i].votos;
        partidos[i].escaños = 0;
        std::cout << std::endl;
    }

    calcularEscaños(partidos, numEscanos);

    std::cout << "Resultado del reparto de escaños:" << std::endl;
    std::cout << "=============================" << std::endl;

    for (const auto& partido : partidos) {
        std::cout << "Partido: " << partido.nombre << std::endl;
        std::cout << "Número de escaños: " << partido.escaños << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
