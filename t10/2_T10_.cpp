/*
Realice un programa que lea los datos almacenados en un fichero generado por un
programa como el del ejercicio anterior y los env´ıe a la salida est´andar.
Nota: Observe que para poder realizar la lectura es preciso que los datos del fichero
est´en separados por alg ´un car´acter delimitador—por ejemplo, por caracteres blancos.
*/
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream archivo("datos.txt");  // Abre el archivo en modo de lectura

    if (!archivo) {
        std::cout << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }

    std::string dato;

    while (archivo >> dato) {
        std::cout << dato << " ";
    }

    archivo.close();  // Cierra el archivo

    return 0;
}
