/*
Realice un programa que permita al usuario introducir datos de tipo int y los vaya
guardando en un fichero separados por el car´acter punto y coma.
*/
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string nombreArchivo = "datos.txt";
    std::ofstream archivo(nombreArchivo);

    if (!archivo) {
        std::cout << "No se pudo crear el archivo." << std::endl;
        return 1;
    }

    int dato;
    char opcion;

    do {
        std::cout << "Introduzca un dato de tipo int: ";
        std::cin >> dato;

        archivo << dato << ";"; // Escribir el dato en el archivo separado por punto y coma

        std::cout << "¿Desea introducir otro dato? (s/n): ";
        std::cin >> opcion;
    } while (opcion == 's' || opcion == 'S');

    archivo.close();

    std::cout << "Los datos se han guardado correctamente en el archivo." << std::endl;

    return 0;
}
