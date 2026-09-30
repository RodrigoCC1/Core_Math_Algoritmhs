// Code to multiply matrices only with pointers

// first we declare the function. This function will recieve three pointers that represent matrices each one and one integer (N)
void multplyMatrices(double* A, double* B, double* C, int N){
    // initialize  the first for loop to 
    for(int i = 0; i < N; ++i){
        // initialize the second for loop
        for(int j = 0; j < N; ++j){
            // initialize the value of the Matrix C in 0.0 with its respective pointer
            *(C + (i * N + j)) = 0.0;
            // initialize the third foor loop
            for(int k = 0; k < N; ++k){
                // declare one variable to store the value of the product of the Matrices
                double prodcuct = *(A + (i*N+j)) * *(B + (k*N+j));
                // update the value in each iteration and store y the C Matrix
                *(C +(I*N+j)) += product;
            }
        }
    }
}

int main (){

     int N = 3;

    // Crear matrices dinámicas
    double* A = new double[N * N];
    double* B = new double[N * N];
    double* C = new double[N * N];

    // Llenar A
    // A = [1 2 3; 4 5 6; 7 8 9]
    double datosA[] = {1,2,3, 4,5,6, 7,8,9};
    for (int i = 0; i < N*N; i++) A[i] = datosA[i];

    // Llenar B
    // B = [10 11 12; 13 14 15; 16 17 18]
    double datosB[] = {10,11,12, 13,14,15, 16,17,18};
    for (int i = 0; i < N*N; i++) B[i] = datosB[i];

     // Multiplicar
    multiplicarMatrices(A, B, C, N);

    // Imprimir resultado
    cout << "Resultado C = A * B:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << C[i*N + j] << " ";
        }
        cout << endl;
    }

    // Liberar memoria
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}