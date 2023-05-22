/*
Defina una estructura persona que conste de los campos nombre y edad. Defina
tambi´en un vector de personas. Cree un vector de punteros que mantenga el vector de
personas ordenado por el nombre y otro vector de punteros que mantenga el vector de
personas ordenado por la edad—v´ease la Figura 7.10. Muestre en la salida est´andar el
vector ordenado por nombre y luego el vector ordenado por edad apoy´andose en los
vectores de punteros.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct persona {
    std::string nombre;
    int edad;
};

bool compararPorNombre(const persona* a, const persona* b) {
    return a->nombre < b->nombre;
}

bool compararPorEdad(const persona* a, const persona* b) {
    return a->edad < b->edad;
}

void mostrarVectorPersonas(const std::vector<persona*>& vectorPersonas) {
    for (const auto& p : vectorPersonas) {
        std::cout << "Nombre: " << p->nombre << ", Edad: " << p->edad << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<persona> vectorOriginal = {
        {"Juan", 25},
        {"María", 30},
        {"Carlos", 20},
        {"Laura", 28},
        {"Pedro", 35}
    };

    std::vector<persona*> vectorPunterosNombre;
    std::vector<persona*> vectorPunterosEdad;

    // Llenar los vectores de punteros
    for (auto& p : vectorOriginal) {
        vectorPunterosNombre.push_back(&p);
        vectorPunterosEdad.push_back(&p);
    }

    // Ordenar los vectores de punteros
    std::sort(vectorPunterosNombre.begin(), vectorPunterosNombre.end(), compararPorNombre);
    std::sort(vectorPunterosEdad.begin(), vectorPunterosEdad.end(), compararPorEdad);

    // Mostrar el vector ordenado por nombre
    std::cout << "Vector ordenado por nombre:" << std::endl;
    mostrarVectorPersonas(vectorPunterosNombre);

    // Mostrar el vector ordenado por edad
    std::cout << "Vector ordenado por edad:" << std::endl;
    mostrarVectorPersonas(vectorPunterosEdad);

    return 0;
}
