/*
En este ejercicio vamos a trabajar con un vector que puede crecer din´amicamente durante
la ejecuci ´on del programa. El vector se representar´a como una estructura con
tres campos:
 Un campo de tipo puntero que alberga la direcci ´on de inicio del vector en memoria
din´amica.
 Un campo entero que guarde el tama˜no f´ısico del vector. Es decir, cu´antos elementos
tenemos reservados en memoria din´amica.
 Un campo entero que almacene el tama˜no l ´ogico del vector. Es decir, que indique
cu´antos elementos del tama˜no f´ısico se est´an utilizando en realidad.
Para trabajar con el vector se utilizar´an cuatro funciones:
 Una funci´on inicia que dada una estructura de tipo vector y un tama˜no f´ısico solicita
memoria din´amica para el vector y actualiza los tres campos de la estructura
apropiadamente. Por ejemplo, el campo del tama˜no l ´ogico se debe iniciar a cero.
 Una funci´on consulta que dada una estructura de tipo vector y un ´ındice devuelva
el valor ubicado en dicho ´ındice en el vector. Se puede suponer que el ´ındice
suministrado es correcto—o sea que est´a entre el valor cero y el tama˜no l ´ogico
del vector menos uno.
 Una funci´on destruye que dada una estructura de tipo vector libera los recursos
asociados a dicho vector, es decir, su memoria din´amica. Los campos de tama˜no
f´ısico y l ´ogico se deben poner a cero.
 Una funci´on mete que dado una estructura de tipo vector y un dato debe a˜ nadir
el dato al final del vector, es decir, despu´es del ´ ultimo dato que almacena el vector.
En caso de que el tama˜no l ´ogico del vector sea inferior a su tama˜no f´ısico la
inserci ´on es sencilla. Si tama˜no l ´ogico y f´ısico coinciden entonces hay que: 1) solicitar
un vector en memoria din´amica con tama˜no igual al tama˜no f´ısico previo
m´as cinco, 2) copiar los datos del vector antiguo al nuevo vector, 3) a˜ nadir el dato
al nuevo vector, 4) liberar la memoria din´amica asociada al vector antiguo y 5) actualizar
los datos de la estructura vector para que refleje los cambios realizados.
Por ´ ultimo, escribe una funci´on main que cree un vector de tama˜no f´ısico 5 usando
la funci´on inicia y mediante un ciclo con centinela lea datos de la entrada y los vaya
metiendo en el vector din´amico. Cuando el usuario haya terminado su introducci´on
muestra los datos del vector en la salida usando la funci´on consulta y destruye el vector
justo antes de terminar el programa. Observa que en todas las funciones previas el
par´ametro de tipo estructura que representa el vector es un par´ametro de entrada y
salida, salvo en la funci´on consulta en donde es un par´ametro de entrada.

*/
#include <iostream>

struct Vector {
    int* elementos;
    int tamanoFisico;
    int tamanoLogico;
};

void inicia(Vector& vector, int tamanoFisico) {
    vector.elementos = new int[tamanoFisico];
    vector.tamanoFisico = tamanoFisico;
    vector.tamanoLogico = 0;
}

int consulta(const Vector& vector, int indice) {
    return vector.elementos[indice];
}

void destruye(Vector& vector) {
    delete[] vector.elementos;
    vector.elementos = nullptr;
    vector.tamanoFisico = 0;
    vector.tamanoLogico = 0;
}

void mete(Vector& vector, int dato) {
    if (vector.tamanoLogico < vector.tamanoFisico) {
        vector.elementos[vector.tamanoLogico] = dato;
        vector.tamanoLogico++;
    } else {
        int nuevoTamanoFisico = vector.tamanoFisico + 5;
        int* nuevoVector = new int[nuevoTamanoFisico];
        for (int i = 0; i < vector.tamanoFisico; ++i) {
            nuevoVector[i] = vector.elementos[i];
        }
        nuevoVector[vector.tamanoLogico] = dato;
        delete[] vector.elementos;
        vector.elementos = nuevoVector;
        vector.tamanoFisico = nuevoTamanoFisico;
        vector.tamanoLogico++;
    }
}

int main() {
    Vector vector;
    const int tamanoFisicoInicial = 5;

    inicia(vector, tamanoFisicoInicial);

    std::cout << "Ingrese elementos (ingrese -1 para finalizar):" << std::endl;
    int elemento;
    while (true) {
        std::cin >> elemento;
        if (elemento == -1) {
            break;
        }
        mete(vector, elemento);
    }

    std::cout << "Elementos del vector:" << std::endl;
    for (int i = 0; i < vector.tamanoLogico; ++i) {
        std::cout << consulta(vector, i) << std::endl;
    }

    destruye(vector);

    return 0;
}
