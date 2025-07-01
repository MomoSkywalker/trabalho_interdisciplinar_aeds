#ifndef PEDIDOS_H
#define PEDIDOS_H

#include "slem.h"

int buscarPedidoPorId(int id, const Pedido pedidos[], int numPedidos);
void cadastrarPedido(Pedido pedidos[], int &numPedidos, const Local locais[], int numLocais);
void listarPedidos(const Pedido pedidos[], int numPedidos);
void excluirPedido(Pedido pedidos[], int &numPedidos);

#endif