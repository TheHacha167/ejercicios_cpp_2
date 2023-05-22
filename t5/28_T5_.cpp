/*
Realice un programa que lea una cadena de caracteres de la entrada est´andar y muestre
en la salida est´andar cu´antas ocurrencias de cada vocal existen en la cadena.
*/
#include <iostream>
#include <string>
#include <unordered_map>

void contarVocales(const std::string& cadena) {
    std::unordered_map<char, int> contadorVocales;

    for (char c : cadena) {
        c = tolower(c); // Convertir a minúscula para contar independientemente de la capitalización
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            contadorVocales[c]++;
        }
    }

    std::cout << "Ocurrencias de cada vocal:" << std::endl;
    std::cout << "a: " << contadorVocales['a'] << std::endl;
    std::cout << "e: " << contadorVocales['e'] << std::endl;
    std::cout << "i: " << contadorVocales['i'] << std::endl;
    std::cout << "o: " << contadorVocales['o'] << std::endl;
    std::cout << "u: " << contadorVocales['u'] << std::endl;
}

int main() {
    std::string cadena;

    std::cout << "Ingrese una cadena de caracteres: ";
    std::getline(std::cin, cadena);

    contarVocales(cadena);

    return 0;
}
