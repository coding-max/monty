#ifndef MONTY
#define MONTY
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN

#include <stdio.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct  - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct content
{
        char *op_func;
        char *value;
        int line_n;
} content_v;


typedef struct stakit
{
        int int_value;
        content_v data;
        struct stack_s *top;
} extern_var_t;


void read_file(FILE *fp);
void (*get_function(char *op_function))(stack_t **, unsigned int);
content_v clean_spaces(char *line);
size_t stack_len(const stack_t *h);

void monty_push(stack_t **top, unsigned int line_n);
void monty_pall(stack_t **top, unsigned int line_n);
void monty_pint(stack_t **top, unsigned int line_n);
void monty_pop(stack_t **top, unsigned int line_n);
void monty_swap(stack_t **top, unsigned int line_n);

#endif