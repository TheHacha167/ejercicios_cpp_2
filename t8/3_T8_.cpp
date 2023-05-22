/*
Se almacena en una estructura la siguiente informaci´on sobre una persona: nombre,
edad y localidad de nacimiento. Realice una funci´on que tome como par´ametros de
entrada un vector de personas, su longitud y una localidad y devuelva como salida
un vector con los datos de las personas cuya localidad de nacimiento coincide con la
localidad recibida como par´ametro. El vector devuelto debe albergarse en memoria
din´amica. Realice tambi´en una funci´on main que permita probar la funci´on.
*/
#include <iostream>
#include <string>

struct Persona {
    std::string nombre;
    int edad;
    std::string localidadNacimiento;
};

Persona* filtrarPersonasPorLocalidad(Persona* personas, int longitud, const std::string& localidad) {
    int contador = 0;
    for (int i = 0; i < longitud; ++i) {
        if (personas[i].localidadNacimiento == localidad) {
            contador++;
        }
    }

    Persona* personasFiltradas = new Persona[contador];
    int indice = 0;
    for (int i = 0; i < longitud; ++i) {
        if (personas[i].localidadNacimiento == localidad) {
            personasFiltradas[indice] = personas[i];
            indice++;
        }
    }

    return personasFiltradas;
}

void mostrarPersonas(Persona* personas, int longitud) {
    for (int i = 0; i < longitud; ++i) {
        std::cout << "Nombre: " << personas[i].nombre << std::endl;
        std::cout << "Edad: " << personas[i].edad << std::endl;
        std::cout << "Localidad de nacimiento: " << personas[i].localidadNacimiento << std::endl;
        std::cout << std::endl;
    }
}

int main() {
    const int longitud = 4;
    Persona personas[longitud] = {
        {"Juan", 25, "Madrid"},
        {"María", 30, "Barcelona"},
        {"Pedro", 35, "Madrid"},
        {"Ana", 28, "Valencia"}
    };

    std::string localidadBuscada;
    std::cout << "Ingrese la localidad de nacimiento: ";
    std::cin >> localidadBuscada;

    Persona* personasFiltradas = filtrarPersonasPorLocalidad(personas, longitud, localidadBuscada);

    std::cout << "Personas con la localidad de nacimiento " << localidadBuscada << ":" << std::endl;
    mostrarPersonas(personasFiltradas, longitud);

    delete[] personasFiltradas;

    return 0;
}
