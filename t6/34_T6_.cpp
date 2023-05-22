/*
Realice una funci´on con la siguiente especificaci´on:
 Entradas: una matriz de caracteres representando una sopa de letras—y su tama˜no—
y una palabra.
 Salidas: La posici´on de inicio en la matriz de la primera ocurrencia horizontal de
la palabra. En caso de que la palabra no aparezca horizontalmente en la sopa de
letras se debe devolver un valor adecuado.
Por ejemplo, dada la matriz—sopa de letras—que aparece m´as abajo y la palabra
MARIO, la funci´on debe devolver la fila 4, columna 2.
*/
#include <iostream>
#include <vector>
#include <string>

// Función que busca la primera ocurrencia horizontal de una palabra en una sopa de letras
std::pair<int, int> buscarPalabraHorizontal(const std::vector<std::vector<char>>& sopaLetras, const std::string& palabra) {
    int filas = sopaLetras.size();
    int columnas = sopaLetras[0].size();

    for (int fila = 0; fila < filas; fila++) {
        for (int columna = 0; columna <= columnas - palabra.length(); columna++) {
            bool encontrada = true;
            for (int i = 0; i < palabra.length(); i++) {
                if (sopaLetras[fila][columna + i] != palabra[i]) {
                    encontrada = false;
                    break;
                }
            }
            if (encontrada) {
                return std::make_pair(fila, columna);
            }
        }
    }

    return std::make_pair(-1, -1); // Valor adecuado si la palabra no se encuentra
}

int main() {
    std::vector<std::vector<char>> sopaLetras = {
        {'L', 'L', 'L', 'L', 'L', 'L'},
        {'L', 'A', 'L', 'L', 'L', 'L'},
        {'L', 'L', 'L', 'L', 'L', 'L'},
        {'L', 'M', 'A', 'R', 'I', 'O'},
        {'L', 'L', 'L', 'L', 'L', 'L'}
    };

    std::string palabra = "MARIO";

    std::pair<int, int> posicion = buscarPalabraHorizontal(sopaLetras, palabra);

    if (posicion.first != -1 && posicion.second != -1) {
        std::cout << "La palabra \"" << palabra << "\" se encuentra en la fila " << posicion.first << ", columna " << posicion.second << std::endl;
    } else {
        std::cout << "La palabra \"" << palabra << "\" no se encuentra horizontalmente en la sopa de letras" << std::endl;
    }

    return 0;
}
