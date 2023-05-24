#include "monty.h"
/**
* push - pushes an element to the stack
* @stack: double pointer to the stack
* @line_number: line number of the instruction in the Monty file
* @value: integer value to be pushed
*/
void push(stack_t **stack, unsigned int line_number, int value)
{
stack_t *new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
new_node->n = value;
new_node->prev = NULL;
new_node->next = *stack;
if (*stack != NULL)
{
(*stack)->prev = new_node;
}
*stack = new_node;
}
