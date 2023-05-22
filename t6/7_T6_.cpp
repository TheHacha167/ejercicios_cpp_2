/*
Implemente una funci´on que calcule la suma de los d´ıgitos de un n´umero entero positivo.
Por ejemplo, dado 3452 la suma de sus d´ıgitos es 3 + 4 + 5 + 2 = 14.
8. Realiza una funci´on que tome como par´ametros dos cadenas de caracteres y devuelva
*/

#include <iostream>

int sumaDigitos(int numero) {
    int suma = 0;

    while (numero != 0) {
        suma += numero % 10;  // Suma el último dígito al total
        numero /= 10;        // Elimina el último dígito
    }

    return suma;
}

int main() {
    int numero;

    std::cout << "Ingrese un numero entero positivo: ";
    std::cin >> numero;

    int suma = sumaDigitos(numero);

    std::cout << "La suma de los digitos de " << numero << " es: " << suma << std::endl;

    return 0;
}
