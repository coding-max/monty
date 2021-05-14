#include "monty.h"

size_t not_empty(char *line)
{
	size_t i;

	for (i = 0; i < strlen(line); i ++)
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			break;
	}
	if (i == strlen(line))
		return (0); /* empty */
	return (1); /* not empty */
}


content_v clean_spaces(char *line)
{
	content_v data;
	char *token;
	size_t i;

	/*
	printf("--> entrada: %s\n", line);
	*/
	token = strtok(line, " \n\t");
	while (token != NULL)
	{
		if (strcmp(token,""))
		{
			data.op_func = token;
			break;   
		}
		token = strtok(NULL, " \n\t");
	}
	if (token == NULL)
	{
		data.op_func = NULL;
		data.value = NULL;
		/*
		printf("--> op_func: %s\n", data.op_func);
		printf("--> value: %s\n", data.value);
		*/
		return (data);
	}
	data.value = NULL;
	token = strtok(NULL, " \n\t");
	/*
	printf("-------> token: %s\n", token);
	*/
	while (token != NULL)
	{
		if (strcmp(token,""))
		{
			/*
			printf("-------> token to analyze: %s\n", token);
			*/
			for (i = 0; i < strlen(token); i ++)
			{
				if (!(token[i] >= '0' && token[i] <= '9'))
					if (token[0] != '-')
						break;
			}
			if (i == strlen(token))
			{
				if (!strcmp(token,"-0"))
					data.value = 0;
				data.value = token;
			}
		}
		token = strtok(NULL, " \n\t");
	}
	/*
	printf("--> op_func: %s\n", data.op_func);
	printf("--> value: %s\n", data.value);
	*/
	return(data);
}
