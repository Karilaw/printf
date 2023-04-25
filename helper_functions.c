#include "main.h"

/**
 * conv_to_binary - converts unsigned integer to binary
 * @num: number to be converted
 *
 * Return: binary number
 */

char *conv_to_binary(unsigned int num)
{
	char *binary = malloc(sizeof(char) * 33);
	int i = 0;
	int j;

	if (num == 0)
	{
		binary[i++] = '0';
	}

	while (num > 0)
	{
		binary[i++] = (num % 2) + '0';
		num /= 2;
	}

	binary[i] = '\0';
	
	for (j = 0; j < i / 2; j++)
	{
		char tmp = binary[j];
		binary[j] = binary[i - j - 1];
		binary[i - j - 1] = tmp;
	}

	return (binary);



}

char *_uitoa_base(unsigned int n, unsigned int base)
{
	char *s;
	char array_digits[] = "0123456789abcdef";
	int i = 0;
	int j;
	char temp;

	if (n == 0)
	{
		s = malloc(sizeof(char) * 2);
		if (s == NULL)
			return (NULL);
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}

	s = malloc(sizeof(char) * 33);
	if (s == NULL)
		return (NULL);

	while (n > 0)
	{
		s[i] = array_digits[n % base];
		n /= base;
		i++;
	}
	s[i] = '\0';

	for (j = 0; j < i / 2; j++)
	{
		temp = s[j];
		s[j] = s[i - j - 1];
		s[i - j - 1] = temp;
	}
	return (s);
}


