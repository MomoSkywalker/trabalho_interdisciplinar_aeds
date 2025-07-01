#include "minunit.h"
#include "../src/locais.h"
#include <string.h>

int tests_run = 0;

// Teste da função buscarLocalPorNome
char *test_buscarLocalPorNome() {
    Local locais[2] = {
        {"Centro", 0, 0},
        {"Bairro", 1, 1}
    };

    mu_assert("Erro: Centro deve estar na posição 0", buscarLocalPorNome("Centro", locais, 2) == 0);
    mu_assert("Erro: Bairro deve estar na posição 1", buscarLocalPorNome("Bairro", locais, 2) == 1);
    mu_assert("Erro: Inexistente deve retornar -1", buscarLocalPorNome("Inexistente", locais, 2) == -1);

    return 0;
}

// Executa todos os testes
char *all_tests() {
    mu_run_test(test_buscarLocalPorNome);
    return 0;
}

// Ponto de entrada do programa de testes
int main() {
    char *result = all_tests();

    if (result != 0) {
        printf("FALHOU: %s\n", result);
    } else {
        printf("TODOS OS TESTES PASSARAM\n");
    }

    printf("Testes executados: %d\n", tests_run);
    return result != 0;
}
