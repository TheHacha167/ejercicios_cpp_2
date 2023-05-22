/*
Escribe las siguientes expresiones matem´aticas como expresiones en C++:
a) a/b + 1 
b) a+b/c+d 
c) (a+b/c)/(d+e/f)
d) a + b/c-d
e) (a + b) *c/d
Haz un programa que inicie las variables de tipo real a, b, c y d a los valores 2, 1, -1
y 4 respectivamente y muestre en la salida est´andar el resultado de evaluar las expresiones.
Soluci´on: a) 3, b) 1, c) 0.167, d) 1.8, e) -0.75.
*/
#include <iostream>

using namespace std;

int main() {
    double a = 2.0, b = 1.0, c = -1.0, d = 4.0, e = 5.0, f = 2.0; // Suponemos valores para e y f.

    double resultadoA = a / b + 1;
    double resultadoB = a + b / c + d;
    double resultadoC = (a + b / c) / (d + e / f);
    double resultadoD = a + b / c - d;
    double resultadoE = (a + b) * c / d;

    cout << "Resultado de a) a/b + 1 : " << resultadoA << endl;
    cout << "Resultado de b) a+b/c+d : " << resultadoB << endl;
    cout << "Resultado de c) (a+b/c)/(d+e/f) : " << resultadoC << endl;
    cout << "Resultado de d) a + b/c-d : " << resultadoD << endl;
    cout << "Resultado de e) (a + b) *c/d : " << resultadoE << endl;

    return 0;
}
