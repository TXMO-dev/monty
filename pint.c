#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
* pint - prints the value at the top of the stack
* @stack: double pointer to the stack
* @line_number: line number of the instruction in the Monty file
*/
void pint(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
}
