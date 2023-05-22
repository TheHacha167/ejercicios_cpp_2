/*
Realiza un programa que permita gestionar las reservas de una sala de cine para una
sesi ´on. La sala tiene 10 filas con 10 asientos por fila. Los asientos se numeran del 0 al 9
para la primera fila (fila 0), del 10 al 19 para la segunda fila (fila 1) y as´ı sucesivamente.
La sala puede representarse como una matriz. Crea las siguientes funciones:
 Funci´on que inicie la matriz. Inicialmente todos los asientos deben estar libres.
 Funci´on que muestre en la salida est´andar la ocupaci´on de la sala.
 Funci´on que devuelva cu´antos asientos libres hay en la sala.
 Funci´on que dado un n´umero de entradas devuelva un vector con los n´umeros de
las filas en que existe, como m´ınimo, ese n´umero de asientos libres. Los n´umeros
de filas deben aparecer en orden creciente.
 Funci´on que dado un n´umero de fila y un entero positivo n reserve n asientos en
la fila especificada. Devuelve un vector con los n´umeros de los asientos reservados.
Puedes suponer que el n´umero de fila es correcto y que la fila contiene esa
cantidad de asientos libres.
 Funci´on que dado un entero positivo n reserve n asientos en la sala. Si no existen
n asientos en la sala no se debe reservar ninguno. Devuelve un vector con los
n´umeros de los asientos reservados. El valor de retorno de la funci´on es un valor
l ´ogico que indica si la sala conten´ıa al menos n asientos libres.
Escriba una funci´on main que solicite cantidades de entradas. Si la cantidad de entradas
es mayor a la cantidad de asientos libres ind´ıquelo en la pantalla. Si es menor o
igual reserve esas entradas. Proceda solicitando cantidades de entradas y reservando
hasta que no haya entradas libres en la sala o se introduzca una cantidad de entradas
negativa. Reserve entradas de la siguiente forma:
 Si es posible albergar todas las entradas en la misma fila, reserve la fila de mayor
numeraci´on con capacidad para albergar el n´umero de entradas solicitadas.
 En otro caso obtenga los asientos de cualquier lugar disponible.
Cada vez que se reserven entradas muestre los n´umeros de entradas reservadas y la
ocupaci´on global de la sala. Por ejemplo:
0: L L L L L L L L L L
1: L L L L L L L L L L
2: L L L L L L L L L L
3: L L L L L L L L L L
4: L L L L L L L L L L
5: L L L L L L L L L L
6: L L L L L L L L L L
7: L L L L L L L L L L
8: L L L L L L L L L L
9: L L L L L L L L L L
Cantidad de entradas: 8
Asientos reservados: [90, 91, 92, 93, 94, 95, 96, 97]
0: L L L L L L L L L L
1: L L L L L L L L L L
2: L L L L L L L L L L
3: L L L L L L L L L L
4: L L L L L L L L L L
5: L L L L L L L L L L
6: L L L L L L L L L L
7: L L L L L L L L L L
8: L L L L L L L L L L
9: O O O O O O O O L L
Cantidad de entradas: 11
Asientos reservados: [98, 99, 80, 81, 82, 83, 84, 85, 86, 87, 88]
0: L L L L L L L L L L
1: L L L L L L L L L L
2: L L L L L L L L L L
3: L L L L L L L L L L
4: L L L L L L L L L L
5: L L L L L L L L L L
6: L L L L L L L L L L
7: L L L L L L L L L L
8: O O O O O O O O O L
9: O O O O O O O O O O
Cantidad de entradas:
*/
#include <iostream>
#include <vector>

const int FILAS = 10;
const int ASIENTOS_POR_FILA = 10;

// Estructura para representar un asiento en la sala de cine
struct Asiento {
    bool reservado = false; // Indica si el asiento está reservado o no
};

// Función para iniciar la matriz de la sala de cine
void iniciarSala(std::vector<std::vector<Asiento>>& sala) {
    sala.resize(FILAS, std::vector<Asiento>(ASIENTOS_POR_FILA));
}

// Función para mostrar la ocupación de la sala de cine
void mostrarOcupacion(const std::vector<std::vector<Asiento>>& sala) {
    for (int fila = 0; fila < FILAS; fila++) {
        std::cout << fila << ": ";
        for (int asiento = 0; asiento < ASIENTOS_POR_FILA; asiento++) {
            char estado = sala[fila][asiento].reservado ? 'O' : 'L';
            std::cout << estado << " ";
        }
        std::cout << std::endl;
    }
}

// Función para contar los asientos libres en la sala de cine
int contarAsientosLibres(const std::vector<std::vector<Asiento>>& sala) {
    int contador = 0;
    for (int fila = 0; fila < FILAS; fila++) {
        for (int asiento = 0; asiento < ASIENTOS_POR_FILA; asiento++) {
            if (!sala[fila][asiento].reservado) {
                contador++;
            }
        }
    }
    return contador;
}

// Función para obtener las filas con un número mínimo de asientos libres
std::vector<int> obtenerFilasConAsientosLibres(const std::vector<std::vector<Asiento>>& sala, int numAsientos) {
    std::vector<int> filasConAsientosLibres;
    for (int fila = 0; fila < FILAS; fila++) {
        int asientosLibres = 0;
        for (int asiento = 0; asiento < ASIENTOS_POR_FILA; asiento++) {
            if (!sala[fila][asiento].reservado) {
                asientosLibres++;
            }
        }
        if (asientosLibres >= numAsientos) {
            filasConAsientosLibres.push_back(fila);
        }
    }
    return filasConAsientosLibres;
}

// Función para reservar asientos en una fila específica
std::vector<int> reservarAsientosEnFila(std::vector<std::vector<Asiento>>& sala, int fila, int numAsientos) {
    std::vector<int> asientosReservados;
    int asientosLibres = 0;
    for (int asiento = 0; asiento < ASIENTOS_POR_FILA; asiento++) {
        if (!sala[fila][asiento].reservado) {
            sala[fila][asiento].reservado = true;
            asientosReservados.push_back(fila * ASIENTOS_POR_FILA + asiento);
            asientosLibres++;
            if (asientosLibres == numAsientos) {
                break;
            }
        }
    }
    return asientosReservados;
}

// Función para reservar asientos en la sala de cine
bool reservarAsientos(std::vector<std::vector<Asiento>>& sala, int numAsientos) {
    std::vector<int> filasConAsientosLibres = obtenerFilasConAsientosLibres(sala, numAsientos);

    if (filasConAsientosLibres.empty()) {
        return false; // No hay suficientes asientos libres en ninguna fila
    }

    int filaReserva = filasConAsientosLibres.back(); // Última fila con suficientes asientos libres
    std::vector<int> asientosReservados = reservarAsientosEnFila(sala, filaReserva, numAsientos);

    std::cout << "Asientos reservados: ";
    for (int asiento : asientosReservados) {
        std::cout << asiento << " ";
    }
    std::cout << std::endl;

    mostrarOcupacion(sala);

    return true;
}

int main() {
    std::vector<std::vector<Asiento>> sala;
    iniciarSala(sala);

    int numAsientos;
    std::cout << "Cantidad de entradas: ";
    std::cin >> numAsientos;

    while (numAsientos >= 0) {
        int asientosLibres = contarAsientosLibres(sala);

        if (numAsientos > asientosLibres) {
            std::cout << "No hay suficientes asientos libres. Asientos disponibles: " << asientosLibres << std::endl;
        } else {
            bool reservado = reservarAsientos(sala, numAsientos);
            if (!reservado) {
                std::cout << "No hay suficientes asientos libres para reservar " << numAsientos << " entradas." << std::endl;
            }
        }

        std::cout << "Cantidad de entradas: ";
        std::cin >> numAsientos;
    }

    return 0;
}
