
#include "../inc/string.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/**
 * @brief Transforms a string according to the given function pointer
 * @note for transforming a string with ctype functions use j_strTransform_int
 * @param [inout] str string to modify
 * @param [in] func functoin to apply on the string
 */
void j_strTransform(char *str, char (*func)(char))
{
    size_t i = 0;
    char c = str[i];
    while(c)
    {
        str[i] = func(c);
        c = str[++i];
    }
}

/**
 * @brief Transforms a string according to the given function pointer
 * @note use this function for transforming a string with ctype functions
 * @param [inout] str string to modify
 * @param [in] func functoin to apply on the string
 */
void j_strTransform_int(char *str, int (*func)(int))
{
    size_t i = 0;
    char c = str[i];
    while(c)
    {
        str[i] = func(c);
        c = str[++i];
    }
}


/**
 * @brief converts a string to lowercase
 * @param [inout] str
 */
void j_str_tolower(char *str)
{
	size_t i = 0;
	char c = str[i];
	while(c)
	{
		str[i] = tolower(c);
		c = str[++i];
	}
}

/**
 * @brief parses a string by a given delimiter and changes the first delimiter character to \0. The output is in a table
 * @param [in] str intput
 * @param [in] delim delimiter
 * @param [out] tab_out table where the pointers to the tokens are stored
 * @param size_tab size of the table tab_out
 * @return ammount of tokens
 */
size_t j_strparse(char *str, char *delim, char **tab_out, size_t size_tab)
{
	size_t idx_tab = 0;
	char *saveptr;
	if (size_tab > 0)
	{
		if ((tab_out[idx_tab++] = strtok_r(str, delim, &saveptr)) != NULL)
		{	
			while ((idx_tab < size_tab) && 
				  ((tab_out[idx_tab++] = strtok_r(NULL, delim, &saveptr)) != NULL));
		}
	}
	return idx_tab - 1;	// last one is NULL, therefore subtract one
}
