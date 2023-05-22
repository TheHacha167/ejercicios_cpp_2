/*
Desarrolle un programa en C++ que trabaje con un vector de personas. Cada persona
se almacena en una estructura con los siguiente campos: nombre, peso en kilos y altura
en metros. El programa debe comenzar leyendo de la entrada est´andar los datos de
varias personas. A continuaci´on debe hacer lo siguiente:
 Mostrar en la salida est´andar un listado con los datos de las personas introducidas.
El listado debe incluir el ´ındice de masa corporal de cada persona, ´este se
calcula como:
IMC =
peso
altura2
 Mostrar en la salida est´andar el nombre de la persona con mayor IMC.
 Un listado con los nombres de las personas cuya altura supera una introducida
por el usuario.
 Indicar si la persona con menor IMC es tambi´en la m´as peque˜ na.
*/
#include <iostream>
#include <vector>
#include <string>
#include <limits>


struct Persona {
    std::string nombre;
    double peso;
    double altura;
};

void mostrarListado(const std::vector<Persona>& personas) {
    std::cout << "Listado de personas:" << std::endl;
    for (int i = 0; i < personas.size(); ++i) {
        const Persona& persona = personas[i];
        double imc = persona.peso / (persona.altura * persona.altura);
        std::cout << "Nombre: " << persona.nombre << std::endl;
        std::cout << "Peso: " << persona.peso << " kg" << std::endl;
        std::cout << "Altura: " << persona.altura << " m" << std::endl;
        std::cout << "IMC: " << imc << std::endl;
        std::cout << std::endl;
    }
}

void mostrarPersonaMayorIMC(const std::vector<Persona>& personas) {
    double maxIMC = 0.0;
    std::string nombreMaxIMC;

    for (const Persona& persona : personas) {
        double imc = persona.peso / (persona.altura * persona.altura);
        if (imc > maxIMC) {
            maxIMC = imc;
            nombreMaxIMC = persona.nombre;
        }
    }

    std::cout << "Persona con mayor IMC: " << nombreMaxIMC << std::endl;
}

void mostrarPersonasAlturaSuperior(const std::vector<Persona>& personas, double altura) {
    std::cout << "Personas con altura superior a " << altura << " m:" << std::endl;
    for (const Persona& persona : personas) {
        if (persona.altura > altura) {
            std::cout << persona.nombre << std::endl;
        }
    }
    std::cout << std::endl;
}

void verificarPersonaMenorIMC(const std::vector<Persona>& personas) {
    double minIMC = std::numeric_limits<double>::max();
    std::string nombreMinIMC;
    bool esMasPequena = false;

    for (const Persona& persona : personas) {
        double imc = persona.peso / (persona.altura * persona.altura);
        if (imc < minIMC) {
            minIMC = imc;
            nombreMinIMC = persona.nombre;
            esMasPequena = true;
        }
        else if (imc == minIMC) {
            esMasPequena = false;
        }
    }

    if (esMasPequena) {
        std::cout << "La persona con menor IMC (" << nombreMinIMC << ") es también la más pequeña." << std::endl;
    }
    else {
        std::cout << "La persona con menor IMC (" << nombreMinIMC << ") no es la más pequeña." << std::endl;
    }
}

int main() {
    std::vector<Persona> personas;
    int numPersonas;
    double alturaLimite;

    std::cout << "Ingrese el número de personas: ";
    std::cin >> numPersonas;

    personas.resize(numPersonas);

    for (int i = 0; i < numPersonas; ++i) {
        Persona& persona = personas[i];
        std::cout << "Persona #" << i + 1 << std::endl;
        std::cout << "Nombre: ";
        std::cin >> persona.nombre;
        std::cout << "Peso (kg): ";
        std::cin >> persona.peso;
        std::cout << "Altura (m): ";
        std::cin >> persona.altura;
        std::cout << std::endl;
    }

    mostrarListado(personas);
    mostrarPersonaMayorIMC(personas);

    std::cout << "Ingrese una altura límite (m): ";
    std::cin >> alturaLimite;
    mostrarPersonasAlturaSuperior(personas, alturaLimite);

    verificarPersonaMenorIMC(personas);

    return 0;
}
