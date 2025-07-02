#include "minunit.h"
#include "../src/rotas.h"

int tests_run = 0;

// Testa se a distância entre (0,0) e (3,4) é 5.0
char *test_calcularDistancia() {
    Local l1 = {"A", 0, 0};
    Local l2 = {"B", 3, 4};

    double dist = calcularDistancia(l1, l2);
    mu_assert("Erro: distancia entre (0,0) e (3,4) deve ser 5.0", (int)(dist * 10) == 50);
    return 0;
}

// Executa todos os testes definidos
char *all_tests() {
    mu_run_test(test_calcularDistancia);
    return 0;
}
