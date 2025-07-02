#include <iostream>
#include <cstring>
#include "locais.h"

int buscarLocalPorNome(const char* nome, const Local locais[], int numLocais) {
    for (int i = 0; i < numLocais; ++i) {
        if (strcmp(locais[i].nome, nome) == 0) return i;
    }
    return -1;
}

void cadastrarLocal(Local locais[], int &numLocais) {
    if (numLocais >= MAX_ENTIDADES) {
        std::cout << "\nErro: limite maximo de locais atingido.\n";
        return;
    }
    Local novoLocal;
    std::cout << "Nome do local: ";
    std::cin.getline(novoLocal.nome, MAX_NOME);
    if (buscarLocalPorNome(novoLocal.nome, locais, numLocais) != -1) {
        std::cout << "\nErro: local ja existente.\n";
        return;
    }
    std::cout << "Coordenada X: ";
    std::cin >> novoLocal.coordX;
    std::cout << "Coordenada Y: ";
    std::cin >> novoLocal.coordY;
    std::cin.ignore();
    locais[numLocais++] = novoLocal;
    std::cout << "\nLocal cadastrado com sucesso.\n";
}

void listarLocais(const Local locais[], int numLocais) {
    if (numLocais == 0) {
        std::cout << "Nenhum local cadastrado.\n";
        return;
    }
    for (int i = 0; i < numLocais; ++i) {
        std::cout << "Nome: " << locais[i].nome << " | Coordenadas: (" << locais[i].coordX << ", " << locais[i].coordY << ")\n";
    }
}

void atualizarLocal(Local locais[], int numLocais) {
    char nomeBusca[MAX_NOME];
    std::cout << "Digite o nome do local: ";
    std::cin.getline(nomeBusca, MAX_NOME);
    int indice = buscarLocalPorNome(nomeBusca, locais, numLocais);
    if (indice == -1) {
        std::cout << "Local nao encontrado.\n";
        return;
    }
    std::cout << "Nova coordenada X: ";
    std::cin >> locais[indice].coordX;
    std::cout << "Nova coordenada Y: ";
    std::cin >> locais[indice].coordY;
    std::cin.ignore();
    std::cout << "Local atualizado com sucesso.\n";
}

void excluirLocal(Local locais[], int &numLocais) {
    char nomeBusca[MAX_NOME];
    std::cout << "Digite o nome do local a excluir: ";
    std::cin.getline(nomeBusca, MAX_NOME);
    int indice = buscarLocalPorNome(nomeBusca, locais, numLocais);
    if (indice == -1) {
        std::cout << "Local nao encontrado.\n";
        return;
    }
    for (int i = indice; i < numLocais - 1; ++i) {
        locais[i] = locais[i + 1];
    }
    numLocais--;
    std::cout << "Local excluido.\n";
}
