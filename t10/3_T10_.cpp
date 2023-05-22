/*
Realice una funci´on que, dada una cadena de caracteres que contiene el nombre de un
fichero generado por un programa como el del ejercicio 1, lea los valores almacenados
en el fichero y los guarde en un vector de elementos de tipo double recibido como
par´ametro. La funci´on debe devolver tambi´en el n´umero de datos le´ıdos del fichero.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int leerDatosArchivo(const std::string& nombreArchivo, std::vector<double>& datos) {
    std::ifstream archivo(nombreArchivo);

    if (!archivo) {
        std::cout << "No se pudo abrir el archivo." << std::endl;
        return 0;
    }

    double valor;
    int contador = 0;

    while (archivo >> valor) {
        datos.push_back(valor);
        contador++;
    }

    archivo.close();

    return contador;
}
