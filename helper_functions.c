#include "main.h"

char *conv_to_binary(unsigned int num)
{	
	int i = 0;
	int binary_array[32] = {0};
	char *res;
	int j;

	if (num == 0)
	{	
		res = malloc(sizeof(char) * 2);
		res[0] = '0';
		res[1] = '\0';

		return (res);
	}

	while (num > 0)
	{	
		binary_array[i] = num % 2;
		num /= 2;
		i++;
	}

	res = malloc(i + 1);

	for (j = 0; j < i; j++)
	{	
		res[j] = binary_array[i - j - 1] + '0';
	}

	res[j] = '\0';

	return (res);
}
