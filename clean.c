#include "monty.h"

content_v clean_spaces(char *line)
{
    content_v data;

    /* entrada nunca vacia - contien al menos el carcater \n */
    /* puede ser vacio ("") */
    data.op_func = strtok(line, " \n\t");
    //printf("--> data.op_func = %s\n", data.op_func);
    data.value = strtok(NULL, " \n\t");
    //printf("--> data.value = %s\n", data.value);

    return(data);
}
