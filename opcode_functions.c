#include "monty.h"

void push(stack_t **stack,unsigned int line_number)
{
    /* Check if there is an argument */
    if (global_data.current_token == NULL)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Convert the argument to an integer */
    int value;
    char *endptr;
    value = strtol(global_data.current_token, &endptr, 10);
    if (*endptr != '\0')
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Create a new node for the stack */
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    /* Initialize the new node */
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    /* Update the previous node's pointer */
    if (*stack != NULL)
        (*stack)->prev = new_node;

    /* Update the stack pointer */
    *stack = new_node;
}

void pall(stack_t **stack)
{
    stack_t *current = *stack;

    /* Print all values on the stack */
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
