/*
Defina una estructura que sirva para representar a una persona. La estructura debe
contener dos campos: el nombre de la persona y un valor de tipo l ´ogico que indica si
la persona tiene alg ´un tipo de minusval´ıa. Realice un programa que dado un vector
de personas rellene dos nuevos vectores: uno que contenga las personas que no tienen
ninguna minusval´ıa y otro que contenga las personas con minusval´ıa.
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
    std::vector<Persona> personas = {
        {"Juan", true},
        {"María", false},
        {"Pedro", true},
        {"Ana", false}
    };

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
