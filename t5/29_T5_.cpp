/*
Realice un programa que lea l´ıneas de la entrada est´andar hasta que se lea una l´ınea
cuyo contenido sea la cadena FIN. El programa debe mostrar en la salida est´andar la
l´ınea m´as larga de las le´ıdas y tambi´en la menor desde un punto de vista lexicogr´afico.
*/
#include <iostream>
#include <string>
#include <limits>

int main() {
    std::string linea;
    std::string lineaMasLarga;
    std::string lineaMenorLexicograficamente;

    // Inicializamos la longitud máxima con el valor mínimo posible
    int longitudMaxima = std::numeric_limits<int>::min();

    std::cout << "Ingrese las lineas (ingrese FIN para finalizar):" << std::endl;

    while (getline(std::cin, linea) && linea != "FIN") {
        // Verificamos si la línea actual es la más larga
        if (linea.length() > longitudMaxima) {
            longitudMaxima = linea.length();
            lineaMasLarga = linea;
        }

        // Verificamos si la línea actual es la menor lexicográficamente
        if (linea < lineaMenorLexicograficamente || lineaMenorLexicograficamente.empty()) {
            lineaMenorLexicograficamente = linea;
        }
    }

    std::cout << "Linea mas larga: " << lineaMasLarga << std::endl;
    std::cout << "Linea menor lexicograficamente: " << lineaMenorLexicograficamente << std::endl;

    return 0;
}
