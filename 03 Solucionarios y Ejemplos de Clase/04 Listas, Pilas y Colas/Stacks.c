#include <stdio.h>
#include <stdlib.h>

typedef int TInfo;

typedef struct StackNode {
	TInfo value;
	struct StackNode * next;
} TStackNode;

typedef TStackNode * TStack;

void create_stack(TStack *ptr_stack){
	*ptr_stack = NULL;
}

void push(TStack *ptr_stack, int elem){
	TStackNode *ptrNewNode;
	ptrNewNode = (TStackNode *) malloc(sizeof(TStackNode));	
	ptrNewNode->value = elem;
	ptrNewNode->next = *ptr_stack;
	*ptr_stack = ptrNewNode;
}

void show_stack_elements(TStack stack){
	TStackNode * ptr_aux;
	if (stack == NULL)
		return;

	ptr_aux = stack;
	stack = stack->next;
	show_stack_elements(stack);
	printf("%d ", ptr_aux->value);
}

int is_empty(TStack *ptr_stack){
	return *ptr_stack == NULL;
}

int pop(TStack *ptr_stack){
	TStackNode * ptrDelete;
	int value;

	if (!is_empty(ptr_stack)){
		ptrDelete = *ptr_stack;
		value = (*ptr_stack)->value;
		*ptr_stack = (*ptr_stack)->next;
		free (ptrDelete);
 	}
 	return value;
}

int main(){
	TStack stack;

	create_stack(&stack);
	push(&stack, 5);
	push(&stack, 3);
	push(&stack, 7);
	show_stack_elements(stack);

	int value = pop(&stack);
	value = pop(&stack);
	value = pop(&stack);
	printf("3er valor extraído de la pila: %d\n", value);
	show_stack_elements(stack);

	return 0;
}