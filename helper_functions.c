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
        for (j = 0; j < i / 2; j++)
        {
                temp = s[j];
                s[j] = s[i - j - 1];
                s[i - j - 1] = temp;
        }
        return (s);
}
