/*

Realice un programa que lea el contenido de un fichero de texto y lo env´ıe a la salida
est´andar. Haga dos versiones, una que lea el fichero car´acter a car´acter y otro que lea
el fichero l´ınea a l´ınea.

*/
#include <iostream>
#include <fstream>

void leerFicheroCaracterPorCaracter(const std::string& nombreFichero) {
    std::ifstream archivo(nombreFichero);

    if (!archivo) {
        std::cout << "No se pudo abrir el fichero." << std::endl;
        return;
    }

    char caracter;
    while (archivo.get(caracter)) {
        std::cout << caracter;
    }

    archivo.close();
}

void leerFicheroLineaPorLinea(const std::string& nombreFichero) {
    std::ifstream archivo(nombreFichero);

    if (!archivo) {
        std::cout << "No se pudo abrir el fichero." << std::endl;
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::cout << linea << std::endl;
    }

    archivo.close();
}

int main() {
    std::string nombreFichero = "archivo.txt";

    std::cout << "Contenido del fichero (carácter a carácter):" << std::endl;
    leerFicheroCaracterPorCaracter(nombreFichero);

    std::cout << std::endl;

    std::cout << "Contenido del fichero (línea a línea):" << std::endl;
    leerFicheroLineaPorLinea(nombreFichero);

    return 0;
}
