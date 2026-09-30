
// this function will use to increase the capacity for a array and add a new value
// // This function increases the array's capacity when needed and appends a new value.

void agregarElemento(VectorDinamico* vector, double valor_nuevo){
    // first, we verify if the elementos_actuales is greater than capacidad
    // First, we check whether the current number of elements exceeds the capacity.
    if (vector->elementos_actuales >= vector->capacidad){
        // we allocate the new caapcity for the array
        // We allocate a new block of memory with increased capacity.
        double* nuevo_vector = new double[vector->capacidad+1];
        
        // now we copy all the values to the new array using a for loop
        // We copy all existing elements into the newly allocated array.
        for(int i = 0; i<vector->capacidad; ++i){
            *(nuevo_vector + i) = *(vector + i);
        }

        // we avoid memory leak deleting the old array
        // We delete the old array to prevent memory leaks.
        delete [] vector->puntero;

        // we update the pointer
        // We update the internal pointer to reference the new array.
        vector->puntero = nuevo_vector;

        // we increase the capacity
        // We update the capacity to reflect the new size.
        vector->capacidad++;

    }

    // we add the new value outside the if statement because the addition to the value always happens and aslo we increase the 
    // currently elements  
    // We insert the new value outside the conditional block because insertion always occurs,
    // regardless of whether the array was resized.
    *(nuevo_vector + elementos_actuales) = valor_nuevo;
    vector->elementos_actuales++;
}