/*
Realice una funci´on cuyos par´ametros sean los nombres de dos ficheros de texto. La
funci´on har´a una copia en el segundo fichero de aquellas frases contenidas en el primer
fichero que tengan m´as de 10 palabras. Las frases en el primer fichero est´an separadas
por el car´acter punto y coma. Las frases deben quedar en el fichero destino cada una
en una l´ınea. La funci´on debe devolver un valor de tipo l ´ogico indicando si lo dos
ficheros se han abierto correctamente. Las palabras se separan por un ´ unico espacio
en blanco o car´acter de nueva l´ınea.
Si suponemos que el contenido del fichero origen es:
Si buscas resultados distintos, no hagas siempre lo mismo; Lo que
sabemos es una gota de agua, lo que ignoramos es el oc´eano;¡Oh envidia,
ra´ız de infinitos males y carcoma de las virtudes!;El que lee mucho y
anda mucho, ve mucho y sabe mucho;
El contenido del fichero destino debe ser:
Lo que sabemos es una gota de agua, lo que ignoramos es el oc´eano
¡Oh envidia, ra´ız de infinitos males y carcoma de las virtudes!
El que lee mucho y anda mucho, ve mucho y sabe mucho
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

struct Frase {
    std::string ingles;
    std::string castellano;
};

std::vector<Frase> leerFichero(const std::string& nombreFichero) {
    std::vector<Frase> frases;
    std::ifstream archivo(nombreFichero);

    if (!archivo) {
        std::cout << "No se pudo abrir el archivo: " << nombreFichero << std::endl;
        return frases;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        Frase frase;
        std::istringstream iss(linea);

        iss >> frase.ingles;
        iss >> frase.castellano;

        frases.push_back(frase);
    }

    archivo.close();
    return frases;
}

void mostrarFrases(const std::vector<Frase>& frases) {
    for (const auto& frase : frases) {
        std::cout << "Inglés: " << frase.ingles << ", Castellano: " << frase.castellano << std::endl;
    }
}

void guardarEnFichero(const std::vector<Frase>& frases, const std::string& nombreFichero) {
    std::ofstream archivo(nombreFichero);

    if (!archivo) {
        std::cout << "No se pudo abrir el archivo: " << nombreFichero << std::endl;
        return;
    }

    for (const auto& frase : frases) {
        archivo << frase.ingles << " " << frase.castellano << std::endl;
    }

    archivo.close();
}

int main() {
    std::string nombreFichero;
    std::cout << "Ingrese el nombre del archivo: ";
    std::cin >> nombreFichero;

    std::vector<Frase> frases = leerFichero(nombreFichero);
    mostrarFrases(frases);

    return 0;
}
