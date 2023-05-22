/*
Una aplicaci ´on almacena la siguiente informaci´on sobre cada persona: nombre, n´umero
del DNI y edad. Las personas se almacenan en un vector ordenado seg ´un el DNI. Realice
las siguientes funciones:
 Funci´on que, dado un n´umero de DNI dni y un vector de personas, devuelva la
primera posici´on del vector que contiene a una persona cuyo n´umero de DNI es
igual o superior a dni o el n´umero de elementos del vector si no hay tal persona
en el vector.
 Funci´on que, dado un vector de personas y una posici´on p del vector, desplace
una posici´on a la derecha a todos los elementos del vector cuya posici´on sea igual
o mayor que p.
 Funci´on que, dado un vector de personas y una posici´on p del vector, desplace
una posici´on a la izquierda a todos los elementos del vector cuya posici´on sea
mayor que p.
 Funci´on que, dado un vector de personas, muestre en la salida est´andar su contenido.
 Funci´on que lea de la entrada est´andar, y devuelva, los datos de una persona. El
rango de edades admitido es: [0,150].
Realice un programa principal que permita mediante un men´u gestionar un vector
ordenado de personas. El programa debe permitir:
 Introducir una nueva persona. Sugerencia: utilice las dos primeras funciones.
Dada una nueva persona utilice la primera funci´on para comprobar si ya est´a en
el vector. En caso de que ya est´e rechace su introducci´on. En el caso de que no
est´e cree un hueco en el vector para ella—con la segunda funci´on—e ins´ertela en
la posici´on correspondiente.
 Eliminar una persona. Sugerencia: utilice la primera funci´on para localizar su
posici´on en el vector—si es que est´a—y la tercera funci´on para suprimirla.Mostrar el contenido del vector.
*/
#include <iostream>
#include <vector>
#include <string>

struct Persona {
    std::string nombre;
    int dni;
    int edad;
};

int buscarPosicion(const std::vector<Persona>& personas, int dni) {
    int pos = 0;
    while (pos < personas.size() && personas[pos].dni < dni) {
        pos++;
    }
    return pos;
}

void desplazarDerecha(std::vector<Persona>& personas, int pos) {
    personas.push_back(personas.back());
    for (int i = personas.size() - 2; i > pos; i--) {
        personas[i] = personas[i - 1];
    }
}

void desplazarIzquierda(std::vector<Persona>& personas, int pos) {
    for (int i = pos; i < personas.size() - 1; i++) {
        personas[i] = personas[i + 1];
    }
    personas.pop_back();
}

void mostrarPersonas(const std::vector<Persona>& personas) {
    for (const auto& persona : personas) {
        std::cout << "Nombre: " << persona.nombre << ", DNI: " << persona.dni << ", Edad: " << persona.edad << std::endl;
    }
}

Persona leerPersona() {
    Persona persona;
    std::cout << "Introduce el nombre: ";
    std::cin >> persona.nombre;
    std::cout << "Introduce el DNI: ";
    std::cin >> persona.dni;
    std::cout << "Introduce la edad: ";
    std::cin >> persona.edad;
    return persona;
}

int main() {
    std::vector<Persona> personas;

    int opcion;
    do {
        std::cout << "Menú:" << std::endl;
        std::cout << "1. Introducir una nueva persona" << std::endl;
        std::cout << "2. Eliminar una persona" << std::endl;
        std::cout << "3. Mostrar el contenido del vector" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Elige una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                Persona nuevaPersona = leerPersona();
                int pos = buscarPosicion(personas, nuevaPersona.dni);
                if (pos < personas.size() && personas[pos].dni == nuevaPersona.dni) {
                    std::cout << "La persona ya existe en el vector." << std::endl;
                } else {
                    desplazarDerecha(personas, pos);
                    personas[pos] = nuevaPersona;
                    std::cout << "Persona añadida correctamente." << std::endl;
                }
                break;
            }
            case 2: {
                int dniEliminar;
                std::cout << "Introduce el DNI de la persona a eliminar: ";
                std::cin >> dniEliminar;
                int pos = buscarPosicion(personas, dniEliminar);
                if (pos < personas.size() && personas[pos].dni == dniEliminar) {
                    desplazarIzquierda(personas, pos);
                    std::cout << "Persona eliminada correctamente." << std::endl;
                } else {
                    std::cout << "No se encontró ninguna persona con ese DNI en el vector." << std::endl;
                }
                break;
            }
            case 3:
                mostrarPersonas(personas);
                break;
            case 4:
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            default:
                std::cout << "Opción no válida. Inténtalo de nuevo." << std::endl;
                break;
        }

        std::cout << std::endl;
    } while (opcion != 4);

    return 0;
}
