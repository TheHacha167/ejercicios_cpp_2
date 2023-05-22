/*

El DNI incluye una letra con el objeto de detectar errores al ser escrito. Dado un
n´umero de DNI la letra correspondiente se obtiene calculando el resto de dividir dicho
n´umero entre 23. Una vez obtenido el resto la Tabla 6.2 indica la letra correspondiente.
Realice una funci´on que dado un n´umero de DNI devuelva su letra asociada y un
programa que, apoy´andose en la funci´on implementada, solicite un DNI hasta que su
letra asociada sea correcta.
*/
#include <iostream>
#include <string>

char calcularLetraDNI(int dni) {
    const std::string letrasDNI = "TRWAGMYFPDXBNJZSQVHLCKE";
    int indice = dni % 23;
    return letrasDNI[indice];
}

bool validarDNI(int dni, char letra) {
    char letraCalculada = calcularLetraDNI(dni);
    return (letra == letraCalculada);
}

int main() {
    int dni;
    char letra;

    do {
        std::cout << "Introduce el número de DNI: ";
        std::cin >> dni;
        std::cout << "Introduce la letra del DNI: ";
        std::cin >> letra;

        if (!validarDNI(dni, letra)) {
            std::cout << "La letra del DNI es incorrecta. Inténtalo de nuevo." << std::endl;
        }
    } while (!validarDNI(dni, letra));

    std::cout << "DNI válido: " << dni << letra << std::endl;

    return 0;
}
