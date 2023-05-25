#include "monty.h"

/* Number of opcodes */
#define NUM_OPCODES 2

int main(int argc, char *argv[])
{
    FILE *file;
    stack_t *stack = NULL;
    char line[1024];

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        /* Rest of the code */
    }

    /* Free resources */
    free_stack(stack);
    fclose(file);

    return 0;
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
