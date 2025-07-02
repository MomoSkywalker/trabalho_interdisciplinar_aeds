#include "minunit.h"
#include "../src/pedidos.h"

int tests_run = 0;

char *test_buscarPedidoPorId() {
    Pedido pedidos[2] = {
        {1, "A", "B", 10.0},
        {2, "C", "D", 20.0}
    };

    mu_assert("Erro: Pedido 1 deve estar na posição 0", buscarPedidoPorId(1, pedidos, 2) == 0);
    mu_assert("Erro: Pedido 2 deve estar na posição 1", buscarPedidoPorId(2, pedidos, 2) == 1);
    mu_assert("Erro: Pedido inexistente deve retornar -1", buscarPedidoPorId(3, pedidos, 2) == -1);
    return 0;
}

char *all_tests() {
    mu_run_test(test_buscarPedidoPorId);
    return 0;
}

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