#include <iostream>
#include <cstring>
#include "veiculos.h"
#include "locais.h"

int buscarVeiculoPorPlaca(const char* placa, const Veiculo veiculos[], int numVeiculos) {
    for (int i = 0; i < numVeiculos; ++i) {
        if (strcmp(veiculos[i].placa, placa) == 0) return i;
    }
    return -1;
}

void listarVeiculos(const Veiculo veiculos[], int numVeiculos) {
    if (numVeiculos == 0) {
        std::cout << "Nenhum veiculo cadastrado.\n";
        return;
    }
    for (int i = 0; i < numVeiculos; ++i) {
        std::cout << "Placa: " << veiculos[i].placa
                  << " | Modelo: " << veiculos[i].modelo
                  << " | Local: " << veiculos[i].localAtual
                  << " | Status: " << (veiculos[i].status == DISPONIVEL ? "Disponivel" : "Ocupado")
                  << "\n";
    }
}

void cadastrarVeiculo(Veiculo veiculos[], int &numVeiculos, const Local locais[], int numLocais) {
    if (numVeiculos >= MAX_ENTIDADES) {
        std::cout << "\nLimite de veiculos atingido.\n";
        return;
    }
    Veiculo novo;
    std::cout << "Placa: ";
    std::cin.getline(novo.placa, 10);
    if (buscarVeiculoPorPlaca(novo.placa, veiculos, numVeiculos) != -1) {
        std::cout << "Placa ja cadastrada.\n";
        return;
    }
    std::cout << "Modelo: ";
    std::cin.getline(novo.modelo, MAX_NOME);
    std::cout << "Local atual: ";
    std::cin.getline(novo.localAtual, MAX_NOME);
    novo.status = DISPONIVEL;
    veiculos[numVeiculos++] = novo;
    std::cout << "Veiculo cadastrado.\n";
}

void atualizarVeiculo(Veiculo veiculos[], int numVeiculos, const Local locais[], int numLocais) {
    char placa[10];
    std::cout << "Placa do veiculo: ";
    std::cin.getline(placa, 10);
    int idx = buscarVeiculoPorPlaca(placa, veiculos, numVeiculos);
    if (idx == -1) {
        std::cout << "Veiculo nao encontrado.\n";
        return;
    }
    std::cout << "Novo modelo: ";
    std::cin.getline(veiculos[idx].modelo, MAX_NOME);
    std::cout << "Veiculo atualizado.\n";
}

void excluirVeiculo(Veiculo veiculos[], int &numVeiculos) {
    char placa[10];
    std::cout << "Placa do veiculo: ";
    std::cin.getline(placa, 10);
    int idx = buscarVeiculoPorPlaca(placa, veiculos, numVeiculos);
    if (idx == -1) {
        std::cout << "Nao encontrado.\n";
        return;
    }
    for (int i = idx; i < numVeiculos - 1; ++i)
        veiculos[i] = veiculos[i + 1];
    numVeiculos--;
    std::cout << "Excluido com sucesso.\n";
}
