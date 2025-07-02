#ifndef VEICULOS_H
#define VEICULOS_H

#include "slem.h"

// Declarações das funções que estão em veiculos.cpp
void cadastrarVeiculo(Veiculo veiculos[], int &numVeiculos, const Local locais[], int numLocais);
void listarVeiculos(const Veiculo veiculos[], int numVeiculos);
void atualizarVeiculo(Veiculo veiculos[], int numVeiculos, const Local locais[], int numLocais);
void excluirVeiculo(Veiculo veiculos[], int &numVeiculos);
int buscarVeiculoPorPlaca(const char* placa, const Veiculo veiculos[], int numVeiculos);

#endif
