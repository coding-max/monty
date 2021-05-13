#include "monty.h"

int counting_letters(char *line)
{
    int i, c_let = 0;

     for (i = 0; i < (strlen(line) -1); i++)
    {
        if (line[i] >= 'a' && line[i] <= 'z')
        {
            c_let++;
            if (c_let > 0 && (line[i + 1] == ' ' || line[i + 1] == '\0'))
                break;
        }
    }
    return (c_let);
}

int counting_numbers(char *line)
{
    int i, c_num = 0;

    for (i = 0; i < (strlen(line) -1); i++)
    {
        if (line[i] >= '0' && line[i] <= '9')
        {
            c_num++;
            if (c_num > 0 && (line[i + 1] == ' ' || line[i + 1] == '\0') )
                break;
        }
    }
    return (c_num);
}

char *get_op(char *line, char *clean_line)
{
    int i, j, c_let;
    c_let = counting_letters(line);

    for (i = 0, j = 0; i < (strlen(line) - 1); i++)
    {
        if (line[i] >= 'a' && line[i] <= 'z')
        {
            clean_line[j] = line[i];
            j++;
            if (c_let > 0 && (line[i + 1] == ' ' || line[i + 1] == '\0'))
                break;
        }
    }
    return (clean_line);
}

char *get_value(char *line, char *clean_num)
{
    int i, j, c_num;
    c_num = counting_numbers(line);

    for (i = 0, j = 0; i < (strlen(line) - 1); i++)
    {
        if (line[i] >= '0' && line[i] <= '9')
        {
            clean_num[j] = line[i];
            j++;
            if (c_num > 0 && (line[i + 1] == ' ' || line[i + 1] == '\0'))
                break;
        }
    }
    return (clean_num);
}

content_v clean_spaces(char *line)
{
    char *clean_line, *clean_num;
    int count_letters, count_numbers;

    content_v data;
    data.line_n = 0;

    count_letters = counting_letters(line);
    clean_line = malloc(sizeof(count_letters));
    if (!clean_line)
        printf("NO PUEDE ALLOCAR\n");

    clean_line = get_op(line, clean_line);
    data.op_func = clean_line;
    if (count_letters == 0)
        data.op_func = NULL;
            /* mallo error - return (NULL); */
    
    printf("----> data.op_func = %s\n", data.op_func);

    count_numbers = counting_numbers(line);
    clean_num = malloc(sizeof(count_numbers));
    if (!clean_num)
        printf("NO PUEDE ALLOCAR\n");
            /* mallo error - return (NULL); */
    clean_num = get_value(line, clean_num);
    data.value = clean_num;
    if (count_numbers == 0)
        data.value = NULL;
    printf("----> data.value = %s\n", data.value);

    printf("----> data.value = 434*****----%s\n*--*-*-*-", data.value);
    
    return (data);
}