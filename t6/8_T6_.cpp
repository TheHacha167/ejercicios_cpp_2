/*

Realiza una funci´on que tome como par´ametros dos cadenas de caracteres y devuelva
la cadena m´as larga y la m´as corta.

*/
#include <iostream>
#include <string>

void obtenerCadenas(const std::string& cadena1, const std::string& cadena2, std::string& cadenaMasLarga, std::string& cadenaMasCorta) {
    if (cadena1.length() > cadena2.length()) {
        cadenaMasLarga = cadena1;
        cadenaMasCorta = cadena2;
    } else {
        cadenaMasLarga = cadena2;
        cadenaMasCorta = cadena1;
    }
}

int main() {
    std::string cadena1, cadena2;
    std::string cadenaMasLarga, cadenaMasCorta;

    std::cout << "Ingrese la primera cadena: ";
    std::getline(std::cin, cadena1);

    std::cout << "Ingrese la segunda cadena: ";
    std::getline(std::cin, cadena2);

    obtenerCadenas(cadena1, cadena2, cadenaMasLarga, cadenaMasCorta);

    std::cout << "La cadena mas larga es: " << cadenaMasLarga << std::endl;
    std::cout << "La cadena mas corta es: " << cadenaMasCorta << std::endl;

    return 0;
}
