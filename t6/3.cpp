/*
Realice una funci ´on que tome como par´ametros los extremos de un intervalo y un
valor y devuelva un valor l ´ogico que indique si el valor pertenece al intervalo cerrado
formado por los extremos. Por ejemplo, si los extremos son a y b, con a <= b, y el
valor es x, entonces debe devolver si x 2 [a; b].
*/
#include <iostream>

bool perteneceIntervalo(double a, double b, double valor) {
    return valor >= a && valor <= b;
}

int main() {
    double a = 1.0;
    double b = 5.0;
    double valor = 3.5;

    bool pertenece = perteneceIntervalo(a, b, valor);
    if (pertenece) {
        std::cout << "El valor " << valor << " pertenece al intervalo [" << a << ", " << b << "]" << std::endl;
    } else {
        std::cout << "El valor " << valor << " no pertenece al intervalo [" << a << ", " << b << "]" << std::endl;
    }

    return 0;
}
