#ifndef MONTY_H
#define MONTY_H

/* Other necessary header files */

/* struct definition for stack */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/* struct definition for instruction */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
