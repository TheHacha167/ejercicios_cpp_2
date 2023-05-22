/*
Suponga un fichero de texto con el siguiente formato: cada l´ınea contiene una palabra
en ingl´es separada mediante un espacio en blanco de la misma palabra en castellano.
Por ejemplo:
kitchen cocina
apple manzana
Realice las siguientes funciones:
 Funci´on que tome como par´ametro de entrada el nombre de un fichero de texto
con el formato comentado y devuelva un vector de estructuras con las palabras
almacenadas en el fichero. Cada estructura debe contener dos campos que almacenan
la palabra en ingl´es y en castellano respectivamente.
 Funci´on main que solicite al usuario un nombre de fichero de texto con palabras
en ingl´es y castellano y utilice la funci´on previa para leer las palabras del fichero.
A continuaci´on debe mostrar en la salida est´andar cada palabra en ingl´es y debe
solicitar al usuario que escriba la palabra en castellano. Tras ello debe mostrar en
la salida est´andar el n´umero de aciertos y fallos que ha tenido el usuario.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Palabra {
    std::string ingles;
    std::string castellano;
};

std::vector<Palabra> cargarPalabrasDesdeArchivo(const std::string& nombreArchivo) {
    std::vector<Palabra> palabras;
    std::ifstream archivo(nombreArchivo);

    if (!archivo) {
        std::cout << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return palabras;
    }

    std::string ingles, castellano;
    while (archivo >> ingles >> castellano) {
        Palabra palabra = { ingles, castellano };
        palabras.push_back(palabra);
    }

    archivo.close();
    return palabras;
}

int main() {
    std::string nombreArchivo;
    std::cout << "Ingrese el nombre del archivo: ";
    std::cin >> nombreArchivo;

    std::vector<Palabra> palabras = cargarPalabrasDesdeArchivo(nombreArchivo);

    int aciertos = 0;
    int fallos = 0;

    for (const auto& palabra : palabras) {
        std::string respuestaUsuario;
        std::cout << "Palabra en inglés: " << palabra.ingles << std::endl;
        std::cout << "Ingrese la palabra en castellano: ";
        std::cin >> respuestaUsuario;

        if (respuestaUsuario == palabra.castellano) {
            aciertos++;
        } else {
            fallos++;
        }
    }

    std::cout << "Aciertos: " << aciertos << std::endl;
    std::cout << "Fallos: " << fallos << std::endl;

    return 0;
}
