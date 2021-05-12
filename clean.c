#include "monty.h"

int counting_letters(char *line)
{
    int i, c_let = 0;

     for (i = 0; i < strlen(line); i++)
    {
        if (line[i] >= 'a' && line[i] <= 'z')
        {
            c_let++;
            if (c_let > 0 && (line[i+1] = ' ' || line[i+1] = '\0'))
                break;
        }
    }
    return (c_let);
}

int counting_numbers(char *line)
{
    int i, c_num = 0;

    for (i = 0; i < strlen(line); i++)
    {
        if (line[i] >= '0' && line[i] <= '9')
        {
            c_num++;
            if (c_num > 0 && (line[i + 1] = ' ' || line[i+1] = '\0'))
                break;
        }
    }
    return (c_num);
}

char get_op(char *line)
{
    char *clean_line;
    int i, j;

    for (i = 0, j = 0; i < strlen(line); i++)
    {
        if (line[i] >= 'a' && line[i] <= 'z')
        {
            clean_line[j] = line[i];
            j++;
        }
    }
    return (clean_line);
}

char get_value(char *line)
{
    char *clean_num;
    int i, j;

    for (i = 0, j = 0; i < strlen(line); i++)
    {
        if (line[i] >= '0' && line[i] <= '9')
        {
            clean_num[j] = line[i];
            j++;
        }
    }
}

content_v clean_spaces(char *line)
{
    int count_letters, count_numbers;

    content_v data;
    data.line_n = 0;

    count_letters = counting_letters(line);
    if (count_letters == 0)
        data.op_func = NULL;
    else
    {
        clean_line = malloc(sizeof(count_letters));
        if (!clean_line)
            return (NULL);
        data.op_func = get_op(line);
    }
    count_numbers = counting_numbers(line);
    if (count_numbers == 0)
        data.value = NULL;
    else
    {
        clean_num = malloc(sizeof(count_numbers));
        if (!clean_num)
            return (NULL);
        data.value = get_value(line);
    }
    return (data);
}
