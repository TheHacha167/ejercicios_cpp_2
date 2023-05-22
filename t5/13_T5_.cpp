/*
Realiza un programa que defina dos vectores de caracteres y despu´es almacene el contenido
de ambos vectores en un nuevo vector situando en primer lugar los elementos
del primer vector seguido por los elementos del segundo vector. Muestre el contenido
del nuevo vector en la salida est´andar.

*/
#include <iostream>
#include <vector>

using namespace std;

vector<char> combinarVectores(const vector<char>& vector1, const vector<char>& vector2) {
    vector<char> nuevoVector;

    // Combinar los elementos del primer vector
    for (int i = 0; i < vector1.size(); i++) {
        nuevoVector.push_back(vector1[i]);
    }

    // Combinar los elementos del segundo vector
    for (int i = 0; i < vector2.size(); i++) {
        nuevoVector.push_back(vector2[i]);
    }

    return nuevoVector;
}

int main() {
    vector<char> vector1 = {'a', 'b', 'c'};
    vector<char> vector2 = {'x', 'y', 'z'};

    vector<char> nuevoVector = combinarVectores(vector1, vector2);

    cout << "Contenido del nuevo vector: ";
    for (int i = 0; i < nuevoVector.size(); i++) {
        cout << nuevoVector[i] << " ";
    }
    cout << endl;

    return 0;
}
