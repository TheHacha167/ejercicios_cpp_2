/*
Modifica el programa sobre personas con posible minusval´ıa para que los datos se lean
de la entrada est´andar.
*/
#include <iostream>
#include <vector>
#include <string>

struct Persona {
    std::string nombre;
    bool tieneMinusvalia;
};

void separarPersonas(const std::vector<Persona>& personas, std::vector<Persona>& personasSinMinusvalia, std::vector<Persona>& personasConMinusvalia) {
    for (const auto& persona : personas) {
        if (persona.tieneMinusvalia) {
            personasConMinusvalia.push_back(persona);
        } else {
            personasSinMinusvalia.push_back(persona);
        }
    }
}

int main() {
    std::vector<Persona> personas;
    std::string nombre;
    char minusvalia;

    std::cout << "Ingrese los datos de las personas ('fin' para terminar):" << std::endl;

    while (true) {
        std::cout << "Nombre: ";
        std::getline(std::cin, nombre);

        if (nombre == "fin") {
            break;
        }

        std::cout << "¿Tiene minusvalía? (s/n): ";
        std::cin >> minusvalia;
        std::cin.ignore(); // Limpiar el buffer del salto de línea

        bool tieneMinusvalia = (minusvalia == 's' || minusvalia == 'S');

        personas.push_back({nombre, tieneMinusvalia});
    }

    std::vector<Persona> personasSinMinusvalia;
    std::vector<Persona> personasConMinusvalia;

    separarPersonas(personas, personasSinMinusvalia, personasConMinusvalia);

    std::cout << "Personas sin minusvalía:" << std::endl;
    for (const auto& persona : personasSinMinusvalia) {
        std::cout << persona.nombre << std::endl;
    }

    std::cout << "Personas con minusvalía:" << std::endl;
    for (const auto& persona : personasConMinusvalia) {
        std::cout << persona.nombre << std::endl;
    }

    return 0;
}
