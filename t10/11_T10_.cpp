/*

Realice una funci´on que tome como par´ametros un vector con los nombres de ficheros
de texto y el nombre de un fichero de salida. La funci´on debe guardar en el fichero de
salida la concatenaci´on de todos los ficheros cuyos nombres aparecen en el vector.
*/
#include <iostream>
#include <fstream>
#include <vector>

void concatenarFicheros(const std::vector<std::string>& nombresFicheros, const std::string& nombreFicheroSalida) {
    std::ofstream ficheroSalida(nombreFicheroSalida);

    if (!ficheroSalida) {
        std::cout << "No se pudo abrir el fichero de salida." << std::endl;
        return;
    }

    for (const std::string& nombreFichero : nombresFicheros) {
        std::ifstream fichero(nombreFichero);

        if (!fichero) {
            std::cout << "No se pudo abrir el fichero: " << nombreFichero << std::endl;
            continue;
        }

        char caracter;

        while (fichero.get(caracter)) {
            ficheroSalida << caracter;
        }

        fichero.close();
    }

    ficheroSalida.close();

    std::cout << "Se ha concatenado el contenido de los ficheros en el fichero de salida." << std::endl;
}

int main() {
    std::vector<std::string> nombresFicheros = { "fichero1.txt", "fichero2.txt", "fichero3.txt" };
    std::string nombreFicheroSalida = "fichero_salida.txt";

    concatenarFicheros(nombresFicheros, nombreFicheroSalida);

    return 0;
}
