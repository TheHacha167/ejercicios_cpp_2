/*
Realiza una funci´on que tome como par´ametro una matriz de n´umeros e indique si
hay alg ´un elemento de la matriz que sea el m´ınimo estricto de su columna y, a la vez,
el m´aximo estricto de su fila. Por m´ınimo y m´aximo estricto se quiere decir que sea
´ unico, es decir, que no haya ning ´un otro elemento con un valor tan bajo o tan alto en
el caso del m´ınimo y m´aximo respectivamente.
*/
#include <iostream>
#include <vector>

bool esMinimoEstrictoDeColumnaYMaximoEstrictoDeFila(const std::vector<std::vector<int>>& matriz) {
    int filas = matriz.size();
    int columnas = matriz[0].size();

    for (int i = 0; i < filas; i++) {
        int filaMaximo = matriz[i][0]; // Valor máximo en la fila
        int columnaMinimo = matriz[0][i]; // Valor mínimo en la columna

        // Obtener el máximo de la fila
        for (int j = 1; j < columnas; j++) {
            if (matriz[i][j] > filaMaximo) {
                filaMaximo = matriz[i][j];
            }
        }

        // Obtener el mínimo de la columna
        for (int j = 1; j < filas; j++) {
            if (matriz[j][i] < columnaMinimo) {
                columnaMinimo = matriz[j][i];
            }
        }

        // Comprobar si el elemento es el mínimo estricto de su columna y el máximo estricto de su fila
        if (matriz[i][i] == columnaMinimo && matriz[i][i] == filaMaximo) {
            return true;
        }
    }

    return false;
}

int main() {
    // Ejemplo de matriz
    std::vector<std::vector<int>> matriz = {
        {3, 5, 6},
        {2, 8, 4},
        {7, 9, 1}
    };

    bool resultado = esMinimoEstrictoDeColumnaYMaximoEstrictoDeFila(matriz);
    if (resultado) {
        std::cout << "La matriz tiene un elemento que es el mínimo estricto de su columna y el máximo estricto de su fila." << std::endl;
    } else {
        std::cout << "La matriz no cumple la condición especificada." << std::endl;
    }

    return 0;
}
