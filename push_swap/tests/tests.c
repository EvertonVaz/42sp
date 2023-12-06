#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "../src/push_swap.h"

void print_stack(t_stack *stack, const char *name) {
    printf("%s: ", name);
    while (stack) {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

void print_test_result(int result, const char *test_name) {
    if (result) {
        printf("\033[0;32m%s: Passed\n\033[0m", test_name);
    } else {
        printf("\033[0;31m%s: Failed\n\033[0m", test_name);
    }
}

t_stack *new_node(int val) {
    t_stack *node = malloc(sizeof(t_stack));
    node->value = val;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

int are_equal(t_stack *a, t_stack *b)
{
	if (a->value != b->value)
		return 0;
    return 1;
}

void test_push_move() {
    t_stack *src = new_node(1);
    src->next = new_node(2);
    t_stack *dest = new_node(3);
    dest->next = new_node(4);

    print_stack(src, "Source before");
    print_stack(dest, "Destination before");

    int result = push_move(&src, &dest);

    print_stack(src, "Source after");
    print_stack(dest, "Destination after");

    print_test_result(result == 1 && are_equal(src, new_node(2)) && are_equal(dest, new_node(1)), "test_push_move");
}

void test_pa() {
    t_stack *stack_a = new_node(1);
    stack_a->next = new_node(2);
    t_stack *stack_b = new_node(3);
    stack_b->next = new_node(4);

    print_stack(stack_a, "Stack A before");
    print_stack(stack_b, "Stack B before");

    pa(&stack_b, &stack_a);

    print_stack(stack_a, "Stack A after");
    print_stack(stack_b, "Stack B after");

    int result = are_equal(stack_a, new_node(3)) && are_equal(stack_a->next, new_node(1)) && are_equal(stack_b, new_node(4));
    print_test_result(result, "test_pa");
}

void test_pb() {
    t_stack *stack_a = new_node(1);
    stack_a->next = new_node(2);
    t_stack *stack_b = new_node(3);
    stack_b->next = new_node(4);

    print_stack(stack_a, "Stack A before");
    print_stack(stack_b, "Stack B before");

    pb(&stack_a, &stack_b);

    print_stack(stack_a, "Stack A after");
    print_stack(stack_b, "Stack B after");

    int result = are_equal(stack_b, new_node(1)) && are_equal(stack_b->next, new_node(3)) && are_equal(stack_b->next->next, new_node(4)) && are_equal(stack_a, new_node(2));

    print_test_result(result, "test_pb");
}


// Test for swap function
void test_swap() {
    t_stack *stack = new_node(1);
    stack->next = new_node(2);
    stack->next->next = new_node(3);
    stack->next->prev = stack;
    stack->next->next->prev = stack->next;

    print_stack(stack, "Stack before swap");
    int result = swap(&stack);
	printf("result: %d\n", result);
    print_stack(stack, "Stack after swap");

    print_test_result(result == 1 && stack->value == 2 && stack->next->value == 1, "test_swap");
}

// Test for sa function
void test_sa() {
    t_stack *stack = new_node(1);
    stack->next = new_node(2);
    stack->next->prev = stack;

    print_stack(stack, "Stack A before sa");
    sa(&stack);
    print_stack(stack, "Stack A after sa");

    print_test_result(stack->value == 2 && stack->next->value == 1, "test_sa");
}

// Test for sb function
void test_sb() {
    t_stack *stack = new_node(1);
    stack->next = new_node(2);
    stack->next->prev = stack;

    print_stack(stack, "Stack B before sb");
    sb(&stack);
    print_stack(stack, "Stack B after sb");

    print_test_result(stack->value == 2 && stack->next->value == 1, "test_sb");
}

// Test for ss function
void test_ss() {
    t_stack *stack_a = new_node(1);
    stack_a->next = new_node(2);
    stack_a->next->prev = stack_a;

    t_stack *stack_b = new_node(3);
    stack_b->next = new_node(4);
    stack_b->next->prev = stack_b;

    print_stack(stack_a, "Stack A before ss");
    print_stack(stack_b, "Stack B before ss");

    ss(&stack_a, &stack_b);

    print_stack(stack_a, "Stack A after ss");
    print_stack(stack_b, "Stack B after ss");

    print_test_result(stack_a->value == 2 && stack_a->next->value == 1 &&
                      stack_b->value == 4 && stack_b->next->value == 3, "test_ss");
}

// Test for rotate function
void test_rotate() {
    t_stack *stack = new_node(1);
    stack->next = new_node(2);
    stack->next->prev = stack;

    print_stack(stack, "Stack before rotate");
    int result = rotate(&stack);
    print_stack(stack, "Stack after rotate");

    print_test_result(result == 1 && stack->value == 2 && stack->next->value == 1, "test_rotate");
}

// Test for ra function
void test_ra() {
    t_stack *stack_a = new_node(1);
    stack_a->next = new_node(2);
    stack_a->next->prev = stack_a;

    print_stack(stack_a, "Stack A before ra");
    ra(&stack_a);
    print_stack(stack_a, "Stack A after ra");

    print_test_result(stack_a->value == 2 && stack_a->next->value == 1, "test_ra");
}

// Test for rb function
void test_rb() {
    t_stack *stack_b = new_node(1);
    stack_b->next = new_node(2);
    stack_b->next->prev = stack_b;

    print_stack(stack_b, "Stack B before rb");
    rb(&stack_b);
    print_stack(stack_b, "Stack B after rb");

    print_test_result(stack_b->value == 2 && stack_b->next->value == 1, "test_rb");
}

// Test for rr function
void test_rr() {
    t_stack *stack_a = new_node(1);
    stack_a->next = new_node(2);
    stack_a->next->prev = stack_a;

    t_stack *stack_b = new_node(3);
    stack_b->next = new_node(4);
    stack_b->next->prev = stack_b;

    print_stack(stack_a, "Stack A before rr");
    print_stack(stack_b, "Stack B before rr");

    rr(&stack_a, &stack_b);

    print_stack(stack_a, "Stack A after rr");
    print_stack(stack_b, "Stack B after rr");

    print_test_result(stack_a->value == 2 && stack_a->next->value == 1 &&
                      stack_b->value == 4 && stack_b->next->value == 3, "test_rr");
}

// Test for reverse_rotate function
void test_reverse_rotate() {
    t_stack *stack = new_node(1);
    stack->next = new_node(2);
    stack->next->prev = stack;
    stack->next->next = new_node(3);
    stack->next->next->prev = stack->next;

    print_stack(stack, "Stack before reverse_rotate");
    int result = reverse_rotate(&stack);
    print_stack(stack, "Stack after reverse_rotate");

    print_test_result(result == 1 && stack->value == 3 && stack->next->value == 1, "test_reverse_rotate");
}

// Test for rra function
void test_rra() {
    t_stack *stack_a = new_node(1);
    stack_a->next = new_node(2);
    stack_a->next->prev = stack_a;
	stack_a->next->next = new_node(3);
    stack_a->next->next->prev = stack_a->next;

    print_stack(stack_a, "Stack A before rra");
    rra(&stack_a);
    print_stack(stack_a, "Stack A after rra");

    print_test_result(stack_a->value == 3 && stack_a->next->value == 1, "test_rra");
}

// Test for rrb function
void test_rrb() {
    t_stack *stack_b = new_node(1);
    stack_b->next = new_node(2);
    stack_b->next->prev = stack_b;
	stack_b->next->next = new_node(3);
    stack_b->next->next->prev = stack_b->next;

    print_stack(stack_b, "Stack B before rrb");
    rrb(&stack_b);
    print_stack(stack_b, "Stack B after rrb");

    print_test_result(stack_b->value == 3 && stack_b->next->value == 1, "test_rrb");
}

// Test for rrr function
void test_rrr() {
    t_stack *stack_a = new_node(1);
    stack_a->next = new_node(2);
    stack_a->next->prev = stack_a;
	stack_a->next->next = new_node(3);
    stack_a->next->next->prev = stack_a->next;

    t_stack *stack_b = new_node(3);
    stack_b->next = new_node(4);
    stack_b->next->prev = stack_b;
	stack_b->next->next = new_node(5);
    stack_b->next->next->prev = stack_b->next;

    print_stack(stack_a, "Stack A before rrr");
    print_stack(stack_b, "Stack B before rrr");

    rrr(&stack_a, &stack_b);

    print_stack(stack_a, "Stack A after rrr");
    print_stack(stack_b, "Stack B after rrr");

    print_test_result(stack_a->value == 3 && stack_a->next->value == 1 &&
                      stack_b->value == 5 && stack_b->next->value == 3, "test_rrr");
}

int main() {
    test_push_move();
    test_pa();
    test_pb();
	test_swap();
    test_sa();
    test_sb();
    test_ss();
	test_rotate();
    test_ra();
    test_rb();
    test_rr();
	test_reverse_rotate();
    test_rra();
    test_rrb();
    test_rrr();
    return 0;
}


