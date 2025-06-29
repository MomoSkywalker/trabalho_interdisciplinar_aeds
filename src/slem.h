#ifndef SLEM_H
#define SLEM_H

const int MAX_ENTIDADES = 100;
const int MAX_NOME = 50;

enum StatusVeiculo { DISPONIVEL, OCUPADO };

struct Local {
    char nome[MAX_NOME];
    int coordX;
    int coordY;
};

struct Veiculo {
    char placa[10];
    char modelo[MAX_NOME];
    StatusVeiculo status;
    char localAtual[MAX_NOME];
};

struct Pedido {
    int id;
    char localOrigem[MAX_NOME];
    char localDestino[MAX_NOME];
    float peso;
};

// Funções de menu
void exibirMenuPrincipal();
void exibirSubMenu(const char* titulo);

#endif