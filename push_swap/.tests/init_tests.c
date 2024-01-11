#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../includes/push_swap.h"

// Teste para a função append_node
void test_append_node() {
    t_stack *stack = NULL;
    append_node(&stack, 1, 0);

    assert(stack != NULL);
    assert(stack->value == 1);
    assert(stack->current_pos == 0);
    assert(stack->next == NULL);
    assert(stack->prev == NULL);

    // Limpeza da lista após o teste
    free_list(stack);
}

// Teste para a função stack_fill
void test_stack_fill() {
    t_stack *stack = malloc(sizeof(t_stack));
    assert(stack != NULL);

    stack_fill(stack);

    assert(stack->cost_a == 0);
    assert(stack->cost_b == 0);
    assert(stack->current_pos == 0);
    assert(stack->target_pos == 0);
    assert(stack->index == 0);
    assert(stack->next == NULL);
    assert(stack->prev == NULL);

    // Limpeza da lista após o teste
    free_list(stack);
}

// Teste para a função stack_init
void test_stack_init() {
    t_stack *stack_a = NULL;
    char *argv[] = {"3", "1", "4", "1", NULL};
    stack_init(&stack_a, argv);

    assert(stack_a != NULL);
    assert(stack_a->value == 3);
    assert(stack_a->current_pos == 0);
    assert(stack_a->next->value == 1);
    assert(stack_a->next->current_pos == 1);
    assert(stack_a->next->next->value == 4);
    assert(stack_a->next->next->current_pos == 2);

    // Limpeza da lista após o teste
    free_list(stack_a);
}

// Teste para a função free_list
void test_free_list() {
    t_stack *stack = malloc(sizeof(t_stack));
    assert(stack != NULL);

    // Preencher a lista com alguns nós
    append_node(&stack, 1, 0);
    append_node(&stack, 2, 1);
    append_node(&stack, 3, 2);

    // Testar a liberação da lista
    assert(free_list(stack) == EXIT_SUCCESS);
}

int main() {
    // Executar os testes
    test_append_node();
    test_stack_fill();
    test_stack_init();
    test_free_list();

    printf("Todos os testes passaram!\n");

    return 0;
}
