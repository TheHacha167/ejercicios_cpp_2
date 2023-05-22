/*
Realice una funci´on recursiva que diga si una cadena de caracteres es un pal´ındromo.
Un pal´ındromo es una frase o palabra que se lee igual de delante hacia atr´as que de
atr´as hacia delante, por ejemplo: reconocer o anilina. Para simplificar suponga que la
cadena no contiene ni may´ usculas, ni signos de puntuaci´on, ni espacios en blanco ni
tildes.
*/
#include <iostream>
#include <cstring>

bool esPalindromoRecursivo(const char* cadena, int inicio, int fin) {
    // Caso base: cuando hemos recorrido toda la cadena o solo queda un carácter
    if (inicio >= fin) {
        return true;
    }

    // Verificar si los caracteres en las posiciones inicio y fin son iguales
    if (cadena[inicio] != cadena[fin]) {
        return false;
    }

    // Llamada recursiva para verificar los caracteres intermedios
    return esPalindromoRecursivo(cadena, inicio + 1, fin - 1);
}

bool esPalindromo(const char* cadena) {
    int longitud = std::strlen(cadena);
    return esPalindromoRecursivo(cadena, 0, longitud - 1);
}

int main() {
    const char* palabra = "reconocer";

    if (esPalindromo(palabra)) {
        std::cout << palabra << " es un palíndromo" << std::endl;
    } else {
        std::cout << palabra << " no es un palíndromo" << std::endl;
    }

    return 0;
}
