/*
Escriba un programa que almacene y trate la informaci´on sobre las elecciones a delegado
de una clase. El programa debe leer el n´umero de candidatos que se presentan a
delegado (al menos deben presentarse 3 alumnos). Para cada candidato el programa
debe leer su nombre, DNI y fecha de nacimiento. A continuaci´on, el programa debe ir
leyendo y almacenando en una estructura adecuada los votos emitidos por cada uno
de los alumnos presentes en la clase. El voto ser´a un n´umero entero que indica lo
siguiente:
 Si el n´umero es 0 el voto se considera “voto en blanco”.
 Si el n´umero est´a en el intervalo [1;N], siendo N el n´umero de candidatos, el voto
se contabilizar´a como voto para el candidato correspondiente.
 Si el n´umero es -1, significa que la emisi´on de votos ha finalizado.
 Si el n´umero es distinto a los anteriores, el voto se considera “voto nulo”.
El programa debe mostrar el n´umero de votos emitidos, el n´umero de votos nulos, el
n´umero de votos en blanco y el n´umero de votos conseguidos por cada candidato,
mostrando adem´as su nombre. Por ´ ultimo, el programa debe determinar los candidatos
que han resultado elegidos como delegado y subdelegado mostrando su nombre,
DNI y fecha de nacimiento. Si m´as de un candidato empataron con el mayor
n´umero de votos elija como delegado y subdelegado a cualquiera de los candidatos.
*/
#include <iostream>
#include <vector>
#include <string>

struct Candidato {
    std::string nombre;
    std::string dni;
    std::string fechaNacimiento;
    int votos;
};

void mostrarResultados(const std::vector<Candidato>& candidatos, int votosTotales, int votosNulos, int votosBlancos) {
    std::cout << "Resultados de las elecciones:" << std::endl;
    std::cout << "=============================" << std::endl;
    std::cout << "Número total de votos emitidos: " << votosTotales << std::endl;
    std::cout << "Número de votos nulos: " << votosNulos << std::endl;
    std::cout << "Número de votos en blanco: " << votosBlancos << std::endl;

    int maxVotos = 0;
    std::vector<Candidato> ganadores;

    for (const auto& candidato : candidatos) {
        std::cout << "Candidato: " << candidato.nombre << std::endl;
        std::cout << "DNI: " << candidato.dni << std::endl;
        std::cout << "Fecha de nacimiento: " << candidato.fechaNacimiento << std::endl;
        std::cout << "Número de votos: " << candidato.votos << std::endl;
        std::cout << std::endl;

        if (candidato.votos > maxVotos) {
            maxVotos = candidato.votos;
            ganadores.clear();
            ganadores.push_back(candidato);
        } else if (candidato.votos == maxVotos) {
            ganadores.push_back(candidato);
        }
    }

    std::cout << "Candidatos elegidos:" << std::endl;
    std::cout << "====================" << std::endl;

    for (const auto& ganador : ganadores) {
        std::cout << "Delegado/Subdelegado: " << ganador.nombre << std::endl;
        std::cout << "DNI: " << ganador.dni << std::endl;
        std::cout << "Fecha de nacimiento: " << ganador.fechaNacimiento << std::endl;
        std::cout << std::endl;
    }
}

int main() {
    int numCandidatos;

    do {
        std::cout << "Ingrese el número de candidatos (al menos 3): ";
        std::cin >> numCandidatos;
    } while (numCandidatos < 3);

    std::vector<Candidato> candidatos(numCandidatos);

    for (int i = 0; i < numCandidatos; ++i) {
        std::cout << "Candidato #" << i + 1 << std::endl;
        std::cout << "Nombre: ";
        std::cin >> candidatos[i].nombre;
        std::cout << "DNI: ";
        std::cin >> candidatos[i].dni;
        std::cout << "Fecha de nacimiento: ";
        std::cin >> candidatos[i].fechaNacimiento;
        candidatos[i].votos = 0;
        std::cout << std::endl;
    }

    int voto;
    int votosTotales = 0;
    int votosNulos = 0;
    int votosBlancos = 0;

    std::cout << "Ingrese los votos (Ingrese -1 para finalizar):" << std::endl;

    while (true) {
        std::cin >> voto;

        if (voto == -1) {
            break;
        }

        if (voto == 0) {
            ++votosBlancos;
        } else if (voto > 0 && voto <= numCandidatos) {
            ++candidatos[voto - 1].votos;
        } else {
            ++votosNulos;
        }

        ++votosTotales;
    }

    mostrarResultados(candidatos, votosTotales, votosNulos, votosBlancos);

    return 0;
}
