/*

Un n´umero primo es un entero mayor que 1 cuyos ´ unicos divisores enteros positivos
son el 1 y ´el mismo. Un m´etodo para encontrar todos los n´umeros primos en un rango
de 1 a N es el conocido como Criba de Erat´ostenes. Considere la lista de n´umeros entre
el 2 y N. Dos es el primer n´umero primo, pero sus m´ ultiplos (4, 6, 8, . . . ) no lo son,
por lo que se tachan de la lista. El siguiente n´umero despu´es del 2 que no est´a tachado
es el 3, el siguiente primo. Entonces tachamos de la lista todos los m´ ultiplos de 3 (6, 9,
12, . . . ). El siguiente n´umero que no est´a tachado es el 5, el siguiente primo, y entonces
tachamos todos losm´ ultiplos de 5 (10, 15, 20, . . . ). Repetimos este procedimiento hasta
que lleguemos al primer elemento de la lista cuyo cuadrado sea mayor que N. Todos
los n´umeros que no se han tachado en la lista son los primos entre 2 y N.
*/
#include <iostream>
#include <vector>

using namespace std;

void cribaEratostenes(int N) {
    vector<bool> esPrimo(N + 1, true);

    for (int p = 2; p * p <= N; p++) {
        if (esPrimo[p]) {
            for (int i = p * p; i <= N; i += p) {
                esPrimo[i] = false;
            }
        }
    }

    cout << "Números primos en el rango [1, " << N << "]:" << endl;

    for (int i = 2; i <= N; i++) {
        if (esPrimo[i]) {
            cout << i << " ";
        }
    }

    cout << endl;
}

int main() {
    int N;

    cout << "Ingrese un número entero N: ";
    cin >> N;

    cribaEratostenes(N);

    return 0;
}
