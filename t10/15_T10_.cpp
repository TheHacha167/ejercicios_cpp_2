/*
Dado un fichero como el siguiente (del que s ´olo se muestran las primeras cuatro l´ıneas,
el resto tienen el mismo formato):
Nombre: Luis Montejo Aguilera
Hijos: 3 8 6 2
Nombre: Ignacio Molina Guerrero
Hijos: 1 20
En el fichero, el primer entero que aparece tras el texto Hijos: indica el n´umero de
hijos que tiene la persona cuyo nombre aparece en la l´ınea anterior. Defina una estructura
que conste de dos campos: nombre y n´umero de hijos. Realice una funci´on con
las siguientes caracter´ısticas:
 Entradas: el nombre de un fichero de texto con el formato como el explicado.
Salidas: Un valor l ´ogico indicando si se pudo abrir el fichero correctamente. Un
vector de estructuras—y su tama˜no—del tipo que ha tenido que definir. El vector
contiene a los pares (nombre, n´umero de hijos) que contiene el fichero. Tambi´en
se debe devolver un valor de tipo l ´ogico indicando si se detect´o alg ´un error al
leer del fichero.
*/#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

struct Persona {
    std::string nombre;
    int numHijos;
};

std::vector<Persona> leerFichero(const std::string& nombreFichero) {
    std::vector<Persona> personas;
    std::ifstream archivo(nombreFichero);

    if (!archivo) {
        std::cout << "No se pudo abrir el archivo: " << nombreFichero << std::endl;
        return personas;
    }

    std::string linea;
    std::string nombre;
    int numHijos;
    while (std::getline(archivo, linea)) {
        if (linea.find("Nombre: ") == 0) {
            if (!nombre.empty()) {
                Persona persona;
                persona.nombre = nombre;
                persona.numHijos = numHijos;
                personas.push_back(persona);
            }
            nombre = linea.substr(8);  // Se omite el prefijo "Nombre: "
            numHijos = 0;
        } else if (linea.find("Hijos: ") == 0) {
            std::istringstream iss(linea.substr(7));  // Se omite el prefijo "Hijos: "
            int hijo;
            while (iss >> hijo) {
                numHijos++;
            }
        }
    }

    // Agregar la última persona al vector
    if (!nombre.empty()) {
        Persona persona;
        persona.nombre = nombre;
        persona.numHijos = numHijos;
        personas.push_back(persona);
    }

    archivo.close();
    return personas;
}

int main() {
    std::string nombreFichero;
    std::cout << "Ingrese el nombre del archivo: ";
    std::cin >> nombreFichero;

    std::vector<Persona> personas = leerFichero(nombreFichero);

    if (personas.empty()) {
        std::cout << "No se leyeron datos del archivo." << std::endl;
    } else {
        std::cout << "Personas leídas del archivo:" << std::endl;
        for (const auto& persona : personas) {
            std::cout << "Nombre: " << persona.nombre << ", Hijos: " << persona.numHijos << std::endl;
        }
    }

    return 0;
}
