#include "monty.h"

extern_var_t ex;

/**
 * main - honestly, idk.
 * Return: less find out god.
 */
int main(int argc, char *argv[])
{
	FILE *fp;

	/* arg error */
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(1);
	}
	/* open file error */
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s", argv[1]);
		exit(1);
	}
	read_file(fp);
	fclose(fp);
	return(0);
}

/*
	ex.
	+---------------+
	| data.op_func	| -> char* 		(primera palabra del opcode)
	| data.value	| -> char* 		(primer argumento del opcode)
	| data.line_n	| -> int 		(numero del linea que se lee)
	| int_value		| -> int		(primer argumento del opcode - atoi(data.value))
	+---------------+
*/

/**
 * read_file - honestly, idk.
 * @fp: idk.
 * Return: less find out god.
 */
void read_file(FILE *fp)
{
	char *line = NULL;
	size_t len = 0;
	int status, line_status, exe_code, i;
	stack_t *top_ptr = NULL;

	/* get new line from fp's buffer */
	i = 0;
	printf("----------------------\n");
	while (getline(&line, &len, fp) != -1)
	{
		printf("--> %s", line);
		ex.data = clean_spaces(line);
		printf("--> data.op_func = %s\n", ex.data.op_func);
		printf("--> data.value = %s\n", ex.data.value);
		if (ex.data.value)
		{
			ex.int_value = atoi(ex.data.value);
			printf("--> ex.int_value = %d\n", ex.int_value);
		}
		else
		{
			printf("--> ex.int_value = empty\n");
		}
		ex.data.line_n = i;
		printf("--> ex.data.line_n = %d\n", ex.data.line_n);
		get_function(ex.data.op_func)(&top_ptr, ex.data.line_n);
		/*
		free(line);
		free(ex.data.op_func);
		free(ex.data.value);
		*/
		i++;
		printf("----------------------\n");
	}
	// free stack
}

/**
 * get_function - honestly, idk.
 * @op_function: idk.
 * Return: less find out god.
 */
void (*get_function(char *op_function))(stack_t **, unsigned int)
{
	instruction_t functions[] = {
		{"push"	, monty_push},
		{"pall"	, monty_pall},
		{"pint"	, monty_pint},
		{"pop"	, monty_pop},
		/*
		{"swap"	, monty_swap},
		*/
		{NULL, NULL}
	};
	int i;

	for (i = 0; functions[i].opcode; i++)
		if (op_function == functions[i].opcode)
			break;

	return (functions[i].f);
}
