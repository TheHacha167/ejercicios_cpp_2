/*
Realice una funci´on que dadas dos cadenas de caracteres, s1 y s2, devuelva si la primera
cadena es menor lexicogr´aficamente que la segunda. Esto se puede realizar trivialmente
con la expresi ´on s1 < s2. Realice una implementaci´on alternativa en la que vaya
comparando los caracteres de las dos cadenas. Tenga en cuenta que una cadena s1 es
menor lexicogr´aficamente que otra cadena s2 si se verifica que:En el primer car´acter en que difieren las dos cadenas se verifica que el car´acter de
s1 es menor lexicogr´aficamente que el car´acter de s2. Por ejemplo, abc es menor
que abd porque en el primer car´acter en que difieren se verifica que ’c’ < ’d’.
 La longitud de la cadena s1 es inferior a la longitud de la cadena s2 y todos los caracteres
existentes de s1 coinciden con los caracteres que ocupan la misma posici´on
en s2. Por ejemplo, cama es menor que camastro.
 En otro caso, s1 no es menor que s2. Por ejemplo, abc no es menor que abb, ni
que ab, ni que abc.
*/
#include <iostream>
#include <string>

bool esMenorLexicograficamente(const std::string& s1, const std::string& s2) {
    // Comparar carácter por carácter
    for (size_t i = 0; i < s1.length() && i < s2.length(); i++) {
        if (s1[i] < s2[i]) {
            return true;
        } else if (s1[i] > s2[i]) {
            return false;
        }
    }

    // Si todos los caracteres coinciden hasta el mínimo de las longitudes
    // de las cadenas, la cadena más corta es menor lexicográficamente
    return s1.length() < s2.length();
}

int main() {
    std::string s1 = "abc";
    std::string s2 = "abd";

    if (esMenorLexicograficamente(s1, s2)) {
        std::cout << s1 << " es menor lexicográficamente que " << s2 << std::endl;
    } else {
        std::cout << s1 << " no es menor lexicográficamente que " << s2 << std::endl;
    }

    return 0;
}
