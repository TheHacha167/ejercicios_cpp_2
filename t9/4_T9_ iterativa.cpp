/*
En su libro Elementos el matem´atico griego Euclides describi´o un m´etodo para calcular
elm´aximo com´un divisor de dos enteros. Elm´etodo se puede describir con la siguiente
recurrencia:
mcd(x; y) =
(
x si y = 0
mcd(y; resto(x; y)) si x  y y y > 0
Realice una funci´on recursiva y otra iterativa que calculen el m´aximo com´un divisor
de dos enteros.
*/
#include <iostream>

int mcdIterativo(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }

    return x;
}
