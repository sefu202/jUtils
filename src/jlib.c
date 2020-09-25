#include <ctype.h>
#include <stdbool.h>

/**
 * @brief converts a string with comma into an int, digits after digitsAfterComma are ignored
 * excample: atoi_d("10.15", 2) would result in 1015.
 * @param [in] str input string
 * @param digitsAfterComma result is multiplied by 10^this
 * @retval number found in the string
 */
int atoi_d(char *str, unsigned char digitsAfterComma)
{
	char c;
	int ret = 0;
	bool isNegative = false;

	if (*str == '-')
	{
		isNegative = true;
		str++;
	}
	while (isdigit(c = *(str++)))
	{
		ret *= 10;
		ret += c - '0';
	}
	if (c == '.')
	{
		while (c = *(str++), isdigit(c) && digitsAfterComma--)
		{
			ret *= 10;
			ret += c - '0';
		}
	}
	for (unsigned char i = 0; i < digitsAfterComma; i++)
	{
		ret *= 10;
	}
	if (isNegative)
	{
		ret *= -1;
	}
	return ret;
}
