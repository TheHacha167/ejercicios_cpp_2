/*
Realice una funci´on que tome como par´ametro de entrada el nombre de un fichero de
texto y devuelva la l´ınea del fichero de mayor longitud.

*/
#include <iostream>
#include <fstream>
#include <string>

std::string obtenerLineaMasLarga(const std::string& nombreFichero) {
    std::ifstream fichero(nombreFichero);

    if (!fichero) {
        std::cout << "No se pudo abrir el fichero: " << nombreFichero << std::endl;
        return "";
    }

    std::string linea;
    std::string lineaMasLarga;
    std::size_t longitudMaxima = 0;

    while (std::getline(fichero, linea)) {
        if (linea.length() > longitudMaxima) {
            longitudMaxima = linea.length();
            lineaMasLarga = linea;
        }
    }

    fichero.close();

    if (longitudMaxima == 0) {
        std::cout << "El fichero está vacío." << std::endl;
    } else {
        std::cout << "La línea más larga tiene " << longitudMaxima << " caracteres." << std::endl;
    }

    return lineaMasLarga;
}

int main() {
    std::string nombreFichero = "fichero.txt";

    std::string lineaMasLarga = obtenerLineaMasLarga(nombreFichero);

    std::cout << "La línea más larga es: " << lineaMasLarga << std::endl;

    return 0;
}
