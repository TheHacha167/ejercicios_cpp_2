/*
Defina una estructura fecha que almacene el d´ıa, mes y a˜no como enteros. Realice
funciones que permitan:
 La lectura de una fecha correcta de la entrada est´andar.
 El env´ıo a la salida est´andar de una fecha con el formato d´ıa/mes/a˜ no.
 La comparaci´on de dos fechas, indicando si la primera es anterior a la segunda.
 El incremento en un a˜no de una fecha. Tenga en cuenta los a˜nos bisiestos: el
29/2/2008 m´as un a˜no es el 28/2/2009.
Realice tambi´en un programa principal que permita probar el funcionamiento de las
funciones.
*/
#include <iostream>

struct Fecha {
    int dia;
    int mes;
    int anio;
};

bool esBisiesto(int anio) {
    if (anio % 4 == 0) {
        if (anio % 100 == 0) {
            if (anio % 400 == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } else {
        return false;
    }
}

bool esFechaValida(int dia, int mes, int anio) {
    if (mes < 1 || mes > 12)
        return false;

    int diasEnMes;

    if (mes == 2) {
        if (esBisiesto(anio))
            diasEnMes = 29;
        else
            diasEnMes = 28;
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        diasEnMes = 30;
    } else {
        diasEnMes = 31;
    }

    if (dia < 1 || dia > diasEnMes)
        return false;

    return true;
}

void leerFecha(Fecha& fecha) {
    do {
        std::cout << "Ingrese una fecha (dd mm aaaa): ";
        std::cin >> fecha.dia >> fecha.mes >> fecha.anio;
    } while (!esFechaValida(fecha.dia, fecha.mes, fecha.anio));
}

void mostrarFecha(const Fecha& fecha) {
    std::cout << fecha.dia << "/" << fecha.mes << "/" << fecha.anio << std::endl;
}

bool esAnterior(const Fecha& fecha1, const Fecha& fecha2) {
    if (fecha1.anio < fecha2.anio)
        return true;
    else if (fecha1.anio > fecha2.anio)
        return false;
    else {
        if (fecha1.mes < fecha2.mes)
            return true;
        else if (fecha1.mes > fecha2.mes)
            return false;
        else {
            if (fecha1.dia < fecha2.dia)
                return true;
            else
                return false;
        }
    }
}

void incrementarAnio(Fecha& fecha) {
    fecha.anio++;

    if (fecha.mes == 2 && fecha.dia == 29 && !esBisiesto(fecha.anio)) {
        fecha.dia = 28;
    }
}

int main() {
    Fecha fecha1, fecha2;

    std::cout << "Ingrese la primera fecha:" << std::endl;
    leerFecha(fecha1);

    std::cout << "Ingrese la segunda fecha:" << std::endl;
    leerFecha(fecha2);

    std::cout << "La primera fecha ingresada es: ";
    mostrarFecha(fecha1);

    std::cout << "La segunda fecha ingresada es: ";
    mostrarFecha(fecha2);

    if (esAnterior(fecha1, fecha2)) {
        std::cout << "La primera fecha es anterior a la segunda fecha." << std::endl;
    } else {
        std::cout << "La primera fecha no es anterior a la segunda fecha." << std::endl;
    }

    incrementarAnio(fecha1);
    std::cout << "La primera fecha incrementada en un año es: ";
    mostrarFecha(fecha1);

    return 0;
}
