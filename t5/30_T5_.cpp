/*
Escribir un programa que solicite de la entrada est´andar un nombre y compruebe si el
nombre se encuentra o no en un vector iniciado con una serie de nombres.
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::string> nombres = {"Juan", "María", "Pedro", "Ana", "Luis"};

    std::string nombre;

    std::cout << "Ingrese un nombre: ";
    std::cin >> nombre;

    // Convertimos el nombre a minúsculas para hacer la búsqueda sin distinción de mayúsculas o minúsculas
    std::transform(nombre.begin(), nombre.end(), nombre.begin(), [](unsigned char c) { return std::tolower(c); });

    // Buscamos el nombre en el vector
    auto it = std::find_if(nombres.begin(), nombres.end(), [&](const std::string& n) {
        std::string temp = n;
        // Convertimos el nombre en el vector a minúsculas para comparar sin distinción de mayúsculas o minúsculas
        std::transform(temp.begin(), temp.end(), temp.begin(), [](unsigned char c) { return std::tolower(c); });
        return temp == nombre;
    });

    if (it != nombres.end()) {
        std::cout << "El nombre se encuentra en el vector." << std::endl;
    } else {
        std::cout << "El nombre no se encuentra en el vector." << std::endl;
    }

    return 0;
}
