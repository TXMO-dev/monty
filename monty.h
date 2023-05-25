#ifndef MONTY_H
#define MONTY_H

/* Structures */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function Prototypes */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void execute_opcode(stack_t **stack, char *line, unsigned int line_number);
void push_stack(stack_t **stack, int value);
void print_stack(stack_t *stack);
void free_stack(stack_t *stack);
int is_integer(const char *str);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */

