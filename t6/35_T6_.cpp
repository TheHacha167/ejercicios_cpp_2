/*
Se va a trabajar en un programa de codificaci´on sencilla de cadenas de caracteres. Una
codificaci´on es una aplicaci ´on biyectiva del conjunto de los caracteres del alfabeto en
el propio conjunto de los caracteres del alfabeto. Un ejemplo de codificaci´on es la
siguiente aplicaci ´on biyectiva:
a b c d e f g h i j k l m n ˜n o p q r s t u v w x y z
b c d e f g h i j k l m n ˜n o p q r s t u v w x y z a
Dada esta codificaci´on, una cadena como “hola” se codifica como “ipmb”.
Piense y describa una forma de representar en un programa C++ una codificaci´on.
Realice las siguientes funciones.
(a) Realice una funci´on que lea de la entrada est´andar una codificaci´on y devuelva
la codificaci´on le´ıda.
(b) Funci´on que tome como entrada una codificaci´on y calcule si la codificaci´on es
correcta. Una codificaci´on es correcta si representa una aplicaci ´on biyectiva de los
caracteres del alfabeto. Nota: una forma sencilla de comprobar si una codificaci´on
es correcta consiste en comprobar que tanto en el dominio como en el codominio
aparece cada car´acter del alfabeto una ´ unica vez. Es decir, hay que comprobar
que el car´acter a aparece una ´ unica vez en el dominio, que el car´acter b aparece
una ´ unica vez en el dominio y as´ı sucesivamente hasta el car´acter z. Despu´es hay
que hacer lo mismo con el codominio.
(c) Realice una funci´on que reciba como par´ametros de entrada una codificaci´on y
como par´ametro de entrada y salida una cadena de caracteres. La funci´on debe
utilizar la codificaci´on para codificar la cadena de caracteres. Por ejemplo, dada
la codificaci´on inicial y la cadena “si”, debe cambiar la cadena a “tj”.
(d) Realice una funci´on que tome como par´ametro una codificaci´on. La funci´on debe
leer l´ıneas de la entrada est´andar y escribirlas en la salida est´andar codificadas.
Sugerencia: utilice la funci´on realizada en el ejercicio anterior. Por ejemplo, si se
leen las siguientes l´ıneas:
Realice una funci´on main que permita probar las funciones previas. La funci´on
debe leer una codificaci´on de la entrada est´andar o utilizar una por defecto. En
caso de que la codificaci´on a utilizar sea correcta, debe leer l´ıneas de la entrada
est´andar y escribirlas codificadas en la salida est´andar.
*/
#include <iostream>
#include <string>
#include <map>

// Función para leer una codificación de la entrada estándar
std::map<char, char> leerCodificacion() {
    std::map<char, char> codificacion;

    for (char c = 'a'; c <= 'z'; c++) {
        char codigo;
        std::cout << "Ingrese el código para el carácter '" << c << "': ";
        std::cin >> codigo;
        codificacion[c] = codigo;
    }

    return codificacion;
}

// Función para verificar si una codificación es correcta
bool verificarCodificacion(const std::map<char, char>& codificacion) {
    std::map<char, bool> dominio;
    std::map<char, bool> codominio;

    for (char c = 'a'; c <= 'z'; c++) {
        dominio[c] = false;
        codominio[c] = false;
    }

    for (const auto& par : codificacion) {
        char caracter = par.first;
        char codigo = par.second;

        if (dominio[caracter] || codominio[codigo]) {
            return false; // El carácter ya aparece en el dominio o codominio
        }

        dominio[caracter] = true;
        codominio[codigo] = true;
    }

    return true; // La codificación es correcta
}

// Función para codificar una cadena de caracteres según una codificación dada
std::string codificarCadena(const std::map<char, char>& codificacion, const std::string& cadena) {
    std::string codificada;

    for (char c : cadena) {
        if (codificacion.count(c) > 0) {
            codificada += codificacion.at(c);
        } else {
            codificada += c; // Si el carácter no está en la codificación, se mantiene igual
        }
    }

    return codificada;
}

// Función para leer líneas de la entrada estándar y escribirlas codificadas en la salida estándar
void leerYCodificarLineas(const std::map<char, char>& codificacion) {
    std::string linea;
    std::getline(std::cin, linea); // Limpiar el buffer

    while (std::getline(std::cin, linea)) {
        std::string codificada = codificarCadena(codificacion, linea);
        std::cout << codificada << std::endl;
    }
}

int main() {
    std::map<char, char> codificacion = leerCodificacion();

    if (verificarCodificacion(codificacion)) {
        leerYCodificarLineas(codificacion);
    } else {
        std::cout << "La codificación ingresada es incorrecta." << std::endl;
    }

    return 0;
}
