// struct used to encapsulate all metadata associated with a dynamic matrix.
struct MatrizDinamica{
    double* puntero;
    size_t filas;
    size_t columnas;
};

// This function creates the matrices 
MatrizDinamica crearMatriz(size_t filas, size_t columnas){

    // first, we create an instance of the matrix struct.
    MatrizDinamica matriz_resultante;

    // we allocated a new block of memory based on the requested dimensions.
    double* matrizNueva = new double [filas * columnas];

    // we populate the structure with the allocated memory and its dimensions.
    matriz_resultante.puntero = matrizNueva;
    matriz_resultante.filas = filas;
    matriz_resultante.columnas = columnas;

    // we initialize all elements to 0.0
    for(int i= 0; i < filas; ++i){
        for(int j = 0; j < columnas; ++j){
        *(matrizNueva + (i * columnas + j)) = 0.0;
        }
    }

    // finally, we return the fully initialized matrix
    return matriz_resultante;
}

// this function adds matrices
MatrizDinamica sumarMatrices(MatrizDinamica* A, MatrizDinamica* B){
    // we check that both matrices shared the same dimensions
    if(A-> filas == B-> filas && A-> columnas == B-> columnas){
        // inside the conditional block, we crate a new matrix to store the result.
        MatrizDinamica C = crearMatriz(A->filas, A->columnas);

        // we use nested loops to add corresponding elements usign pointers arithmetic
        for(int i = 0; i < A->filas; ++i){
            for (int j =0; j < A->columnas; ++j){
                *(C.puntero + (i * A->columnas + j)) = *(A->puntero + (i * A->columnas + j)) + 
                *(B->puntero + (i * A->columnas + j));
            }
        }

    return C;
    }

    // whether the dimensions are incompatiblen, we return an invalid matrix descriptor.
    MatrizDinamica matriz_invalida;
    matriz_invalida.filas = 0;
    matriz_invalida.columnas = 0;
    matriz_invalida.puntero = nullptr;

    return matriz_invalida;
}

// This function multiplys two matrices
MatrizDinamica multiplicarMAtrices (MatrizDinamica* A, MatrizDinamica* B){
    // First, we check whether the number of columns in A matches the number of rows in B.
    if(A->columnas == B->filas){

        // We create the result matrix using A's row count and B's column count.
        MatrizDinamica matrizC = crearMatriz(A->filas, B->columnas);

        // We perform the standard matrix multiplication using nested loops and pointer arithmetic.
        for(int i = 0; i < matrizC.filas; ++i){
            for(int j = 0; j < matrizC.columnas; ++j){
                //*(matrizC.puntero + (i * matrizC.columnas + j)) = 0.0;
                for(int k = 0; k < A->columnas; ++k){
                    double producto = *(A->puntero + (i * A->columnas + k)) * *(B->puntero + (k * B->columnas + j));
                    *(matrizC.puntero + (i *matrizC.columnas + j)) += producto;
                }
            }
        }

    return matrizC;
    }

    // If the dimensions are incompatible, we return an invalid matrix descriptor.
    MatrizDinamica matriz_invalida;
    matriz_invalida.puntero = nullptr;
    matriz_invalida.filas = 0;
    matriz_invalida.columnas = 0;

    return matriz_invalida;
}

// this function is only to deletes a matrix safely to prevent memory leaks.
// This function safely deallocates the matrix to prevent memory leaks.
void destruirMatriz(MatrizDinamica* matriz){
    if(matriz->puntero != nullptr){
        delete [] matriz->puntero;
        matriz->puntero = nullptr;
        matriz->filas = 0;
        matriz->columnas = 0;
    }
}
