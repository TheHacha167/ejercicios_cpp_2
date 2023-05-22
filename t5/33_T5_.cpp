/*
Realice un programa que lea una cadena de caracteres e indique cu´antas palabras
tiene. Una palabra puede venir separada de otra por uno o m´as caracteres de espacio
en blanco.
*/
#include <iostream>
#include <string>
#include <sstream>

int contarPalabras(const std::string& cadena) {
    std::istringstream iss(cadena);
    int contador = 0;
    std::string palabra;

    while (iss >> palabra) {
        contador++;
    }

    return contador;
}

int main() {
    std::string cadena;

    std::cout << "Ingrese una cadena de caracteres: ";
    std::getline(std::cin, cadena);

    int numeroPalabras = contarPalabras(cadena);

    std::cout << "La cadena tiene " << numeroPalabras << " palabras." << std::endl;

    return 0;
}
