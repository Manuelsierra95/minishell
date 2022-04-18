#include<stdio.h>
#include"./libft/libft.h"

char *test_i(char *input, int *i)
{
	int	x;

	x = *i;
	printf("x: %d\n", x);
	while (input[x])
	{
		if (input[x] == ' ')
			break ;
		x++;
	}
	*i = x;
	return (ft_substr(input, *i, ft_strlen(input)));
}

int main(void)
{
	static int	i;
	char	*input;

	input = "Hola como estamos";
	i = 0;
	while (input[i])
	{
		printf("String: %c\tvalor despues de i: %d\n", input[i], i);
		test_i(input, &i);
		// printf("String: %c\tvalor antes de i: %d\n", input[i], i);
		i++;
	}
}