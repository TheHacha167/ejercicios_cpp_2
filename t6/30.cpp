/*
Un a˜no es bisiesto si es divisible por 4, excepto el ´ ultimo de cada siglo (aquel divisible
por 100), salvo que este ´ ultimo sea divisible por 400. De este modo 2004, 2008 o 2012
son bisiestos, pero no lo son 2100, 2200 o 2300, y s´ı lo es 2400. Realice una funci´on que
dado un a˜no devuelva si es bisiesto.
*/
#include <iostream>

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

int main() {
    int anio;

    std::cout << "Ingrese un año: ";
    std::cin >> anio;

    if (esBisiesto(anio)) {
        std::cout << anio << " es un año bisiesto." << std::endl;
    } else {
        std::cout << anio << " no es un año bisiesto." << std::endl;
    }

    return 0;
}

