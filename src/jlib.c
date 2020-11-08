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


#define ITOA_FORMATED_BUFFER_SIZE 10
char itoa_formated(const char *format, int in, char *out)
{
	if (out == NULL) {
		return -1;
	}
	
	if (format == NULL) {
		out[0] = '#';
		out[1] = '\0';
		return -1;
	}

	char buffer[ITOA_FORMATED_BUFFER_SIZE];	// buffer for itoa
	char *ptrBuffer = buffer;				// pointer to buffer to remove negative sign, see flag1		
	unsigned char idx_out = 0, idx_buffer = 0, idx_format = 0; // indexes for memory
	//uint8_t size_buffer;
	const bool isNegative = in < 0;	// flag for negative numbers

	itoa(in, buffer, 10);	// convert number to string

	// flag1:
	if (isNegative) {
		ptrBuffer++;	// itoa will add a leading '-' which is unwanted
	}

	idx_buffer = strlen(ptrBuffer);
	idx_format = strlen(format);
	idx_out = idx_format;

	while(idx_format) {
		char out_c;	// temporary storage for the character to be written to the output buffer
		char c = format[--idx_format];	// temporary storage for format
		switch (c) {
			// '+' means show positive and negative sign
			case '+': 
				if (!isNegative) {
					out_c = '+';
				}
			// '-' means show only negative sign, this part is the same for + and -
			case '-':
				if (isNegative) {
					out_c = '-';
				}
				break;
			// write the number to the output
			case 'N':
			case 'n':
				if (idx_buffer) {
					out_c = ptrBuffer[--idx_buffer];
				} else if (c == 'N') {	// for 'N' always fill
					out_c = '0';
				}
				break;
			// ignore ''' if there arent any numbers to come anymore
			case '\'':
				// still more numbers left in the buffer or big N (or anything else) following
				if (idx_buffer || (idx_format -1 && (format[idx_format-1] != 'n'))) {
					out_c = c;
				}
				break;
			// every other character
			default:
				out_c = c;
				break;
		}
		out[--idx_out] = out_c;
	}

	// move the string to the beginning of out
	memmove(out, out+idx_out, ITOA_FORMATED_BUFFER_SIZE-idx_out);
	// and \0 terminate it
	out[(ITOA_FORMATED_BUFFER_SIZE - 1) - idx_out] ='\0';

	// number too big for format
	if (idx_buffer) {
		out[0] = '#';
	}

	return 0;
}

#define LTOA_FORMATED_BUFFER_SIZE 10
char ltoa_formated(const char *format, long in, char *out)
{
	if (out == NULL) {
		return -1;
	}
	
	if (format == NULL) {
		out[0] = '#';
		out[1] = '\0';
		return -1;
	}

	char buffer[ITOA_FORMATED_BUFFER_SIZE];	// buffer for itoa
	char *ptrBuffer = buffer;				// pointer to buffer to remove negative sign, see flag1		
	unsigned char idx_out = 0, idx_buffer = 0, idx_format = 0; // indexes for memory
	//uint8_t size_buffer;
	const bool isNegative = in < 0;	// flag for negative numbers

	ltoa(in, buffer, 10);	// convert number to string

	// flag1:
	if (isNegative) {
		ptrBuffer++;	// itoa will add a leading '-' which is unwanted
	}

	idx_buffer = strlen(ptrBuffer);
	idx_format = strlen(format);
	idx_out = idx_format;

	while(idx_format) {
		char out_c;	// temporary storage for the character to be written to the output buffer
		char c = format[--idx_format];	// temporary storage for format
		switch (c) {
			// '+' means show positive and negative sign
			case '+': 
				if (!isNegative) {
					out_c = '+';
				}
			// '-' means show only negative sign, this part is the same for + and -
			case '-':
				if (isNegative) {
					out_c = '-';
				}
				break;
			// write the number to the output
			case 'N':
			case 'n':
				if (idx_buffer) {
					out_c = ptrBuffer[--idx_buffer];
				} else if (c == 'N') {	// for 'N' always fill
					out_c = '0';
				}
				break;
			// ignore ''' if there arent any numbers to come anymore
			case '\'':
				// still more numbers left in the buffer or big N (or anything else) following
				if (idx_buffer || (idx_format -1 && (format[idx_format-1] != 'n'))) {
					out_c = c;
				}
				break;
			// every other character
			default:
				out_c = c;
				break;
		}
		out[--idx_out] = out_c;
	}

	// move the string to the beginning of out
	memmove(out, out+idx_out, ITOA_FORMATED_BUFFER_SIZE-idx_out);
	// and \0 terminate it
	out[(ITOA_FORMATED_BUFFER_SIZE - 1) - idx_out] ='\0';

	// number too big for format
	if (idx_buffer) {
		out[0] = '#';
	}

	return 0;
}