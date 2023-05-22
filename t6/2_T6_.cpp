/*
Realiza una funci´on que tome como par´ametros dos cadenas de caracteres y devuelva
la cadena m´as larga o la primera si ambas tienen la misma longitud.
*/
#include <iostream>
#include <string>

std::string cadenaMasLarga(const std::string& cadena1, const std::string& cadena2) {
    if (cadena1.length() >= cadena2.length()) {
        return cadena1;
    } else {
        return cadena2;
    }
}

int main() {
    std::string cadena1 = "Hola";
    std::string cadena2 = "Mundo";

    std::string masLarga = cadenaMasLarga(cadena1, cadena2);
    std::cout << "La cadena más larga es: " << masLarga << std::endl;

    return 0;
}
