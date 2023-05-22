/*
Escribe un programa que lea de la entrada est´andar dos n´umeros y muestre en la
salida est´andar su suma, resta, multiplicaci´on y divisi ´on. Nota: suponiendo que las
variables x e y almacenan dos n´umeros, las expresiones x+y, x-y, x*y y x/d calculan
la suma, resta, producto y divisi ´on respectivamente de los valores almacenados en

las variables. Suponiendo que el usuario introduce los n´umeros 6 y 3 el programa
mostrar´a lo siguiente:
Suma: 9
Resta: 3
Producto: 18
Division: 2

*/

#include <iostream>

int main() {
    double x, y;
    std::cout << "Introduce el primer número: ";
    std::cin >> x;
    std::cout << "Introduce el segundo número: ";
    std::cin >> y;

    std::cout << "Suma: " << x + y << std::endl;
    std::cout << "Resta: " << x - y << std::endl;
    std::cout << "Producto: " << x * y << std::endl;
    if (y != 0) {
        std::cout << "División: " << x / y << std::endl;
    } else {
        std::cout << "No se puede dividir por cero." << std::endl;
    }

    return 0;
}
