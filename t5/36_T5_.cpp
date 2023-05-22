/*
Modifica el programa anterior de forma que el ´ındice de la palabra a adivinar no lo
introduzca el usuario sino que se genere aleatoriamente—
*/
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

const int MAX_FALLOS = 6;

void mostrarAhorcado(int fallos) {
    // ...
}

void mostrarPalabra(const std::string& palabra, const std::vector<bool>& letrasDescubiertas) {
    // ...
}

bool adivinarPalabra(const std::string& palabra) {
    // ...
}

int main() {
    std::vector<std::string> palabras = {"hola", "adios", "programacion", "computadora"};

    std::srand(std::time(nullptr));  // Inicializar la semilla aleatoria

    int indice = std::rand() % palabras.size();
    std::string palabra = palabras[indice];

    adivinarPalabra(palabra);

    return 0;
}
