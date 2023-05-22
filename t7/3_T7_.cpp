/*
Escriba una funci´on que tome como par´ametro un vector y su tama˜no y devuelva
el m´aximo y el m´ınimo de sus elementos. Utilice par´ametros de tipo puntero para
especificar el vector y los par´ametros de salida de la funci´on.
*/
void encontrarMaximoMinimo(const int* vector, int tamano, int* maximo, int* minimo) {
    if (tamano == 0) {
        // Si el tamaño del vector es cero, no hay elementos, por lo que no hay máximo ni mínimo
        *maximo = *minimo = 0;
        return;
    }

    // Inicializar el máximo y el mínimo con el primer elemento del vector
    *maximo = *minimo = vector[0];

    // Recorrer el vector para encontrar el máximo y el mínimo
    for (int i = 1; i < tamano; i++) {
        if (vector[i] > *maximo) {
            *maximo = vector[i];
        }
        if (vector[i] < *minimo) {
            *minimo = vector[i];
        }
    }
}
