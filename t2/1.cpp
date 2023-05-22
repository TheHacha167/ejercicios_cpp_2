/*

Calcule el valor de la variable result, de tipo double, tras la ejecuci´on de las siguientes
asignaciones:
(a) 
    r e s u l t = 3 . 0 * 5 . 0 ;
(b)
    x = 2 . 0 ;
    y = 3 . 0 ;
    r e s u l t = pow( x , y)􀀀x ;
(c)
    r e s u l t = 4 . 0 ;
    x = 2 . 0 ;
    r e s u l t = r e s u l t * x ;

*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double result, x, y;

    // (a)
    result = 3.0 * 5.0;
    cout << "Resultado (a): " << result << endl; // 15.0

    // (b)
    x = 2.0;
    y = 3.0;
    result = pow(x, y) - x;
    cout << "Resultado (b): " << result << endl; // 6.0

    // (c)
    result = 4.0;
    x = 2.0;
    result = result * x;
    cout << "Resultado (c): " << result << endl; // 8.0

    return 0;
}
