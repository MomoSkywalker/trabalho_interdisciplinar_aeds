#include <iostream>
#include <cmath>     // Para usar as funções de matemática como sqrt e pow.
#include <cfloat>    // Para pegar o maior valor possível de um double (DBL_MAX).
#include <cstring>   // Para copiar strings com strcpy.
#include "slem.h"
#include "rota.h"
#include "locais.h"
#include "veiculos.h"

/**
 * Calcula a distância em linha reta entre dois locais.
 * Usa o Teorema de Pitágoras, basicamente.
 */
double calcularDistancia(const Local &l1, const Local &l2) {
    return sqrt(pow(l2.coordX - l1.coordX, 2) + pow(l2.coordY - l1.coordY, 2));
}

/**
 * Prepara para calcular e mostrar a rota de um pedido.
 * (Ainda em desenvolvimento)
 */
void calcularExibirRota(Pedido &pedido, Veiculo veiculos[], int numVeiculos, const Local locais[], int numLocais) {
    // Acha os índices dos locais de origem e destino na nossa lista de locais.
    int idxOrigem = buscarLocalPorNome(pedido.localOrigem, locais, numLocais);
    int idxDestino = buscarLocalPorNome(pedido.localDestino, locais, numLocais);

    // Se não achar um dos locais, não tem como continuar.
    if (idxOrigem == -1 || idxDestino == -1) {
        std::cout << "Erro: Local de origem ou destino nao encontrado.\n";
        return;
    }

    // A lógica para achar o melhor veículo e calcular a rota vem aqui...
    std::cout << "\nCalculando rota (logica a ser implementada)...\n";
}
