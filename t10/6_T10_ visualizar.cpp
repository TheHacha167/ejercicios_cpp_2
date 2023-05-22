/*
Realice un programa que permita escribir en un fichero datos de tipo char, int, float y
cadenas de caracteres sin espacios en blanco, en cualquier orden, y hasta que el usuario
decida. Realice tambi´en un programa que permita visualizar los datos almacenados
en un fichero creado con el programa anterior.
Sugerencia: Para que el fichero pueda ser le´ıdo correctamente preceda cada dato almacenado
en el fichero con un car´acter que indique el tipo del siguiente elemento
guardado en el fichero. Por ejemplo, ’c’ para char, ’i’ para int, ’f’ para float y ’s’ para
string. Un fichero de este tipo podr´ıa ser el siguiente:
i 66 f 7.5 s hola s Luis c a c b
Este fichero contiene un dato de tipo int—66—, seguido de un dato de tipo float—
7.5—, seguido de dos datos de tipo string— hola y Luis—, seguidos por dos datos de
tipo char—a y b.
*/
#include <iostream>
#include <fstream>
#include <string>

void visualizarFichero(const std::string& nombreFichero) {
    std::ifstream archivo(nombreFichero);

    if (!archivo) {
        std::cout << "No se pudo abrir el fichero." << std::endl;
        return;
    }

    char tipo;
    while (archivo >> tipo) {
        switch (tipo) {
            case 'c': {
                char dato;
                archivo >> dato;
                std::cout << "char: " << dato << std::endl;
                break;
            }
            case 'i': {
                int dato;
                archivo >> dato;
                std::cout << "int: " << dato << std::endl;
                break;
            }
            case 'f': {
                float dato;
                archivo >> dato;
                std::cout << "float: " << dato << std::endl;
                break;
            }
            case 's': {
                std::string dato;
                archivo >> dato;
                std::cout << "string: " << dato << std::endl;
                break;
            }
            default:
                std::cout << "Tipo de dato inválido." << std::endl;
                break;
        }
    }
}

int main() {
    std::string nombreFichero = "datos.txt";
    visualizarFichero(nombreFichero);

    return 0;
}
