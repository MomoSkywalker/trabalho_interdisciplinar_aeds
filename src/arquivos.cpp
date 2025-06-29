#include <iostream>
#include <fstream>
#include "slem.h"
#include "arquivos.h"

// Função salvarDados (do commit anterior)
void salvarDados(const Local locais[], int numLocais, const Veiculo veiculos[], int numVeiculos, const Pedido pedidos[], int numPedidos) {
    std::ofstream arqLoc("dados_bin/locais.dat", std::ios::binary);
    if (arqLoc.is_open()) { arqLoc.write((char*)&numLocais, sizeof(int)); arqLoc.write((char*)locais, sizeof(Local) * numLocais); arqLoc.close(); }
    std::ofstream arqVei("dados_bin/veiculos.dat", std::ios::binary);
    if (arqVei.is_open()) { arqVei.write((char*)&numVeiculos, sizeof(int)); arqVei.write((char*)veiculos, sizeof(Veiculo) * numVeiculos); arqVei.close(); }
    std::ofstream arqPed("dados_bin/pedidos.dat", std::ios::binary);
    if (arqPed.is_open()) { arqPed.write((char*)&numPedidos, sizeof(int)); arqPed.write((char*)pedidos, sizeof(Pedido) * numPedidos); arqPed.close(); }
    std::cout << "\nDados salvos com sucesso!\n";
}


/**
 * Carrega os dados dos arquivos de volta para o programa.
 * É o que permite que os dados não se percam ao fechar o sistema.
 */
void restaurarDados(Local locais[], int &numLocais, Veiculo veiculos[], int &numVeiculos, Pedido pedidos[], int &numPedidos) {
    // Abre o arquivo de locais para leitura.
    std::ifstream arqLoc("dados_bin/locais.dat", std::ios::binary);
    // Se o arquivo existir...
    if (arqLoc.is_open()) {
        // ...primeiro a gente lê quantos locais tem...
        arqLoc.read((char*)&numLocais, sizeof(int));
        // ...e depois lê os dados dos locais para dentro do array.
        arqLoc.read((char*)locais, sizeof(Local) * numLocais);
        arqLoc.close();
    }

    // Mesma coisa para os veículos.
    std::ifstream arqVei("dados_bin/veiculos.dat", std::ios::binary);
    if (arqVei.is_open()) {
        arqVei.read((char*)&numVeiculos, sizeof(int));
        arqVei.read((char*)veiculos, sizeof(Veiculo) * numVeiculos);
        arqVei.close();
    }

    // E finalmente para os pedidos.
    std::ifstream arqPed("dados_bin/pedidos.dat", std::ios::binary);
    if (arqPed.is_open()) {
        arqPed.read((char*)&numPedidos, sizeof(int));
        arqPed.read((char*)pedidos, sizeof(Pedido) * numPedidos);
        arqPed.close();
    }

    std::cout << "\nDados restaurados com sucesso!\n";
}
