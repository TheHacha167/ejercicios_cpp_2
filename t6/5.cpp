/*

Realice una funci´on que, dada una cadena de caracteres, devuelva cu´antos d´ıgitos
contiene. Sugerencia: use la funci´on del ejercicio anterior para, dado un car´acter de la
cadena, comprobar si el car´acter es un d´ıgito.
*/
#include <iostream>

bool esDigito(char c) {
    return c >= '0' && c <= '9';
}

int contarDigitos(const std::string& cadena) {
    int contador = 0;
    for (char c : cadena) {
        if (esDigito(c)) {
            contador++;
        }
    }
    return contador;
}

int main() {
    std::string cadena = "Abc123xyz45";

    int cantidadDigitos = contarDigitos(cadena);
    std::cout << "La cadena contiene " << cantidadDigitos << " dígitos." << std::endl;

    return 0;
}
