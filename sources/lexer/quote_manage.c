#include "../../includes/minishell.h"

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

int	quote_analyzer_utils(char *input)
{
	int	i;
	int	num_quote;

	i = 0;
	num_quote = 0;
	while (input[i])
	{
		if (input[i] == D_QUOTE)
			num_quote++;
		i++;
	}
	return (num_quote);
}

int	quote_analyzer(char *input)
{
	int	diff_quote;

	diff_quote = quote_analyzer_utils(input);
	return (diff_quote);
}