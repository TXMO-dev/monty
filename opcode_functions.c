#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"
/**
 * push - Pushes an element to the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
char *value_str;
int value;
value_str = strtok(NULL, " \t\n");
if (value_str == NULL || !is_integer(value_str))
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
value = atoi(value_str);
push_stack(stack, value);
}

/**
 * pall - Pushes an element to the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
(void)line_number;
print_stack(*stack);
}

/**
 * pus_stack - Pushes an element to the stack
 * @stack: Double pointer to the stack
 * @value: Line number in the file
 */
void push_stack(stack_t **stack, int value)
{
stack_t *new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
new_node->n = value;
new_node->next = *stack;
*stack = new_node;
}

/**
 * print - Pushes an element to the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 */
void print_stack(stack_t *stack)
{
while (stack != NULL)
{
printf("%d\n", stack->n);
stack = stack->next;
}
}
/**
 * execute - Pushes an element to the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 */
void execute_opcode(stack_t **stack, char *opcode, unsigned int line_number)
{
if (strcmp(opcode, "push") == 0)
{
char *arg = strtok(NULL, " \t\n");
int value;
if (arg == NULL || !is_integer(arg))
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
value = atoi(arg);
push_stack(stack, value);
}
else if (strcmp(opcode, "pall") == 0)
{
print_stack(*stack);
} else if (strcmp(opcode, "pint") == 0)
{
pint(stack, line_number);
} else if (strcmp(opcode, "pop") == 0)
{
pop(stack, line_number);
} else if(strcmp(opcode, "swap") == 0)
{
swap(stack, line_number);
} else if(strcmp(opcode, "add") == 0)
{
add(stack, line_number);
} else if(strcmp(opcode, "nop") == 0)
{
nop(stack, line_number);
} else if(strcmp(opcode, "sub") == 0)
{
sub(stack, line_number);
} else if(strcmp(opcode, "div") == 0)
{
div(stack, line_number);
}
/**
 * sub - Subtracts the top element of the stack from the second top element
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}
/**
 * div_op - Divides the second top element of the stack by the top element
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 */
void div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}

/**
 * pop - Removes the top element of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
/**
 * swap - Swaps the top two elements of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
/**
 * add - Adds the top two elements of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
/**
 * execute - Pushes an element to the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 */
int is_integer(const char *str)
{
if (*str == '-')
{
str++;
}
if (*str == '\0')
{
return (0);
}
while (*str != '\0')
{
if (!isdigit(*str))
{
return (0);
}
str++;
}
return (1);
}
/**
 * nop - Doesn't do anything
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * pint - Pushes an element to the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 */
void pint(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
}
/**
 * execute - Pushes an element to the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 */
void free_stack(stack_t *stack)
{
stack_t *current = stack;
while (current != NULL)
{
stack_t *temp = current;
current = current->next;
free(temp);
}
}

