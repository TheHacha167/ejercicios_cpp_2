/*
Escribe una funci´on que intercambie el valor de sus dos par´ametros.


*/
#include <iostream>

void intercambiar(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int num1 = 5;
    int num2 = 10;

    std::cout << "Antes del intercambio: " << num1 << ", " << num2 << std::endl;

    intercambiar(num1, num2);

    std::cout << "Después del intercambio: " << num1 << ", " << num2 << std::endl;

    return 0;
}
