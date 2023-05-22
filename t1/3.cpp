/*
Realice un programa que lea de la entrada est´andar los siguientes datos de una persona:
 Edad: dato de tipo entero.
 Sexo: dato de tipo car´acter.
 Altura en metros: dato de tipo real.
Tras leer los datos, el programa debe mostrarlos en la salida est´andar. Tenga en cuenta
que un dato de tipo car´acter—char—s´olo puede almacenar un car´acter, por lo que
como usuario del programa s ´olo puede introducir un car´acter para el sexo—por ejemplo,
M o F.

*/

#include <iostream>

int main() {
    int edad;
    char sexo;
    float altura;

    std::cout << "Introduce tu edad: ";
    std::cin >> edad;

    std::cout << "Introduce tu sexo (M o F): ";
    std::cin >> sexo;

    std::cout << "Introduce tu altura en metros: ";
    std::cin >> altura;

    std::cout << "\nEdad: " << edad << "\nSexo: " << sexo << "\nAltura en metros: " << altura << std::endl;

    return 0;
}
