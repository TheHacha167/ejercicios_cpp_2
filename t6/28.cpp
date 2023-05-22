/*
En este ejercicio se va a implementar el algoritmo de selecci ´on, que sirve para ordenar
de forma creciente una secuencia de elementos, en nuestro caso, almacenados en un
vector. Dado un vector de n elementos, por ejemplo: f5; 9; 2; 1; 4g, el algoritmo selecciona
el m´ınimo de los elementos del vector y lo intercambia por el elemento que
ocupa la primera posici´on del vector, en el ejemplo esto produce el vector f1; 9; 2; 5; 4g.
A continuaci´on selecciona el m´ınimo de los elementos entre las posiciones 1 y n 􀀀 1 y
lo intercambia por el elemento en la posici´on 1. En el ejemplo, esto produce el vector
f1; 2; 9; 5; 4g. En general, en la iteraci ´on i se selecciona el m´ınimo entre las posiciones
[i; n 􀀀 1] y se intercambia con el valor en la posici´on i, tras ello se verifica que las posiciones
[0; i] del vector contienen los i + 1 elementos menores del vector ordenados. La
funci´on de ordenaci´on por selecci ´on es la siguiente:
void s e l e c c i on ( int v [ ] , int tamv ) f
for ( int i = 0 ; i < tamv 􀀀 1 ; ++i ) f
int posmin = minimo ( v , i , tamv 􀀀1);
i f ( posmin != i )
inter cambia ( v [ i ] , v [ posmin ] ) ;
g
g
donde la funci´on intercambia es como la especificada en un ejercicio anterior y la funci´on
minimo tiene la siguiente especificaci´on:
/  De s c r i p c i ´on : Ca l c u l a l a p o s i c i ´on d e l menor e l emen t o d e l
 v e c t o r e n t r e do s p o s i c i o n e s
 Par ´ame t r o s de e n t r a d a :
 􀀀 v : e l v e c t o r
 􀀀 i : p o s i c i ´on i n i c i a l
 􀀀 f : p o s i c i ´on f i n a l
 P r e c o n d i c i o n e s : i <= f
 Va l o r de r e t o r n o : l a p o s i c i ´on d e l menor e l emen t o d e l v e c t o r
 e n t r e l a s p o s i c i o n e s [ i , f ]
 /
Implemente las funciones intercambia, minimo y seleccion, y una funci´on main que permita
probar la funci´on de ordenaci´on.
*/
#include <iostream>

void intercambia(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int minimo(int v[], int inicio, int fin) {
    int pos_min = inicio;
    for (int i = inicio + 1; i <= fin; i++) {
        if (v[i] < v[pos_min]) {
            pos_min = i;
        }
    }
    return pos_min;
}

void seleccion(int v[], int tamv) {
    for (int i = 0; i < tamv - 1; ++i) {
        int pos_min = minimo(v, i, tamv - 1);
        if (pos_min != i) {
            intercambia(v[i], v[pos_min]);
        }
    }
}

int main() {
    int v[] = {5, 9, 2, 1, 4};
    int tamv = sizeof(v) / sizeof(v[0]);

    std::cout << "Vector original: ";
    for (int i = 0; i < tamv; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    seleccion(v, tamv);

    std::cout << "Vector ordenado: ";
    for (int i = 0; i < tamv; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
