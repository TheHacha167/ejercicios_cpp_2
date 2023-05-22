/*
Realice una funci´on que tome como par´ametros dos nombres de ficheros, siendo el
primero fichero un fichero de texto, y copie el contenido del primer fichero en el segundo.

*/
#include <iostream>
#include <fstream>

void copiarContenidoFichero(const std::string& nombreFicheroOrigen, const std::string& nombreFicheroDestino) {
    std::ifstream ficheroOrigen(nombreFicheroOrigen);
    std::ofstream ficheroDestino(nombreFicheroDestino);

    if (!ficheroOrigen) {
        std::cout << "No se pudo abrir el fichero de origen." << std::endl;
        return;
    }

    if (!ficheroDestino) {
        std::cout << "No se pudo abrir el fichero de destino." << std::endl;
        return;
    }

    char caracter;

    while (ficheroOrigen.get(caracter)) {
        ficheroDestino << caracter;
    }

    ficheroOrigen.close();
    ficheroDestino.close();

    std::cout << "Se ha copiado el contenido del fichero de origen al fichero de destino." << std::endl;
}

int main() {
    std::string nombreFicheroOrigen = "fichero_origen.txt";
    std::string nombreFicheroDestino = "fichero_destino.txt";

    copiarContenidoFichero(nombreFicheroOrigen, nombreFicheroDestino);

    return 0;
}
