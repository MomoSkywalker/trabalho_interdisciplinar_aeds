#include <iostream>
#include <cstring>
#include "slem.h"
#include "pedidos.h"
#include "locais.h"

// Busca um pedido pelo ID no array de pedidos
// Retorna o índice se encontrado, ou -1 se não existir
int buscarPedidoPorId(int id, const Pedido pedidos[], int numPedidos) {
    for (int i = 0; i < numPedidos; ++i) {
        if (pedidos[i].id == id) return i;
    }
    return -1;
}

// Lista todos os pedidos cadastrados
void listarPedidos(const Pedido pedidos[], int numPedidos) {
    if (numPedidos == 0) {
        std::cout << "Nenhum pedido cadastrado.\n";
        return;
    }
    for (int i = 0; i < numPedidos; ++i) {
        std::cout << "ID: " << pedidos[i].id
                  << " | Origem: " << pedidos[i].localOrigem
                  << " | Destino: " << pedidos[i].localDestino
                  << " | Peso: " << pedidos[i].peso << "kg\n";
    }
}
