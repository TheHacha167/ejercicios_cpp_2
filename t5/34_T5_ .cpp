/*
Implementar el juego del ahorcado. El programa dispondr´a de un men´u con tres opciones:
introducir palabra, adivinar palabra y salir. La primera opci´on permite introducir
la palabra que otro jugador—o nosotros mismos, para probar el programa—ha
de adivinar. La segunda opci ´on s ´olo podr´a llevarse a cabo si ha sido introducida previamente
una palabra. De ser as´ı aparecer´a una cadena formada por guiones—tantos
como letras contiene la palabra. El programa ir´a pidiendo una letra tras otra. Si la
letra es v´alida aparecer´a en la cadena en la posici´on correspondiente, si no es as´ı contaremos
un fallo. El programa termina cuando se han acertado todas las letras o se ha
fallado seis veces.
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
    std::string palabra;
    bool palabraIntroducida = false;

    while (true) {
        std::cout << "Menú:" << std::endl;
        std::cout << "1. Introducir palabra" << std::endl;
        std::cout << "2. Adivinar palabra" << std::endl;
        std::cout << "3. Salir" << std::endl;

        int opcion;
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        if (opcion == 1) {
            std::cout << "Introduce la palabra a adivinar: ";
            std::cin >> palabra;
            palabraIntroducida = true;
        } else if (opcion == 2) {
            if (!palabraIntroducida) {
                std::cout << "Primero debes introducir una palabra." << std::endl;
            } else {
                adivinarPalabra(palabra);
            }
        } else if (opcion == 3) {
            break;
        } else {
            std::cout << "Opción inválida. Introduce un número válido." << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
