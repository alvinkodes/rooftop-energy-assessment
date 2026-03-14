#include <stdio.h>
#include <stdlib.h>

typedef struct s_node {
	int val;
	struct s_node* next;
} t_node;

typedef struct s_stack {
	t_node* head;
	size_t size;
} t_stack;

t_node* create_node(int val) {
	t_node* new_node;

	new_node = (t_node*)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->val = val;
	new_node->next = NULL;
	return (new_node);
}

void push(t_stack* stack, t_node* node) {
	if (!stack->head) {
		stack->head = node;
		printf("  push(%d)  ->  top is now %d\n", node->val, stack->head->val);
		stack->size++;
		return ;
	}
	node->next = stack->head;
	stack->head = node;
	stack->size++;
	printf("  push(%d)  ->  top is now %d\n", node->val, stack->head->val);
} 

int pop(t_stack* stack) {
	if (!stack->head) {
		printf("The stack is empty! Exiting...\n");
		exit(EXIT_FAILURE);
	}
	t_node* tmp = stack->head;
	int value = tmp->val;
	stack->head = tmp->next;
	free(tmp);
	stack->size--;
	if (stack->head)
        printf("  pop()   ->  removed %d, top is now %d\n", value, stack->head->val);
    else
        printf("  pop()   ->  removed %d, stack is now empty\n", value);
	return (value);
}

int peek(t_stack* stack) {
	if (!stack->head) {
		printf("The stack is empty! Exiting...\n");
		exit(EXIT_FAILURE);
	}
    printf("  peek()  ->  top is %d  (stack unchanged)\n", stack->head->val);
	return (stack->head->val);
}

void print_stack(t_stack* stack) {
    printf("  Stack (top -> bottom): ");
    t_node* cur = stack->head;
    if (!cur) { printf("(empty)"); }
    while (cur) {
        printf("%d", cur->val);
        if (cur->next) printf(" -> ");
        cur = cur->next;
    }
    printf("  [size=%ld]\n", stack->size);
}

void free_stack(t_stack* stack) {
	t_node* cur = stack->head;
	while (cur) {
		t_node* tmp = cur;
		cur = cur->next;
		free(tmp);
	}
}

int main() {
	t_stack stack = {0};
	
	push(&stack, create_node(10));
	push(&stack, create_node(20));
	push(&stack, create_node(30));
	
	printf("\n");
	print_stack(&stack);
	
	printf("\n");
	peek(&stack);

	printf("\n");
	pop(&stack);
	printf("\n");
	print_stack(&stack);
	
	printf("\n");
	push(&stack, create_node(40));
	push(&stack, create_node(50));
	push(&stack, create_node(60));
	peek(&stack);

	printf("\n");
	print_stack(&stack);

	free_stack(&stack);
	return (0);
}