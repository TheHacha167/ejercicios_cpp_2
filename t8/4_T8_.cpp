/*
Realice las siguientes funciones para el trabajo con vectores de strings:
 Funci´on que recibe como entrada un tama˜no y devuelve un vector ubicado en
memoria din´amica de ese tama˜ no.
 Funci´on que recibe como entrada un vector de strings y su tama˜no y muestre en
la salida est´andar los strings. Cada string debe aparecer en una l´ınea distinta.
 Funci´on que reciba un vector de strings ubicado en memoria din´amica, su tama˜no
y un nuevo tama˜ no. La funci´on debe trasladar el vector original a otro vector en
memoria din´amica que tenga el nuevo tama˜ no. Nuevo tama˜no puede ser menor
o mayor que el tama˜no previo. Se debe liberar la memoria ocupada por el vector
original y se debe devolver la direcci ´on de inicio en memoria din´amica del nuevo
vector.
 Funci´on que reciba un vector de strings y devuelva una copia del vector.
 Funci´on main que permita probar las funciones anteriores.
*/
#include <iostream>
#include <string>

std::string* crearVectorStrings(int tamano) {
    std::string* vector = new std::string[tamano];
    return vector;
}

void mostrarVectorStrings(std::string* vector, int tamano) {
    for (int i = 0; i < tamano; ++i) {
        std::cout << vector[i] << std::endl;
    }
}

std::string* redimensionarVectorStrings(std::string* vector, int tamanoActual, int nuevoTamano) {
    std::string* nuevoVector = new std::string[nuevoTamano];
    int copiarElementos = std::min(tamanoActual, nuevoTamano);
    for (int i = 0; i < copiarElementos; ++i) {
        nuevoVector[i] = vector[i];
    }
    delete[] vector;
    return nuevoVector;
}

std::string* copiarVectorStrings(const std::string* vector, int tamano) {
    std::string* nuevoVector = new std::string[tamano];
    for (int i = 0; i < tamano; ++i) {
        nuevoVector[i] = vector[i];
    }
    return nuevoVector;
}

int main() {
    int tamano;
    std::cout << "Ingrese el tamaño del vector de strings: ";
    std::cin >> tamano;

    std::string* vector = crearVectorStrings(tamano);

    std::cout << "Ingrese " << tamano << " strings:" << std::endl;
    for (int i = 0; i < tamano; ++i) {
        std::cin >> vector[i];
    }

    std::cout << "Contenido del vector original:" << std::endl;
    mostrarVectorStrings(vector, tamano);

    int nuevoTamano;
    std::cout << "Ingrese el nuevo tamaño del vector: ";
    std::cin >> nuevoTamano;

    std::string* nuevoVector = redimensionarVectorStrings(vector, tamano, nuevoTamano);

    std::cout << "Contenido del nuevo vector redimensionado:" << std::endl;
    mostrarVectorStrings(nuevoVector, nuevoTamano);

    std::string* copiaVector = copiarVectorStrings(nuevoVector, nuevoTamano);

    std::cout << "Copia del nuevo vector:" << std::endl;
    mostrarVectorStrings(copiaVector, nuevoTamano);

    delete[] vector;
    delete[] nuevoVector;
    delete[] copiaVector;

    return 0;
}
