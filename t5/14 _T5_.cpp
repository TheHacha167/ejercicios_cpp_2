/*
Dados dos vectores A y B de n y m enteros respectivamente, ordenados de menor
a mayor y sin repetidos, escribe un programa que construya un nuevo vector C de
tama˜no l ´ogico k, con k <= n +m, que sea el resultado de mezclar los vectores A y B, de
manera que el vector C est´e ordenado y no contenga elementos repetidos.
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> mezclarVectores(const vector<int>& vector1, const vector<int>& vector2) {
    vector<int> vectorMezclado;
    int indice1 = 0;
    int indice2 = 0;

    // Combinar los vectores ordenadamente sin elementos repetidos
    while (indice1 < vector1.size() && indice2 < vector2.size()) {
        if (vector1[indice1] < vector2[indice2]) {
            vectorMezclado.push_back(vector1[indice1]);
            indice1++;
        } else if (vector2[indice2] < vector1[indice1]) {
            vectorMezclado.push_back(vector2[indice2]);
            indice2++;
        } else { // Ambos elementos son iguales
            vectorMezclado.push_back(vector1[indice1]);
            indice1++;
            indice2++;
        }
    }

    // Agregar los elementos restantes del vector1, si los hay
    while (indice1 < vector1.size()) {
        vectorMezclado.push_back(vector1[indice1]);
        indice1++;
    }

    // Agregar los elementos restantes del vector2, si los hay
    while (indice2 < vector2.size()) {
        vectorMezclado.push_back(vector2[indice2]);
        indice2++;
    }

    return vectorMezclado;
}

int main() {
    vector<int> vector1 = {1, 3, 5, 7, 9};
    vector<int> vector2 = {2, 4, 6, 8, 10};

    vector<int> vectorMezclado = mezclarVectores(vector1, vector2);

    cout << "Vector mezclado: ";
    for (int i = 0; i < vectorMezclado.size(); i++) {
        cout << vectorMezclado[i] << " ";
    }
    cout << endl;

    return 0;
}
