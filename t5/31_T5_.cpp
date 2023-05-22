/*
Realice un programa que lea una cadena de caracteres e indique si es un pal´ındromo.
Un pal´ındromo es una frase o palabra que se lee igual de delante hacia atr´as que de
atr´as hacia delante, por ejemplo: reconocer o anilina. Para simplificar suponga que
la cadena le´ıda no contiene ni may´ usculas, ni signos de puntuaci´on, ni espacios en
blanco ni tildes.
*/
#include <iostream>
#include <string>
#include <algorithm>

bool esPalindromo(const std::string& cadena) {
    std::string cadenaSinEspacios = cadena;
    cadenaSinEspacios.erase(std::remove_if(cadenaSinEspacios.begin(), cadenaSinEspacios.end(), [](char c) {
        return !std::isalpha(c);
    }), cadenaSinEspacios.end());

    std::string cadenaReversa = cadenaSinEspacios;
    std::reverse(cadenaReversa.begin(), cadenaReversa.end());

    return cadenaSinEspacios == cadenaReversa;
}

int main() {
    std::string cadena;

    std::cout << "Ingrese una cadena: ";
    std::cin >> cadena;

    if (esPalindromo(cadena)) {
        std::cout << "Es un palindromo." << std::endl;
    } else {
        std::cout << "No es un palindromo." << std::endl;
    }

    return 0;
}
