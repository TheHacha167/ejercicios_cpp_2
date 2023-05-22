/*
Escriba una funci´on que tome como par´ametros dos punteros a datos del mismo tipo
e intercambie el contenido de las zonas de memoria a las que apuntan los punteros.
Es decir, la funci´on debe intercambiar a sus dos par´ametros—recibidos por referencia
mediante sintaxis de paso de punteros.
*/
void intercambiarContenido(int* ptr1, int* ptr2) {
    int temp = *ptr1;  // Almacenar el valor de la zona de memoria apuntada por ptr1
    *ptr1 = *ptr2;     // Copiar el contenido de la zona de memoria apuntada por ptr2 a ptr1
    *ptr2 = temp;      // Copiar el contenido guardado en temp a la zona de memoria apuntada por ptr2
}
