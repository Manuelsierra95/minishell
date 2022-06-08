#include "minishell.h"

int	count_quotes(char *input)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] == D_QUOTE || input[i] == S_QUOTE)
			count++;
		i++;
	}
	return (count);
}

int	check_quotes(char *input)
{
	int	i;

	i = 0;
	while(input[i])
	{
		if (input[i] == D_QUOTE)
			return (1);
		i++;
	}
	return (0);
}
char	*take_off_quotes(char *input)
{
	int		i;
	int		j;
	char	*no_quotes_input;

	i = 0;
	j = 0;
	no_quotes_input = malloc(sizeof(char *));
	while (input[i])
	{
		if (input[i] != D_QUOTE)
			no_quotes_input[j++] = input[i];
		i++;
	}
	if (no_quotes_input)
		no_quotes_input[j] = '\0';
	return (no_quotes_input);
}

void	check_quote_error(char *input)
{
	int	state;
	int	i;

	i = -1;
	while (input[++i])
	{
		state = input_state(input[i]);
		if (state == D_QUOTE || state == S_QUOTE)
		{
			if ((state == D_QUOTE || state == S_QUOTE) && (int)ft_strlen(input) == i + 1)
				mng_errors(QUOTE_ERROR, NULL);
			while (input[++i])
			{
				if (input[i] == state)
					break ;
				if (i == (int)ft_strlen(input) - 1)
					mng_errors(QUOTE_ERROR, NULL);
			}
		}
	}
}