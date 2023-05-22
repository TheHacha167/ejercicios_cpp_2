/*
Modifica el programa anterior de forma que se pueda gestionar un cine con varias
salas. El n´umero de salas gestionadas lo decidir´a el usuario, pero como m´aximo ser´an
5. Para albergar las salas se recomienda usar un array tridimensional:
const int NFILAS = 1 0 ;
const int NCOL = 1 0 ;
const int NSALAS = 5 ;
int main ( ) f
bool c ine [NSALAS] [NFILAS ] [NCOL] ;
g
donde la primera dimensi´on indica el n´umero de sala. Recuerda que tal como se indic´o
en la Secci´on 6.10.1 una funci´on que tome como par´ametro un array tridimensional
debe especificar al menos las dos dimensiones ´ ultimas. Por ejemplo, la funci´on que
calcula el n´umero de asientos libres de una sala podr´ıa tener la siguiente signatura:
int l i b r e s ( const bool c ine [ ] [NFILAS ] [NCOL] , int s a l a )
Listamos un ejemplo de ejecuci ´on, por si puede servir de referencia:
Introduce numero de salas (maximo 5): 2
0: L L L L L L L L L L 0: L L L L L L L L L L
1: L L L L L L L L L L 1: L L L L L L L L L L
2: L L L L L L L L L L 2: L L L L L L L L L L
3: L L L L L L L L L L 3: L L L L L L L L L L
4: L L L L L L L L L L 4: L L L L L L L L L L
5: L L L L L L L L L L 5: L L L L L L L L L L
6: L L L L L L L L L L 6: L L L L L L L L L L
7: L L L L L L L L L L 7: L L L L L L L L L L
8: L L L L L L L L L L 8: L L L L L L L L L L
9: L L L L L L L L L L 9: L L L L L L L L L L
Introduce la sala: 0
Cantidad de entradas: 5
Asientos reservados: 90 91 92 93 94
0: L L L L L L L L L L 0: L L L L L L L L L L
1: L L L L L L L L L L 1: L L L L L L L L L L
2: L L L L L L L L L L 2: L L L L L L L L L L
3: L L L L L L L L L L 3: L L L L L L L L L L
4: L L L L L L L L L L 4: L L L L L L L L L L
5: L L L L L L L L L L 5: L L L L L L L L L L
6: L L L L L L L L L L 6: L L L L L L L L L L
7: L L L L L L L L L L 7: L L L L L L L L L L
8: L L L L L L L L L L 8: L L L L L L L L L L
9: O O O O O L L L L L 9: L L L L L L L L L L
Introduce la sala:
*/
#include <iostream>

const int NFILAS = 10;
const int NCOL = 10;
const int NSALAS = 5;
typedef bool Sala[NFILAS][NCOL];
typedef Sala Cine[NSALAS];

int libres(const Sala& sala) {
    int count = 0;
    for (int i = 0; i < NFILAS; ++i)
        for (int j = 0; j < NCOL; ++j)
            if (!sala[i][j]) ++count;
    return count;
}

void reservarAsientos(Sala& sala, int n) {
    for (int i = 0; i < NFILAS && n > 0; ++i)
        for (int j = 0; j < NCOL && n > 0; ++j)
            if (!sala[i][j]) {
                sala[i][j] = true;
                --n;
                std::cout << "Asientos reservados: " << i << " " << j << "\n";
            }
}

void imprimirSala(const Sala& sala) {
    for (int i = 0; i < NFILAS; ++i) {
        std::cout << i << ": ";
        for (int j = 0; j < NCOL; ++j)
            std::cout << (sala[i][j] ? 'O' : 'L') << " ";
        std::cout << "\n";
    }
}

void gestionarCine() {
    Cine cine = {};
    int numSalas;
    std::cout << "Introduce numero de salas (maximo 5): ";
    std::cin >> numSalas;
    for (int s = 0; s < numSalas; ++s) {
        std::cout << "Sala " << s << "\n";
        imprimirSala(cine[s]);
    }

    while (true) {
        int salaNum;
        std::cout << "Introduce la sala: ";
        std::cin >> salaNum;
        if (salaNum < 0 || salaNum >= numSalas) {
            std::cout << "Sala invalida.\n";
            continue;
        }

        int entradas;
        std::cout << "Cantidad de entradas: ";
        std::cin >> entradas;

        if (entradas > libres(cine[salaNum])) {
            std::cout << "No hay suficientes asientos libres.\n";
            continue;
        }

        reservarAsientos(cine[salaNum], entradas);
        imprimirSala(cine[salaNum]);
    }
}

int main() {
    gestionarCine();
    return 0;
}
