/*
Utilizando una estructura fecha como la del ejercicio anterior realice las siguientes
funciones.
 Funci´on que reciba como entrada un vector de fechas y una fecha determinada
y devuelva la direcci ´on de memoria de la primera fecha del vector que coincide
con la fecha. Si la fecha no se encuentra en el vector debe devolver la direcci ´on
de memoria 0.
 Funci´on que utilice la funci´on previa para contar cu´antas ocurrencias de una
fecha existen en un vector de fechas.
 Funci´on main que defina un vector de fechas e invoque a la primera funci´on para
comprobar si una fecha est´a en el vector y para comprobar si una fecha est´a en la
segunda mitad de un vector.

*/
#include <iostream>
#include <vector>

struct fecha {
    int dia;
    int mes;
    int anio;
};

const fecha* buscarFecha(const std::vector<fecha>& vectorFechas, const fecha& fechaBuscada) {
    for (const auto& f : vectorFechas) {
        if (f.dia == fechaBuscada.dia && f.mes == fechaBuscada.mes && f.anio == fechaBuscada.anio) {
            return &f; // Devuelve la dirección de memoria de la fecha encontrada
        }
    }
    return nullptr; // La fecha no se encuentra en el vector, devuelve nullptr
}

int contarOcurrencias(const std::vector<fecha>& vectorFechas, const fecha& fechaBuscada) {
    int contador = 0;
    for (const auto& f : vectorFechas) {
        if (f.dia == fechaBuscada.dia && f.mes == fechaBuscada.mes && f.anio == fechaBuscada.anio) {
            contador++;
        }
    }
    return contador;
}

int main() {
    std::vector<fecha> vectorFechas = {
        {12, 5, 2022},
        {7, 9, 2021},
        {2, 3, 2022},
        {12, 5, 2022},
        {15, 1, 2023}
    };

    fecha fechaBuscada = {12, 5, 2022};

    const fecha* direccionMemoria = buscarFecha(vectorFechas, fechaBuscada);

    if (direccionMemoria != nullptr) {
        std::cout << "La fecha se encuentra en la dirección de memoria: " << direccionMemoria << std::endl;
    } else {
        std::cout << "La fecha no se encuentra en el vector." << std::endl;
    }

    int ocurrencias = contarOcurrencias(vectorFechas, fechaBuscada);
    std::cout << "La fecha aparece " << ocurrencias << " veces en el vector." << std::endl;

    return 0;
}
