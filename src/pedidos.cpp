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
// Cadastra um novo pedido, verificando se os locais informados existem
void cadastrarPedido(Pedido pedidos[], int &numPedidos, const Local locais[], int numLocais) {
    if (numPedidos >= MAX_ENTIDADES) {
        std::cout << "\nErro: Limite maximo de pedidos atingido.\n";
        return;
    }

    if (numLocais < 2) {
        std::cout << "\nErro: E necessario ter pelo menos 2 locais cadastrados.\n";
        return;
    }

    Pedido novoPedido;
    novoPedido.id = numPedidos + 1;

    std::cout << "--- Cadastro de Novo Pedido ---\n";

    std::cout << "Local de Origem: ";
    std::cin.getline(novoPedido.localOrigem, MAX_NOME);

    if (buscarLocalPorNome(novoPedido.localOrigem, locais, numLocais) == -1) {
        std::cout << "Local de origem nao encontrado.\n";
        return;
    }

    std::cout << "Local de Destino: ";
    std::cin.getline(novoPedido.localDestino, MAX_NOME);

    if (buscarLocalPorNome(novoPedido.localDestino, locais, numLocais) == -1) {
        std::cout << "Local de destino nao encontrado.\n";
        return;
    }

    std::cout << "Peso do pedido (kg): ";
    std::cin >> novoPedido.peso;
    std::cin.ignore(); // Limpa o buffer do cin para evitar bugs em próximos inputs

    // Adiciona o pedido no vetor e incrementa o contador
    pedidos[numPedidos++] = novoPedido;
    std::cout << "Pedido cadastrado com sucesso!\n";
}
// Exclui um pedido com base no ID informado
void excluirPedido(Pedido pedidos[], int &numPedidos) {
    int id;
    std::cout << "Digite o ID do pedido a excluir: ";
    std::cin >> id;
    std::cin.ignore(); // Limpa o buffer após entrada numérica

    int idx = buscarPedidoPorId(id, pedidos, numPedidos);
    if (idx == -1) {
        std::cout << "Pedido nao encontrado.\n";
        return;
    }

    // Move os pedidos seguintes uma posição para trás
    for (int i = idx; i < numPedidos - 1; ++i) {
        pedidos[i] = pedidos[i + 1];
    }

    numPedidos--;
    std::cout << "Pedido excluido.\n";
}