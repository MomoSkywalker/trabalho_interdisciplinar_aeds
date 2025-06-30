#include <iostream>
#include <cmath>
#include <cfloat>
#include <cstring>
#include "slem.h"
#include "rota.h"
#include "locais.h"
#include "veiculos.h"

double calcularDistancia(const Local &l1, const Local &l2) {
    return sqrt(pow(l2.coordX - l1.coordX, 2) + pow(l2.coordY - l1.coordY, 2));
}

void calcularExibirRota(Pedido &pedido, Veiculo veiculos[], int numVeiculos, const Local locais[], int numLocais) {
    int idxOrigem = buscarLocalPorNome(pedido.localOrigem, locais, numLocais);
    int idxDestino = buscarLocalPorNome(pedido.localDestino, locais, numLocais);

    if (idxOrigem == -1 || idxDestino == -1) {
        std::cout << "Erro: Local de origem ou destino nao encontrado.\n";
        return;
    }

    double menorDistancia = DBL_MAX;
    int idxVeiculo = -1;

    for (int i = 0; i < numVeiculos; ++i) {
        if (veiculos[i].status == DISPONIVEL) {
            int idxLocalVeiculo = buscarLocalPorNome(veiculos[i].localAtual, locais, numLocais);
            if (idxLocalVeiculo != -1) {
                double dist = calcularDistancia(locais[idxOrigem], locais[idxLocalVeiculo]);
                if (dist < menorDistancia) {
                    menorDistancia = dist;
                    idxVeiculo = i;
                }
            }
        }
    }

    if (idxVeiculo == -1) {
        std::cout << "Nao ha veiculos disponiveis.\n";
        return;
    }

    // A distância total vai ser a soma de dois pedaços:
    // 1. Do veículo até o ponto de coleta (a `menorDistancia` que já achamos).
    // 2. Do ponto de coleta até o ponto de entrega.
    double distTotal = menorDistancia + calcularDistancia(locais[idxOrigem], locais[idxDestino]);

    // Agora é só mostrar o resumo de tudo.
    std::cout << "\n--- Rota de Entrega ---\n";
    std::cout << "Pedido ID: " << pedido.id << "\n";
    std::cout << "Veiculo: " << veiculos[idxVeiculo].placa << "\n";
    std::cout << "Rota: " << veiculos[idxVeiculo].localAtual << " -> "
              << pedido.localOrigem << " -> " << pedido.localDestino << "\n";
    std::cout << "Distancia total: " << distTotal << "\n";

    // --- Simulação da Entrega ---
    // Aqui a gente finge que a entrega aconteceu.
    veiculos[idxVeiculo].status = OCUPADO; // Veículo sai pra entrega
    // Neste sistema simples, a entrega é instantânea.
    veiculos[idxVeiculo].status = DISPONIVEL; // Já ficou disponível de novo.
    
    // E o veículo agora está no seu destino final.
    strcpy(veiculos[idxVeiculo].localAtual, pedido.localDestino);
    std::cout << "Entrega finalizada. Veiculo agora esta em: " << veiculos[idxVeiculo].localAtual << "\n";
}
