/*
Realice un programa que permita al usuario introducir datos de tipo double positivos
y los vaya guardando en un fichero.

*/

#include <iostream>
#include <fstream>

int main() {
    std::ofstream archivo("datos.txt");  // Abre el archivo en modo de escritura

    if (!archivo) {
        std::cout << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }

    double dato;
    char opcion;

    do {
        std::cout << "Introduce un número positivo: ";
        std::cin >> dato;

        if (dato >= 0) {
            archivo << dato << std::endl;
        } else {
            std::cout << "Número inválido. Debe ser positivo." << std::endl;
        }

        std::cout << "¿Deseas introducir otro número? (s/n): ";
        std::cin >> opcion;
    } while (opcion == 's' || opcion == 'S');

    archivo.close();  // Cierra el archivo

    std::cout << "Datos guardados en el archivo correctamente." << std::endl;

    return 0;
}
