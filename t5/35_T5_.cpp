/*
Modifica el programa anterior de forma que se defina un vector de cadenas con posibles
palabras a adivinar. El usuario deber´a introducir un ´ındice v´alido del vector y
jugar con la palabra que se corresponda con dicho ´ındice.
*/
#include <iostream>
#include <string>
#include <vector>

const int MAX_FALLOS = 6;

void mostrarAhorcado(int fallos) {
    std::cout << "  +---+" << std::endl;
    std::cout << "  |   |" << std::endl;

    if (fallos >= 1) {
        std::cout << "  O   |" << std::endl;
    } else {
        std::cout << "      |" << std::endl;
    }

    if (fallos == 2) {
        std::cout << " /    |" << std::endl;
    } else if (fallos >= 3) {
        std::cout << " /|   |" << std::endl;
    } else {
        std::cout << "      |" << std::endl;
    }

    if (fallos == 4) {
        std::cout << " / \\  |" << std::endl;
    } else if (fallos >= 5) {
        std::cout << " /|\\  |" << std::endl;
    } else {
        std::cout << "      |" << std::endl;
    }

    std::cout << "      |" << std::endl;
    std::cout << "=========" << std::endl;
}

void mostrarPalabra(const std::string& palabra, const std::vector<bool>& letrasDescubiertas) {
    for (std::size_t i = 0; i < palabra.length(); ++i) {
        if (letrasDescubiertas[i]) {
            std::cout << palabra[i] << " ";
        } else {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}

bool adivinarPalabra(const std::string& palabra) {
    std::vector<bool> letrasDescubiertas(palabra.length(), false);
    int fallos = 0;

    while (fallos < MAX_FALLOS) {
        mostrarAhorcado(fallos);
        mostrarPalabra(palabra, letrasDescubiertas);

        char letra;
        std::cout << "Introduce una letra: ";
        std::cin >> letra;

        bool acertada = false;

        for (std::size_t i = 0; i < palabra.length(); ++i) {
            if (palabra[i] == letra) {
                letrasDescubiertas[i] = true;
                acertada = true;
            }
        }

        if (!acertada) {
            fallos++;
        }

        bool palabraDescubierta = true;
        for (bool descubierta : letrasDescubiertas) {
            if (!descubierta) {
                palabraDescubierta = false;
                break;
            }
        }

        if (palabraDescubierta) {
            std::cout << "¡Has adivinado la palabra correctamente!" << std::endl;
            return true;
        }
    }

    mostrarAhorcado(fallos);
    std::cout << "¡Has fallado! La palabra era: " << palabra << std::endl;

    return false;
}

int main() {
    std::vector<std::string> palabras = {"hola", "adios", "programacion", "computadora"};

    int indice;
    std::cout << "Seleccione un índice de palabra (0-" << palabras.size() - 1 << "): ";
    std::cin >> indice;

    if (indice < 0 || indice >= palabras.size()) {
        std::cout << "Índice inválido. Saliendo del programa." << std::endl;
        return 0;
    }

    std::string palabra = palabras[indice];

    adivinarPalabra(palabra);

    return 0;
}
