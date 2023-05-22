/*
El operador == permite comparar si dos strings son iguales, pero diferenciando entre
may´ usculas y min´ usculas. Por ejemplo ‘‘ Agosto’’ == ‘‘Agosto’’, pero ‘‘ Agosto’’ != ‘‘ agosto’’.
Desarrolle una funci´on que compare dos strings y devuelva si son iguales independientemente
de que los caracteres se encuentren en may´ usculas o en min´ usculas. Sugerencia:
en la implementaci´on puede utilizar la funci´on toupper de la biblioteca est´andar—
tendr´a que utilizar el include #include <cctype>—que devuelve el car´acter que toma
como par´ametro de entrada a su valor en may´ usculas. Si el par´ametro recibido como
entrada no es una letra min´ uscula del alfabeto ingl´es entonces devuelve el mismo
car´acter que recibi ´o como par´ametro. Por ejemplo, toupper (’a’ ) devuelve ’A’, toupper (’B’)
devuelve ’B’ y toupper (’’ ) devuelve ’’.

*/
#include <iostream>
#include <string>
#include <cctype>

bool sonIguales(const std::string& s1, const std::string& s2) {
    if (s1.length() != s2.length()) {
        return false; // Las cadenas tienen longitudes diferentes, no pueden ser iguales
    }

    for (size_t i = 0; i < s1.length(); i++) {
        // Convertir los caracteres a mayúsculas y comparar
        if (std::toupper(s1[i]) != std::toupper(s2[i])) {
            return false; // Los caracteres no coinciden, las cadenas no son iguales
        }
    }

    return true; // Todas las letras coinciden, las cadenas son iguales
}

int main() {
    std::string s1 = "Agosto";
    std::string s2 = "agosto";

    if (sonIguales(s1, s2)) {
        std::cout << s1 << " y " << s2 << " son iguales" << std::endl;
    } else {
        std::cout << s1 << " y " << s2 << " no son iguales" << std::endl;
    }

    return 0;
}
