#include <cstdio>
#include <cstring>
#include "minunit.h"
#include "../src/locais.h"

int tests_run = 0;

char* test_buscarLocalPorNome() {
    Local locais[2];
    strcpy(locais[0].nome, "Centro");
    locais[0].coordX = 0;
    locais[0].coordY = 0;
    
    strcpy(locais[1].nome, "Bairro");
    locais[1].coordX = 1;
    locais[1].coordY = 1;

    mu_assert("Erro: Centro deve estar na posicao 0", buscarLocalPorNome("Centro", locais, 2) == 0);
    mu_assert("Erro: Bairro deve estar na posicao 1", buscarLocalPorNome("Bairro", locais, 2) == 1);
    mu_assert("Erro: Inexistente deve retornar -1", buscarLocalPorNome("Inexistente", locais, 2) == -1);
    return 0;
}

char* all_tests() {
    mu_run_test(test_buscarLocalPorNome);
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
