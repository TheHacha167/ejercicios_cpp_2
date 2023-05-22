/*

Realice un programa que solicite al usuario que piense un n´umero entero entre el 1
y el 1000. El programa tiene la oportunidad de preguntarle al usuario si el n´umero
pensado es uno dado, por ejemplo, x. El usuario debe responder si lo es, y en caso de
no serlo si x es menor o mayor al n´umero que pens´ o. El programa debe realizar un
m´aximo de 10 preguntas para descubrir el n´umero.

*/
#include <iostream>

using namespace std;

int main() {
    int numeroPensado;
    int intentos = 0;
    int limiteInferior = 1;
    int limiteSuperior = 1000;

    cout << "Piensa en un número entero entre 1 y 1000." << endl;

    // Realizar hasta un máximo de 10 preguntas
    while (intentos < 10) {
        // Calcular el número a adivinar
        int numeroAdivinado = (limiteInferior + limiteSuperior) / 2;

        cout << "¿Es " << numeroAdivinado << " el número que pensaste? (Sí/No): ";
        string respuesta;
        cin >> respuesta;

        if (respuesta == "Sí" || respuesta == "Si" || respuesta == "sí" || respuesta == "si") {
            cout << "¡Adiviné el número!" << endl;
            break;
        } else {
            cout << "¿Es el número que pensaste mayor o menor que " << numeroAdivinado << "? (Mayor/Menor): ";
            cin >> respuesta;

            if (respuesta == "Mayor" || respuesta == "mayor") {
                limiteInferior = numeroAdivinado + 1;
            } else if (respuesta == "Menor" || respuesta == "menor") {
                limiteSuperior = numeroAdivinado - 1;
            }
        }

        intentos++;
    }

    if (intentos >= 10) {
        cout << "No pude adivinar el número en menos de 10 preguntas." << endl;
    }

    return 0;
}
