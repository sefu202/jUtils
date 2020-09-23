/**
 * @brief Transforms a string according to the given function pointer
 * @note for transforming a string with ctype functions use j_strTransform_int
 * @param [inout] str string to modify
 * @param [in] func functoin to apply on the string
 */
void j_strTransform(char *str, char (*func)(char));

/**
 * @brief Transforms a string according to the given function pointer
 * @note use this function for transforming a string with ctype functions
 * @param [inout] str string to modify
 * @param [in] func functoin to apply on the string
 */
void j_strTransform_int(char *str, int (*func)(int));


/**
 * @brief converts a string to lowercase
 * @param [inout] str
 */
void j_str_tolower(char *str);

/**
 * @brief parses a string by a given delimiter and changes the first delimiter character to \0. The output is in a table
 * @param [in] str intput
 * @param [in] delim delimiter
 * @param [out] tab_out table where the pointers to the tokens are stored
 * @param size_tab size of the table tab_out
 * @return ammount of tokens
 */
size_t j_strparse(char *str, char *delim, char **tab_out, size_t size_tab);