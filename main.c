#include "monty.h"

/**
 * main - honestly, idk.
 * Return: less find out god.
 */
int main(int argc, char *argv[])
{
	int exe_code;
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
    
	exe_code = read_file(fp);
	fclose(fp);
	return(exe_code);
}

/**
 * read_file - honestly, idk.
 * @fp: idk.
 * Return: less find out god.
 */
int read_file(FILE *fp)
{
	char *line = NULL;
	size_t len = 0;
	content_v data;
		// data.op_function
		// data.value
    struct stakit p_stack;
		// p_stack.top;
		// p_stack.head;
	int status, line_status;
	extern_var_t ex;

	/* get new line from fp's buffer */
	i = 0;
	while (1)
	{
		line_status = getline(&line, &len, fp);
		if (line_status == -1)
		{
			/* EOF or reading error */ 
			//TODO
			break;
		}
		ex.data = clean_spaces(line);
		ex.data.line_n = i;
		exe_code = get_function(ex.data.op_func)(*(ex.top), i);

		i++;
	}
	return (exe_code);
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
		{"swap"	, monty_swap},
		{NULL, NULL}
	};
	int i;

	for (i = 0; functions[i].opcode; i++)
		if (opcode == functions[i].opcode)
			break;

	return (functions[i].function)

}
