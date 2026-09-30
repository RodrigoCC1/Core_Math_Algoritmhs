#include <cstddef>
#include <iostream>
#include <array>
#include <random>

template <size_t N>

class FiltroMediaMovil {
    private:
        // initialize std::array to 0.0
        std::array<double, N> cola_circular {};
        size_t indice = 0;
        double suma_acumulada = 0;
    public:
        // SMA filter
        double SMA(double nuevo_valor){
        suma_acumulada -= cola_circular[indice];
        suma_acumulada += nuevo_valor;
        cola_circular[indice] = nuevo_valor;

        // update index using modular arithmetic.
        indice = (indice+1) % N;
        double promedio = suma_acumulada / N;
        return promedio;
        }
    };

int main (){
    std::random_device rd;
    std::mt19937 generador(rd());
    std::normal_distribution<double> ruido_gaussiano(0.0, 2.0);

    FiltroMediaMovil <5> filtroN;

    for (int i = 0; i < 30; ++i){
        double muestra = ruido_gaussiano(generador);
        double promedio = filtroN.SMA(muestra);
        std::cout << "valor de i: " << i << "\n";
        std::cout << "valor de entrada: " << muestra << "\n";
        std::cout << "valor filtrado: " << promedio << "\n";
    }
};