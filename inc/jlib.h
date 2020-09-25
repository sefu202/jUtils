
/**
 * @brief converts a string with comma into an int, digits after digitsAfterComma are ignored
 * excample: atoi_d("10.15", 2) would result in 1015.
 * @param [in] str input string
 * @param digitsAfterComma result is multiplied by 10^this
 * @retval number found in the string
 */
int atoi_d(char *str, unsigned char digitsAfterComma);