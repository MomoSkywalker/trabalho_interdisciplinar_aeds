#include <iostream>
#include <cstring>
#include "slem.h"
#include "veiculos.h"
#include "locais.h"

// Função para buscar um veículo pelo número da placa
// Retorna o índice do veículo no array, ou -1 se não for encontrado
int buscarVeiculoPorPlaca(const char* placa, const Veiculo veiculos[], int numVeiculos) {
    for (int i = 0; i < numVeiculos; ++i) {
        if (strcmp(veiculos[i].placa, placa) == 0) return i;
    }
    return -1;
}

// Função para listar todos os veículos cadastrados
void listarVeiculos(const Veiculo veiculos[], int numVeiculos) {
    for (int i = 0; i < numVeiculos; ++i) {
        std::cout << "Placa: " << veiculos[i].placa
                  << " | Modelo: " << veiculos[i].modelo
                  << " | Local: " << veiculos[i].localAtual
                  << " | Status: " << (veiculos[i].status == DISPONIVEL ? "Disponivel" : "Ocupado")
                  << "\n";
    }
}
