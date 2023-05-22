/*
Defina una estructura fecha que almacene el d´ıa, mes y a˜no como enteros. Realice las
siguientes funciones:
 Funci´on que reciba un puntero a una fecha y lea valores para la fecha desde la
entrada est´andar.
 Funci´on que reciba un puntero a una fecha y env´ıe la fecha a la salida est´andar
con el formato d´ıa/mes/a˜ no.
 Funci´on que dados dos punteros a fechas indique si la primera es anterior a la
segunda.
 El incremento en un a˜no de una fecha. Tenga en cuenta los a˜nos bisiestos: el
29/2/2008 m´as un a˜no es el 28/2/2009.
Realice tambi´en un programa principal que permita probar el funcionamiento de las
funciones
*/
#include <iostream>

struct fecha {
    int dia;
    int mes;
    int anio;
};

void leerFecha(fecha* f) {
    std::cout << "Ingrese el dia: ";
    std::cin >> f->dia;
    std::cout << "Ingrese el mes: ";
    std::cin >> f->mes;
    std::cout << "Ingrese el año: ";
    std::cin >> f->anio;
}

void imprimirFecha(const fecha* f) {
    std::cout << f->dia << "/" << f->mes << "/" << f->anio << std::endl;
}

bool esAnterior(const fecha* f1, const fecha* f2) {
    if (f1->anio < f2->anio) {
        return true;
    } else if (f1->anio > f2->anio) {
        return false;
    } else {
        if (f1->mes < f2->mes) {
            return true;
        } else if (f1->mes > f2->mes) {
            return false;
        } else {
            if (f1->dia < f2->dia) {
                return true;
            } else {
                return false;
            }
        }
    }
}

void incrementarAnio(fecha* f) {
    if (f->mes == 2 && f->dia == 29) {
        if ((f->anio % 4 == 0 && f->anio % 100 != 0) || f->anio % 400 == 0) {
            f->dia = 28;
        }
    }
    f->anio++;
}

int main() {
    fecha f1, f2;

    std::cout << "Ingrese la primera fecha:\n";
    leerFecha(&f1);
    std::cout << "La primera fecha ingresada es: ";
    imprimirFecha(&f1);

    std::cout << "Ingrese la segunda fecha:\n";
    leerFecha(&f2);
    std::cout << "La segunda fecha ingresada es: ";
    imprimirFecha(&f2);

    if (esAnterior(&f1, &f2)) {
        std::cout << "La primera fecha es anterior a la segunda.\n";
    } else {
        std::cout << "La primera fecha no es anterior a la segunda.\n";
    }

    std::cout << "Incrementando un año a la primera fecha...\n";
    incrementarAnio(&f1);
    std::cout << "La primera fecha luego del incremento es: ";
    imprimirFecha(&f1);

    return 0;
}
