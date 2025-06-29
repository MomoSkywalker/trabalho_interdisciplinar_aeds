#include <iostream> // Biblioteca para entrada e saída de dados (cout, cin)
#include <cstring>  // Biblioteca para manipulação de strings no estilo C (ex: strcpy)

// --- Arquivos de cabeçalho do projeto (ainda a serem totalmente integrados) ---
#include "slem.h"
#include "locais.h"
#include "veiculos.h"
#include "pedidos.h"
#include "rota.h"
#include "arquivos.h"

/**
 * @brief Exibe o menu principal com todas as opções do sistema.
 * * Limpa a tela para uma exibição mais limpa no terminal.
 */
void exibirMenuPrincipal() {
    // Comando para limpar o terminal, compatível com Linux ("clear") e Windows ("cls")
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

/**
 * @brief Exibe um sub-menu genérico para as operações de CRUD.
 * * @param titulo O título do menu (ex: "Locais", "Veiculos").
 */
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
    // --- Declaração dos arrays que armazenarão os dados em memória ---
    Local locais[MAX_ENTIDADES];
    Veiculo veiculos[MAX_ENTIDADES];
    Pedido pedidos[MAX_ENTIDADES];
    // Contadores para saber quantos itens de cada tipo temos cadastrados
    int numLocais = 0, numVeiculos = 0, numPedidos = 0;
    
    int opcao; // Variável para armazenar a escolha do usuário no menu

    // O loop principal do programa. Continua executando até que o usuário escolha a opção 0 para sair.
    do {
        exibirMenuPrincipal();
        std::cin >> opcao;
        // Limpa o buffer de entrada. Essencial após ler um número para ler strings ou caracteres depois.
        std::cin.ignore(); 

        // Estrutura que direciona o fluxo do programa com base na escolha do usuário
        switch (opcao) {
            case 1: 
                // Gerenciamento de Locais (a ser implementado)
                break;
            case 2: 
                // Gerenciamento de Veículos (a ser implementado)
                break;
            case 3:
                // Gerenciamento de Pedidos (a ser implementado)
                break;
            case 4: {
                // Cálculo de Rota (a ser implementado)
                break;
            }
            case 5:
                // Backup (a ser implementado)
                break;
            case 6:
                // Restauração (a ser implementado)
                break;
            case 0:
                // O usuário escolheu sair
                std::cout << "\nSaindo do sistema...\n";
                break;
            default:
                // Tratamento para qualquer outra entrada numérica
                std::cout << "\nOpcao invalida. Tente novamente.\n";
        }

        // Pausa o programa e espera o usuário pressionar ENTER para continuar.
        // Isso evita que a tela seja limpa imediatamente, permitindo que o usuário veja as mensagens.
        if (opcao != 0) { // Não pausa se o programa estiver saindo
             std::cout << "\nPressione ENTER para continuar...";
             std::cin.get();
        }

    } while (opcao != 0);

    return 0; // Indica que o programa terminou com sucesso
}