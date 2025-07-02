#ifndef SLEM_H
#define SLEM_H

// Constantes globais para o projeto
const int MAX_ENTIDADES = 100;
const int MAX_NOME = 50;

// Enum para o status do veículo
enum StatusVeiculo { DISPONIVEL, OCUPADO };

// Definição da struct para um Local
struct Local {
    char nome[MAX_NOME];
    int coordX;
    int coordY;
};

// Definição da struct para um Veículo
struct Veiculo {
    char placa[10];
    char modelo[MAX_NOME];
    StatusVeiculo status;
    char localAtual[MAX_NOME];
};

// Definição da struct para um Pedido
struct Pedido {
    int id;
    char localOrigem[MAX_NOME];
    char localDestino[MAX_NOME];
    float peso;
};

#endif
