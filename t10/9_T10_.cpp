/*
Realice una funci´on que tome como par´ametros de entrada el nombre de un fichero de
texto y un car´acter c y devuelva el n´umero de ocurrencias en el fichero del car´acter.


*/
#include <iostream>
#include <fstream>

int contarOcurrenciasCaracter(const std::string& nombreFichero, char c) {
    std::ifstream archivo(nombreFichero);

    if (!archivo) {
        std::cout << "No se pudo abrir el fichero." << std::endl;
        return 0;
    }

    char caracter;
    int contador = 0;

    while (archivo.get(caracter)) {
        if (caracter == c) {
            contador++;
        }
    }

    archivo.close();

    return contador;
}

int main() {
    std::string nombreFichero = "archivo.txt";
    char c = 'a';

    int ocurrencias = contarOcurrenciasCaracter(nombreFichero, c);

    std::cout << "El carácter '" << c << "' aparece " << ocurrencias << " veces en el fichero." << std::endl;

    return 0;
}
