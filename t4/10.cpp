/*

Realice un programa que lea caracteres de la entrada est´andar hasta que se introduzca
el car´acter + o -. Indique si todos los caracteres le´ıdos—salvo el ´ ultimo que hace de
centinela—han sido vocales min´ usculas.

*/
#include <iostream>

using namespace std;

int main() {
    char caracter;
    bool todasVocalesMin = true;

    cout << "Introduce caracteres (+' o -' para terminar): ";

    do {
        cin >> caracter;

        if (caracter != '+' && caracter != '-') {
            if (caracter != 'a' && caracter != 'e' && caracter != 'i' && caracter != 'o' && caracter != 'u') {
                todasVocalesMin = false;
            }
        }
    } while (caracter != '+' && caracter != '-');

    if (todasVocalesMin) {
        cout << "Todos los caracteres leídos (excepto el último) han sido vocales minúsculas." << endl;
    } else {
        cout << "No todos los caracteres leídos (excepto el último) han sido vocales minúsculas." << endl;
    }

    return 0;
}
