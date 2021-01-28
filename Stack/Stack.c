#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

Stack *stack_init(void)
{
    Stack *stack = malloc(sizeof(Stack));
    if (stack == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for stack.\n");
    }
    return stack;
}

void *stack_peek(Stack *stack)
{
    if (stack == NULL)
    {
        fprintf(stderr, "Cannot peek null stack.\n");
        return NULL;
    }

    if (stack->head == NULL)
    {
        fprintf(stderr, "Cannot peek empty stack.\n");
        return NULL;
    }

    return stack->head->data;
}

void *stack_pop(Stack *stack)
{
    void *data;
    if (stack == NULL)
    {
        fprintf(stderr, "Cannot pop null stack.\n");
        return NULL;
    }

    if (stack->head == NULL)
    {
        fprintf(stderr, "Cannot pop empty stack.\n");
        return NULL;
    }

    return linked_list_remove_head(stack);
}

void stack_push(Stack *stack, void *data)
{
    if (stack == NULL)
    {
        fprintf(stderr, "Cannot push to null stack.\n");
        return;
    }
    linked_list_prepend(stack, data);
}

void stack_free(Stack *stack)
{
    if (stack == NULL)
    {
        fprintf(stderr, "Cannot free null stack.\n");
        return;
    }
    linked_list_free_list(stack);
}