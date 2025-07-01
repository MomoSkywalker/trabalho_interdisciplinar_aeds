#include <iostream>
#include "slem.h"
#include "locais.h"

// compara duas strings caractere a caractere sem uso de bibliotecas adicionais
int comparaString(const char* a, const char* b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return 1;
        i++;
    }
    if (a[i] != b[i]) return 1;
    return 0;
}

// busca o indice de um local pelo nome no vetor locais
int buscarLocalPorNome(const char* nome, const Local locais[], int numLocais) {
    for (int i = 0; i < numLocais; ++i) {
        if (comparaString(locais[i].nome, nome) == 0) return i;
    }
    return -1;
}

// cadastra um novo local caso ainda nao exista e atualiza o vetor
void cadastrarLocal(Local locais[], int &numLocais) {
    if (numLocais >= MAX_ENTIDADES) {
        std::cout << "\nerro limite maximo de locais atingido\n";
        return;
    }
    Local novoLocal;
    std::cout << "nome do local ";
    std::cin.getline(novoLocal.nome, MAX_NOME);
    if (buscarLocalPorNome(novoLocal.nome, locais, numLocais) != -1) {
        std::cout << "\nerro local ja existente\n";
        return;
    }
    std::cout << "coordenada x ";
    std::cin >> novoLocal.coordX;
    std::cout << "coordenada y ";
    std::cin >> novoLocal.coordY;
    std::cin.ignore();
    locais[numLocais++] = novoLocal;
    std::cout << "\nlocal cadastrado com sucesso\n";
}
void listarLocais(const Local locais[], int numLocais) {
    if (numLocais == 0) {
        std::cout << "nenhum local cadastrado\n";
        return;
    }
    for (int i = 0; i < numLocais; ++i) {
        std::cout << "nome " << locais[i].nome << " coordenadas " << locais[i].coordX << " " << locais[i].coordY << "\n";
    }
}

// atualiza as coordenadas de um local ja cadastrado
void atualizarLocal(Local locais[], int numLocais) {
    char nomeBusca[MAX_NOME];
    std::cout << "digite o nome do local ";
    std::cin.getline(nomeBusca, MAX_NOME);
    int indice = buscarLocalPorNome(nomeBusca, locais, numLocais);
    if (indice == -1) {
        std::cout << "local nao encontrado\n";
        return;
    }
    std::cout << "nova coordenada x ";
    std::cin >> locais[indice].coordX;
    std::cout << "nova coordenada y ";
    std::cin >> locais[indice].coordY;
    std::cin.ignore();
    std::cout << "local atualizado com sucesso\n";
}

// exclui um local a partir do nome informado pelo usuario
void excluirLocal(Local locais[], int &numLocais) {
    char nomeBusca[MAX_NOME];
    std::cout << "digite o nome do local a excluir ";
    std::cin.getline(nomeBusca, MAX_NOME);
    int indice = buscarLocalPorNome(nomeBusca, locais, numLocais);
    if (indice == -1) {
        std::cout << "local nao encontrado\n";
        return;
    }
    for (int i = indice; i < numLocais - 1; ++i) {
        locais[i] = locais[i + 1];
    }
    numLocais--;
    std::cout << "local excluido\n";
}
