#include <iostream>
#include <cstring>
#include "slem.h"
#include "locais.h"
#include "veiculos.h"
#include "pedidos.h"
#include "rota.h"
#include "arquivos.h"

void exibirMenuPrincipal() {
    system("clear || cls");
    std::cout << "===== Sistema de Logistica de Entrega de Mercadorias (SLEM) =====\n";
    std::cout << "1. Gerenciar Locais\n";
    std::cout << "2. Gerenciar Veiculos\n";
    std::cout << "3. Gerenciar Pedidos\n";
    std::cout << "4. Calcular e Exibir Rota de Entrega\n";
    std::cout << "5. Backup de Dados\n";
    std::cout << "6. Restaurar Dados\n";
    std::cout << "0. Sair\n";
    std::cout << "================================================================\n";
    std::cout << "Escolha uma opcao: ";
}

void exibirSubMenu(const char* titulo) {
    system("clear || cls");
    std::cout << "===== Gerenciar " << titulo << " =====\n";
    std::cout << "1. Cadastrar\n";
    std::cout << "2. Listar\n";
    std::cout << "3. Atualizar\n";
    std::cout << "4. Excluir\n";
    std::cout << "0. Voltar ao Menu Principal\n";
    std::cout << "=============================\n";
    std::cout << "Escolha uma opcao: ";
}

int main() {
    Local locais[MAX_ENTIDADES];
    Veiculo veiculos[MAX_ENTIDADES];
    Pedido pedidos[MAX_ENTIDADES];
    int numLocais = 0, numVeiculos = 0, numPedidos = 0;
    int opcao;

    do {
        exibirMenuPrincipal();
        std::cin >> opcao;
        std::cin.ignore();

        switch (opcao) {
            case 1: {
                int subOpcao;
                do {
                    exibirSubMenu("Locais");
                    std::cin >> subOpcao;
                    std::cin.ignore();
                    switch (subOpcao) {
                        case 1: cadastrarLocal(locais, numLocais); break;
                        case 2: listarLocais(locais, numLocais); break;
                        case 3: atualizarLocal(locais, numLocais); break;
                        case 4: excluirLocal(locais, numLocais); break;
                        case 0: break;
                        default: std::cout << "\nOpcao invalida.\n";
                    }
                } while (subOpcao != 0);
                break;
            }
            case 2: {
                int subOpcao;
                do {
                    exibirSubMenu("Veiculos");
                    std::cin >> subOpcao;
                    std::cin.ignore();
                    switch (subOpcao) {
                        case 1: cadastrarVeiculo(veiculos, numVeiculos, locais, numLocais); break;
                        case 2: listarVeiculos(veiculos, numVeiculos); break;
                        case 3: atualizarVeiculo(veiculos, numVeiculos, locais, numLocais); break;
                        case 4: excluirVeiculo(veiculos, numVeiculos); break;
                        case 0: break;
                        default: std::cout << "\nOpcao invalida.\n";
                    }
                } while (subOpcao != 0);
                break;
            }
            case 3: {
                int subOpcao;
                do {
                    exibirSubMenu("Pedidos");
                    std::cin >> subOpcao;
                    std::cin.ignore();
                    switch (subOpcao) {
                        case 1: cadastrarPedido(pedidos, numPedidos, locais, numLocais); break;
                        case 2: listarPedidos(pedidos, numPedidos); break;
                        case 3: std::cout << "\nOpcao de atualizar pedido nao disponivel.\n"; break;
                        case 4: excluirPedido(pedidos, numPedidos); break;
                        case 0: break;
                        default: std::cout << "\nOpcao invalida.\n";
                    }
                } while (subOpcao != 0);
                break;
            }
            // --- Bloco para Cálculo e Exibição da Rota ---
            case 4: {
                // Validação: precisamos de pedidos para calcular uma rota.
                if (numPedidos == 0) {
                    std::cout << "\nNenhum pedido para calcular rota. Cadastre um pedido primeiro.\n";
                    break;
                }
                // Validação: precisamos de veículos para fazer a entrega.
                if (numVeiculos == 0) {
                    std::cout << "\nNenhum veiculo disponivel. Cadastre um veiculo primeiro.\n";
                    break;
                }

                int idPedido;
                std::cout << "\nDigite o ID do pedido para calcular a rota: ";
                std::cin >> idPedido;
                std::cin.ignore();

                // Busca o pedido pelo ID fornecido para garantir que ele existe.
                int indicePedido = buscarPedidoPorId(idPedido, pedidos, numPedidos);
                
                if (indicePedido != -1) {
                    // Se o pedido foi encontrado, chama a função principal de logística.
                    calcularExibirRota(pedidos[indicePedido], veiculos, numVeiculos, locais, numLocais);
                } else {
                    // Informa ao usuário se o ID do pedido não foi encontrado.
                    std::cout << "\nPedido com ID " << idPedido << " nao encontrado.\n";
                }
                break;
            }
            // --- Bloco para Backup e Restauração de Dados ---
            case 5:
                // Chama a função para salvar todos os dados dos arrays em arquivos.
                salvarDados(locais, numLocais, veiculos, numVeiculos, pedidos, numPedidos);
                break;
            case 6:
                // Chama a função para ler os dados dos arquivos e preencher os arrays.
                restaurarDados(locais, numLocais, veiculos, numVeiculos, pedidos, numPedidos);
                break;
            case 0:
                std::cout << "\nSaindo do sistema...\n";
                break;
            default:
                std::cout << "\nOpcao invalida. Tente novamente.\n";
        }

        if (opcao != 0) {
            std::cout << "\nPressione ENTER para continuar...";
            // std::cin.get() aguarda o usuário pressionar a tecla Enter.
            std::cin.get();
        }
    } while (opcao != 0);

    return 0;
}