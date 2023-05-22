/*
Realice una funci´on con las siguientes caracter´ısticas:
 Entradas: un vector de enteros v y su tama˜ no.
 Salidas: un vector de enteros sal y su tama˜ no. El vector sal debe contener los elementos
de v pero sin contener repetidos. Por ejemplo, si v contiene los elementos
f2, 4, 2, 7, 7, 2g entonces sal debe contener los elementos f2, 4, 7g.
Realice tambi´en una funci´on main que permita probar el funcionamiento de la funci´on
dise ˜ nada. Sugerencia: antes de insertar un elemento en el vector de salida verifique
que no se encuentra ya en dicho vector.
*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> eliminarRepetidos(const std::vector<int>& v) {
    std::vector<int> sal;

    for (int i = 0; i < v.size(); i++) {
        // Verificar si el elemento ya está en el vector de salida
        if (std::find(sal.begin(), sal.end(), v[i]) == sal.end()) {
            // Si no está presente, agregarlo al vector de salida
            sal.push_back(v[i]);
        }
    }

    return sal;
}

int main() {
    std::vector<int> v = {2, 4, 2, 7, 7, 2};

    std::vector<int> sal = eliminarRepetidos(v);

    std::cout << "Vector original: ";
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Vector sin elementos repetidos: ";
    for (int i = 0; i < sal.size(); i++) {
        std::cout << sal[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
