#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"

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

void pall(stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    print_stack(*stack);
}

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

void print_stack(stack_t *stack)
{
    while (stack != NULL)
    {
        printf("%d\n", stack->n);
        stack = stack->next;
    }
}

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
    }
}

int is_integer(const char *str)
{
    if (*str == '-')
        str++;

    if (*str == '\0')
        return 0;

    while (*str != '\0')
    {
        if (!isdigit(*str))
            return 0;

        str++;
    }

    return 1;
}


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

