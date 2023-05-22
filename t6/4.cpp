/*
Realice una funci´on que, dado un car´acter, devuelva si es un d´ıgito.
*/
#include <iostream>

bool esDigito(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    char caracter = '5';

    bool esDígito = esDigito(caracter);
    if (esDígito) {
        std::cout << "El carácter '" << caracter << "' es un dígito." << std::endl;
    } else {
        std::cout << "El carácter '" << caracter << "' no es un dígito." << std::endl;
    }

    return 0;
}
