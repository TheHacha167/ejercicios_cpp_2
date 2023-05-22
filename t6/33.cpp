/*
Realice un programa que compruebe si es v´alido el relleno de un Sudoku.
An´alisis del problema: El objetivo del Sudoku es rellenar una matriz de 9x9 celdas
Para resolver este problema realice las siguientes funciones:
(a) Funci´on que dado un Sudoku y un n´umero de fila del Sudoku devuelva un valor
de tipo l ´ogico indicando si no se repiten dos d´ıgitos en la fila.
(b) Funci´on que dado un Sudoku y un n´umero de columna del Sudoku devuelva un
valor de tipo l ´ogico indicando si no se repiten dos d´ıgitos en la columna.
(c) Funci´on que dado un Sudoku y la primera fila y columna de una caja del Sudoku
devuelva un valor de tipo l ´ogico indicando si no se repiten dos d´ıgitos en la caja.
(d) Funci´on main que lea un relleno de un Sudoku en una matriz y que utilice las
funciones previas para determinar si el relleno es v´alido. Se debe mostrar en la
salida est´andar la informaci´on sobre si el relleno es v´alido o no.
*/
#include <iostream>
#include <vector>

const int SIZE = 9;

// Función que verifica si no se repiten dos dígitos en una fila
bool validarFila(const std::vector<std::vector<int>>& sudoku, int fila) {
    std::vector<bool> numeros(SIZE, false);

    for (int col = 0; col < SIZE; col++) {
        int num = sudoku[fila][col];
        if (num != 0) {
            if (numeros[num - 1]) {
                return false;  // Se repite el número en la fila
            }
            numeros[num - 1] = true;
        }
    }

    return true;
}

// Función que verifica si no se repiten dos dígitos en una columna
bool validarColumna(const std::vector<std::vector<int>>& sudoku, int columna) {
    std::vector<bool> numeros(SIZE, false);

    for (int fila = 0; fila < SIZE; fila++) {
        int num = sudoku[fila][columna];
        if (num != 0) {
            if (numeros[num - 1]) {
                return false;  // Se repite el número en la columna
            }
            numeros[num - 1] = true;
        }
    }

    return true;
}

// Función que verifica si no se repiten dos dígitos en una caja
bool validarCaja(const std::vector<std::vector<int>>& sudoku, int filaInicial, int columnaInicial) {
    std::vector<bool> numeros(SIZE, false);

    for (int fila = filaInicial; fila < filaInicial + 3; fila++) {
        for (int columna = columnaInicial; columna < columnaInicial + 3; columna++) {
            int num = sudoku[fila][columna];
            if (num != 0) {
                if (numeros[num - 1]) {
                    return false;  // Se repite el número en la caja
                }
                numeros[num - 1] = true;
            }
        }
    }

    return true;
}

int main() {
    std::vector<std::vector<int>> sudoku(SIZE, std::vector<int>(SIZE));

    // Lectura del relleno del Sudoku
    std::cout << "Ingrese el relleno del Sudoku (0 para casillas vacías):\n";
    for (int fila = 0; fila < SIZE; fila++) {
        for (int columna = 0; columna < SIZE; columna++) {
            std::cin >> sudoku[fila][columna];
        }
    }

    // Validación del relleno del Sudoku
    bool esValido = true;

    // Verificar filas
    for (int fila = 0; fila < SIZE; fila++) {
        if (!validarFila(sudoku, fila)) {
            esValido = false;
            break;
        }
    }

    // Verificar columnas
    for (int columna = 0; columna < SIZE; columna++) {
        if (!validarColumna(sudoku, columna)) {
            esValido = false;
            break;
        }
    }

    // Verificar cajas
    for (int fila = 0; fila < SIZE; fila += 3) {
        for (int columna = 0; columna < SIZE; columna += 3) {
            if (!validarCaja(sudoku, fila, columna)) {
                esValido = false;
                break;
            }
        }
    }

    // Mostrar resultado
    if (esValido) {
        std::cout << "El relleno del Sudoku es válido.\n";
    } else {
        std::cout << "El relleno del Sudoku no es válido.\n";
    }

    return 0;
}
