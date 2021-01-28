#include "LinkedList.h"

typedef LinkedList Stack;

Stack *stack_init(void);
void *stack_peek(Stack *stack);
void *stack_pop(Stack *stack);
void stack_push(Stack *stack, void *data);
void stack_free(Stack *stack);