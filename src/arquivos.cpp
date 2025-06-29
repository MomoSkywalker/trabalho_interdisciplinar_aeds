#include <iostream>
#include <fstream>   // Necessario aqui pra poder mexer com arquivos.
#include "slem.h"
#include "arquivos.h"

/**
 * Salva os dados de locais em um arquivo binário.
 * A ideia é não perder os locais que já foram cadastrados.
 */
void salvarDados(const Local locais[], int numLocais, const Veiculo veiculos[], int numVeiculos, const Pedido pedidos[], int numPedidos) {
    // Tenta abrir (ou criar) o arquivo para salvar os locais.
    // std::ios::binary significa que vamos escrever em binário, que é mais rápido.
    std::ofstream arqLoc("dados_bin/locais.dat", std::ios::binary);

    // Se o arquivo abriu direitinho...
    if (arqLoc.is_open()) {
        // ...primeiro, a gente salva quantos locais existem. Facilita na hora de ler de volta.
        arqLoc.write((char*)&numLocais, sizeof(int));
        // Agora, salva o array inteiro de locais de uma vez.
        arqLoc.write((char*)locais, sizeof(Local) * numLocais);
        arqLoc.close(); // Bom fechar o arquivo depois de usar.
    }

    std::cout << "\nDados de locais salvos!\n";
}
