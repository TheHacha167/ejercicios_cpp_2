/*
Desarrolle un programa que trabaje con un vector de personas. Por cada persona hay
que almacenar su nombre, sexo y edad. Realice las siguientes funciones:
 Funci´on que lea de la entrada est´andar una nueva persona y la inserte al final de
un vector de personas.
 Funci´on que inserte al final de un vector de personas las personas almacenadas
en un fichero de texto—el fichero tendr´a un formato adecuado que debe pensar.
La funci´on recibe como par´ametros de entrada y salida el vector de personas y
su n´umero de elementos y como par´ametro de entrada el nombre del fichero de
texto con las personas.
Funci´on que env´ıe a la salida est´andar el contenido de un vector de personas.
 Funci´on que dado un vector de personas y el nombre de un fichero almacene a
las personas en el fichero—utilizando un formato que permita al programa leer
su contenido.
 Funci´on main que contenga un men´u que permita probar el resto de funciones.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Persona {
    std::string nombre;
    char sexo;
    int edad;
};

void agregarPersona(std::vector<Persona>& personas) {
    Persona nuevaPersona;

    std::cout << "Ingrese el nombre: ";
    std::cin >> nuevaPersona.nombre;

    std::cout << "Ingrese el sexo (M/F): ";
    std::cin >> nuevaPersona.sexo;

    std::cout << "Ingrese la edad: ";
    std::cin >> nuevaPersona.edad;

    personas.push_back(nuevaPersona);
}

void agregarPersonasDesdeArchivo(std::vector<Persona>& personas, const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);

    if (!archivo) {
        std::cout << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return;
    }

    std::string nombre;
    char sexo;
    int edad;

    while (archivo >> nombre >> sexo >> edad) {
        Persona nuevaPersona = { nombre, sexo, edad };
        personas.push_back(nuevaPersona);
    }

    archivo.close();
}

void mostrarPersonas(const std::vector<Persona>& personas) {
    for (const auto& persona : personas) {
        std::cout << "Nombre: " << persona.nombre << ", Sexo: " << persona.sexo << ", Edad: " << persona.edad << std::endl;
    }
}

void guardarPersonasEnArchivo(const std::vector<Persona>& personas, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo);

    if (!archivo) {
        std::cout << "No se pudo crear el archivo: " << nombreArchivo << std::endl;
        return;
    }

    for (const auto& persona : personas) {
        archivo << persona.nombre << " " << persona.sexo << " " << persona.edad << std::endl;
    }

    archivo.close();
}

int main() {
    std::vector<Persona> personas;

    int opcion;
    std::string nombreArchivo;

    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Agregar persona" << std::endl;
        std::cout << "2. Agregar personas desde archivo" << std::endl;
        std::cout << "3. Mostrar personas" << std::endl;
        std::cout << "4. Guardar personas en archivo" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                agregarPersona(personas);
                break;
            case 2:
                std::cout << "Ingrese el nombre del archivo: ";
                std::cin >> nombreArchivo;
                agregarPersonasDesdeArchivo(personas, nombreArchivo);
                break;
            case 3:
                mostrarPersonas(personas);
                break;
            case 4:
                std::cout << "Ingrese el nombre del archivo: ";
                std::cin >> nombreArchivo;
                guardarPersonasEnArchivo(personas, nombreArchivo);
                break;
            case 5:
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            default:
                std::cout << "Opcion no valida." << std::endl;
                break;
        }

        std::cout << std::endl;
    } while (opcion != 5);

    return 0;
}
