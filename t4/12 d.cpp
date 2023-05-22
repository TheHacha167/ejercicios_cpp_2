/*
Para cada uno de los siguientes apartados escriba un programa que calcule el valor de
la suma o el producto expresado:
(a)
Pn
i=1 i = 1 + 2 + 3 + ::: + n
(b)
Pn
i=1 2i 􀀀 1 = 1 + 3 + 5 + ::: + 2n 􀀀 1
(c)
Qn
i=1 i = 1  2  3  :::  n
(d)
Pn
i=1 i! = 1! + 2! + 3! + ::: + n!
(e)
Pn
i=1 2i = 21 + 22 + 23 + ::: + 2n

*/
#include <iostream>

using namespace std;

int main() {
    int n;
    int suma = 0;
    int factorial = 1;

    cout << "Introduce el valor de n: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        factorial *= i;
        suma += factorial;
    }

    cout << "La suma de los factoriales del 1 al " << n << " es: " << suma << endl;

    return 0;
}
