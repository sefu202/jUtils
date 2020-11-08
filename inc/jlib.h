
/**
 * @brief converts a string with comma into an int, digits after digitsAfterComma are ignored
 * excample: atoi_d("10.15", 2) would result in 1015.
 * @param [in] str input string
 * @param digitsAfterComma result is multiplied by 10^this
 * @retval number found in the string
 */
int atoi_d(char *str, unsigned char digitsAfterComma);


/**
 * @brief converts a number to a string according to a input format
 * following characters are implemented:
 *  +: show sign of any number
 *  -: show sign of negative number only
 *  n: digit, ignore if number is too small to fill
 *  N: digit, always fill, (if there are no digits left from itoa it will be filled with 0s)
 *  ': for better readability of big numbers, will be ignored if the number is too small
 *  anything else will just be copied to the output
 * excample format string: "+nn'NNN.NN" shows numbers up to 99'999.99 from an input up to 
 * 9999999 and atleast shows 5 digits (2 behind the comma)
 * if the input number is too big for the format the output will overwrite the first symbol with a #
 * @param format format for the output
 * @param in input number
 * @param out output buffer (shoud be atleast the size of the format)
 */
void itoa_formated(const char *format, int32_t in, char *out);

/**
 * @brief long version of itoa_formated
 * @param format format for the output
 * @param in input number
 * @param out output buffer (shoud be atleast the size of the format)
 */
void ltoa_formated(const char *format, long in, char *out)