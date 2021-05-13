#include "monty.h"

content_v clean_spaces(char *line)
{
    content_v data;

    /* entrada nunca vacia - contien al menos el carcater \n */
    /* puede ser vacio ("") */
    data.op_func = strtok(line, " \n\t");
    
    data.value = strtok(NULL, " \n\t");

    return(data);
}
