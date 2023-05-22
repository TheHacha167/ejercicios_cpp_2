/*

Realice una funci´on que reciba como par´ametro de entrada una cadena de caracteres
que contiene el nombre de un fichero generado mediante el programa del ejercicio
anterior y devuelva como par´ametros de salida:
 un vector de enteros con los valores le´ıdos del fichero.
 el n´umero de enteros le´ıdos del fichero.
 un valor de tipo l ´ogico indicando si se abri´o con ´exito el fichero.
 un valor de tipo l ´ogico que indique si la lectura del fichero termin´o porque se
lleg ´o al fin de fichero o por otra causa.
*/
#include <iostream>
#include <fstream>
#include <vector>

bool leerFichero(const std::string& nombreFichero, std::vector<int>& datos, int& numDatos) {
    std::ifstream archivo(nombreFichero);

    if (!archivo) {
        std::cout << "No se pudo abrir el fichero." << std::endl;
        return false;
    }

    int dato;
    char delimitador;

    while (archivo >> dato >> delimitador) {
        datos.push_back(dato);
    }

    if (archivo.eof()) {
        std::cout << "Lectura del fichero terminada correctamente." << std::endl;
        return true;
    } else {
        std::cout << "Error en la lectura del fichero." << std::endl;
        return false;
    }
}

int main() {
    std::string nombreFichero = "datos.txt";
    std::vector<int> datos;
    int numDatos = 0;
    bool exito = leerFichero(nombreFichero, datos, numDatos);

    if (exito) {
        std::cout << "Datos leídos del fichero:" << std::endl;
        for (int dato : datos) {
            std::cout << dato << " ";
        }
        std::cout << std::endl;
        std::cout << "Número de datos leídos: " << numDatos << std::endl;
    }

    return 0;
}
