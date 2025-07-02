#include <iostream>
#include <fstream>
#include "arquivos.h"

void salvarDados(const Local locais[], int numLocais, const Veiculo veiculos[], int numVeiculos, const Pedido pedidos[], int numPedidos) {
    std::ofstream arqLoc("dados_bin/locais.dat", std::ios::binary);
    if (arqLoc.is_open()) {
        arqLoc.write((char*)&numLocais, sizeof(int));
        arqLoc.write((char*)locais, sizeof(Local) * numLocais);
        arqLoc.close();
    }

    std::ofstream arqVei("dados_bin/veiculos.dat", std::ios::binary);
    if (arqVei.is_open()) {
        arqVei.write((char*)&numVeiculos, sizeof(int));
        arqVei.write((char*)veiculos, sizeof(Veiculo) * numVeiculos);
        arqVei.close();
    }

    std::ofstream arqPed("dados_bin/pedidos.dat", std::ios::binary);
    if (arqPed.is_open()) {
        arqPed.write((char*)&numPedidos, sizeof(int));
        arqPed.write((char*)pedidos, sizeof(Pedido) * numPedidos);
        arqPed.close();
    }

    std::cout << "\nDados salvos com sucesso!\n";
}

void restaurarDados(Local locais[], int &numLocais, Veiculo veiculos[], int &numVeiculos, Pedido pedidos[], int &numPedidos) {
    std::ifstream arqLoc("dados_bin/locais.dat", std::ios::binary);
    if (arqLoc.is_open()) {
        arqLoc.read((char*)&numLocais, sizeof(int));
        arqLoc.read((char*)locais, sizeof(Local) * numLocais);
        arqLoc.close();
    }

    std::ifstream arqVei("dados_bin/veiculos.dat", std::ios::binary);
    if (arqVei.is_open()) {
        arqVei.read((char*)&numVeiculos, sizeof(int));
        arqVei.read((char*)veiculos, sizeof(Veiculo) * numVeiculos);
        arqVei.close();
    }

    std::ifstream arqPed("dados_bin/pedidos.dat", std::ios::binary);
    if (arqPed.is_open()) {
        arqPed.read((char*)&numPedidos, sizeof(int));
        arqPed.read((char*)pedidos, sizeof(Pedido) * numPedidos);
        arqPed.close();
    }

    std::cout << "\nDados restaurados com sucesso!\n";
}
