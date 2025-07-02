#include <iostream>
#include <cmath>
#include <cfloat>
#include <cstring>
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

    double distTotal = menorDistancia + calcularDistancia(locais[idxOrigem], locais[idxDestino]);

    std::cout << "\n--- Rota de Entrega ---\n";
    std::cout << "Pedido ID: " << pedido.id << "\n";
    std::cout << "Veiculo: " << veiculos[idxVeiculo].placa << "\n";
    std::cout << "Rota: " << veiculos[idxVeiculo].localAtual << " -> "
              << pedido.localOrigem << " -> " << pedido.localDestino << "\n";
    std::cout << "Distancia total: " << distTotal << "\n";

    veiculos[idxVeiculo].status = OCUPADO;
    // Em um sistema real, o status só voltaria para DISPONIVEL após a entrega.
    // Para simplificar, vamos simular que a entrega é feita e o veículo já volta a ficar disponível.
    strcpy(veiculos[idxVeiculo].localAtual, pedido.localDestino);
    veiculos[idxVeiculo].status = DISPONIVEL;
    std::cout << "Entrega finalizada. Veiculo agora esta em: " << veiculos[idxVeiculo].localAtual << "\n";
}
