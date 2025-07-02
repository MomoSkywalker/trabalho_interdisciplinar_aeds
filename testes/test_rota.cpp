#include <cstdio>
#include "minunit.h"
#include "../src/rota.h"

int tests_run = 0;

char* test_calcularDistancia() {
    Local l1 = {"A", 0, 0};
    Local l2 = {"B", 3, 4};
    double dist = calcularDistancia(l1, l2);
    mu_assert("Erro: distancia entre (0,0) e (3,4) deve ser 5.0", (int)(dist * 10) == 50);
    return 0;
}

char* all_tests() {
    mu_run_test(test_calcularDistancia);
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
