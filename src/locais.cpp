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
