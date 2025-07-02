#include <cstdio>
#include <cstring>
#include "minunit.h"
#include "../src/veiculos.h"

int tests_run = 0;

char* test_buscarVeiculoPorPlaca() {
    Veiculo veiculos[2] = {
        {"ABC1234", "Modelo A", DISPONIVEL, "Centro"},
        {"XYZ9876", "Modelo B", OCUPADO, "Bairro"}
    };
    mu_assert("Erro: ABC1234 deve estar na posicao 0", buscarVeiculoPorPlaca("ABC1234", veiculos, 2) == 0);
    mu_assert("Erro: XYZ9876 deve estar na posicao 1", buscarVeiculoPorPlaca("XYZ9876", veiculos, 2) == 1);
    mu_assert("Erro: Placa inexistente deve retornar -1", buscarVeiculoPorPlaca("ZZZ9999", veiculos, 2) == -1);
    return 0;
}

char* all_tests() {
    mu_run_test(test_buscarVeiculoPorPlaca);
    return 0;
}

int main() {
    char* result = all_tests();
    if (result != 0) {
        printf("FALHOU: %s\n", result);
    } else {
        printf("TODOS OS TESTES PASSARAM\n");
    }
    printf("Testes executados: %d\n", tests_run);
    return result != 0;
}
