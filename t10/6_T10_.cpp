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

void escribirFichero(const std::string& nombreFichero) {
    std::ofstream archivo(nombreFichero);

    if (!archivo) {
        std::cout << "No se pudo abrir el fichero." << std::endl;
        return;
    }

    char tipo;
    bool continuar = true;

    while (continuar) {
        std::cout << "Introduce el tipo de dato ('c' para char, 'i' para int, 'f' para float, 's' para string): ";
        std::cin >> tipo;

        switch (tipo) {
            case 'c': {
                char dato;
                std::cout << "Introduce un char: ";
                std::cin >> dato;
                archivo << tipo << " " << dato << " ";
                break;
            }
            case 'i': {
                int dato;
                std::cout << "Introduce un int: ";
                std::cin >> dato;
                archivo << tipo << " " << dato << " ";
                break;
            }
            case 'f': {
                float dato;
                std::cout << "Introduce un float: ";
                std::cin >> dato;
                archivo << tipo << " " << dato << " ";
                break;
            }
            case 's': {
                std::string dato;
                std::cout << "Introduce un string sin espacios en blanco: ";
                std::cin >> dato;
                archivo << tipo << " " << dato << " ";
                break;
            }
            default:
                std::cout << "Tipo de dato inválido." << std::endl;
                break;
        }

        std::cout << "¿Desea continuar escribiendo datos? (s/n): ";
        char respuesta;
        std::cin >> respuesta;

        if (respuesta != 's') {
            continuar = false;
        }
    }

    std::cout << "Datos escritos en el fichero." << std::endl;
}

int main() {
    std::string nombreFichero = "datos.txt";
    escribirFichero(nombreFichero);

    return 0;
}
