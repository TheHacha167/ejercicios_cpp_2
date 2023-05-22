/*


Cuando se compra una cajetilla de tabaco en unam´aquina y no se introduce el importe
exacto, lam´aquina utiliza un programa para devolver el m´ınimo n´umero de monedas.
Escriba un programa—considerando ´ unicamente monedas de 5, 10, 20 y 50 c´entimos
de euro—que lea de la entrada est´andar el importe de una cajetilla de tabaco y la
cantidad de dinero introducida por el comprador en la m´aquina y escriba en la salida
est´andar la monedas devueltas por la m´aquina. Nota: trabaja con c´entimos en lugar
de euros para que los c´aculos sean m´as sencillos.

*/
#include <iostream>

using namespace std;

int main() {
    int precio, pago;

    cout << "Introduce el precio de la cajetilla (en centimos): ";
    cin >> precio;

    cout << "Introduce el importe que ha introducido el comprador (en centimos): ";
    cin >> pago;

    int cambio = pago - precio;

    if (cambio < 0) {
        cout << "El importe introducido no es suficiente para cubrir el precio de la cajetilla." << endl;
        return 0;
    }

    int monedas50 = cambio / 50;
    cambio -= monedas50 * 50;

    int monedas20 = cambio / 20;
    cambio -= monedas20 * 20;

    int monedas10 = cambio / 10;
    cambio -= monedas10 * 10;

    int monedas5 = cambio / 5;
    cambio -= monedas5 * 5;

    cout << "La maquina devuelve: " << endl;
    cout << monedas50 << " monedas de 50 centimos" << endl;
    cout << monedas20 << " monedas de 20 centimos" << endl;
    cout << monedas10 << " monedas de 10 centimos" << endl;
    cout << monedas5 << " monedas de 5 centimos" << endl;

    return 0;
}
