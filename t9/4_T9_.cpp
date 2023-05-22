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

int mcdRecursivo(int x, int y) {
    if (y == 0) {
        return x;
    }

    return mcdRecursivo(y, x % y);
}

