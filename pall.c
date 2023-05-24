#include "monty.h"
/**
* pall - prints all the values on the stack
* @stack: double pointer to the stack
*/
void pall(stack_t **stack)
{
stack_t *current = *stack;
while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}
