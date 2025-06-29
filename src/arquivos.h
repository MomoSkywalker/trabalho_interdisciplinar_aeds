#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "slem.h"

void salvarDados(const Local locais[], int numLocais, const Veiculo veiculos[], int numVeiculos, const Pedido pedidos[], int numPedidos);
void restaurarDados(Local locais[], int &numLocais, Veiculo veiculos[], int &numVeiculos, Pedido pedidos[], int &numPedidos);

#endif