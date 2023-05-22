/*
Generalice la funci´on del ejercicio anterior de forma que las opciones del men´u se
reciban en un vector de cadenas. Cada cadena del vector representa una de las opciones
a elegir.
*/
#include <iostream>
#include <vector>

void mostrarMenu(const std::vector<std::string>& opciones) {
    std::cout << "Menú de opciones:" << std::endl;
    for (size_t i = 0; i < opciones.size(); ++i) {
        std::cout << i << " - " << opciones[i] << std::endl;
    }
}

int leerOpcion() {
    int opcion;
    std::cout << "Introduzca la opción elegida: ";
    std::cin >> opcion;
    return opcion;
}

int main() {
    std::vector<std::string> opciones = {"Introducir palabra", "Adivinar palabra", "Salir"};

    int opcion;

    do {
        mostrarMenu(opciones);
        opcion = leerOpcion();

        if (opcion >= 0 && opcion < opciones.size()) {
            std::cout << "Ha elegido la opción: " << opciones[opcion] << std::endl;

            // Aquí se puede implementar la lógica correspondiente a la opción elegida
        } else {
            std::cout << "Opción inválida. Por favor, elija una opción válida." << std::endl;
        }

    } while (opcion != opciones.size() - 1);

    return 0;
}
