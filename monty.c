#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

#define BUFFER_SIZE 1024

/**
* execute_opcode - executes the opcode function based on the instruction
* @instruction: instruction containing the opcode and its arguments
* @stack: double pointer to the stack
* @line_number: line number of the instruction in the Monty file
*/
void execute_opcode(instruction_t *instruction, stack_t **stack, unsigned int line_number)
{
if (strcmp(instruction->opcode, "push") == 0)
{
if (instruction->argument == NULL)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
push(stack, line_number, atoi(instruction->argument));
}
else if (strcmp(instruction->opcode, "pall") == 0)
{
pall(stack);
}
// Add more opcode handling logic here for additional operations
else
{
fprintf(stderr, "L%d: unknown opcode %s\n", line_number, instruction->opcode);
exit(EXIT_FAILURE);
}
}

/**
 * parse_instruction - parses an instruction line from the Monty file
 * @line: line to be parsed
 * @line_number: line number of the instruction in the Monty file
 * Return: instruction_t structure containing the opcode and its argument (if any)
 */
instruction_t parse_instruction(char *line, unsigned int line_number)
{
instruction_t instruction;
char *opcode = strtok(line, " \t\n");
char *argument = strtok(NULL, " \t\n");
if (opcode == NULL)
{
fprintf(stderr, "L%d: missing opcode\n", line_number);
exit(EXIT_FAILURE);
}
instruction.opcode = opcode;
instruction.argument = argument;
return (instruction);
}
/**
* process_file - processes the Monty file
* @filename: name of the Monty file
*/
void process_file(const char *filename)
{
FILE *file = fopen(filename, "r");
if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", filename);
exit(EXIT_FAILURE);
}
char buffer[BUFFER_SIZE];
unsigned int line_number = 0;
stack_t *stack = NULL;
while (fgets(buffer, BUFFER_SIZE, file) != NULL)
{
line_number++;
instruction_t instruction = parse_instruction(buffer, line_number);
execute_opcode(&instruction, &stack, line_number);
}
fclose(file);
// Free any remaining nodes in the stack
while (stack != NULL)
{
stack_t *temp = stack;
stack = stack->next;
free(temp);
}
}

/**
 * main - entry point of the Monty interpreter
 * @argc: argument count
 * @argv: array of arguments
 * Return: 0 on success, 1 on usage error
 */
int main(int argc, char **argv)
{
if (argc != 2)
{
fprintf(stderr, "Usage: monty file\n");
return (EXIT_FAILURE);
}
process_file(argv[1]);
return (EXIT_SUCCESS);
}
