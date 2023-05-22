/*
Realice un programa como el del ejercicio anterior pero en el que se permitan espacios
en blanco. Este programa debe reconocer como pal´ındromos las frases: “dabale arroz
a la zorra el abad” y “la ruta nos aporto otro paso natural”.
*/
#include <iostream>
#include <string>
#include <algorithm>

bool esPalindromo(const std::string& frase) {
    std::string fraseSinEspacios = frase;
    fraseSinEspacios.erase(std::remove_if(fraseSinEspacios.begin(), fraseSinEspacios.end(), [](char c) {
        return !std::isalpha(c) && !std::isspace(c);
    }), fraseSinEspacios.end());

    std::string fraseSinEspaciosReversa = fraseSinEspacios;
    std::reverse(fraseSinEspaciosReversa.begin(), fraseSinEspaciosReversa.end());

    return fraseSinEspacios == fraseSinEspaciosReversa;
}

int main() {
    std::string frase;

    std::cout << "Ingrese una frase: ";
    std::getline(std::cin, frase);

    if (esPalindromo(frase)) {
        std::cout << "Es un palindromo." << std::endl;
    } else {
        std::cout << "No es un palindromo." << std::endl;
    }

    return 0;
}
