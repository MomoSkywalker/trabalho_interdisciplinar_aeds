#ifndef ROTA_H
#define ROTA_H

#include "slem.h"

// Declarações das funções que estão em rota.cpp
double calcularDistancia(const Local &l1, const Local &l2);
void calcularExibirRota(Pedido &pedido, Veiculo veiculos[], int numVeiculos, const Local locais[], int numLocais);

#endif
