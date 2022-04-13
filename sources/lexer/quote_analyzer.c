#include "../../includes/minishell.h"

int	quote_analyzer_utils2(char *input)
{
	int	i;
	int	r_quote;

	i = 0;
	r_quote = 0;
	while (input[i])
	{
		if (input[i] == S_QUOTE)
		{
			while (input[i] == S_QUOTE && input[i])
			{
				r_quote++;
				i++;
			}
			break ;
		}
		i++;
	}
	return (r_quote);
}

int	quote_analyzer_utils(t_shell *dataCmd, char *input)
{
	int	i;
	int	l_quote;
	int	r_quote;

	i = 0;
	l_quote = 0;
	while (input[i])
	{
		if (input[i] == S_QUOTE)
		{
			while (input[i] == S_QUOTE && input[i++])
				l_quote++;
			break ;
		}
		i++;
	}
	r_quote = quote_analyzer_utils2(ft_substr(input, i, ft_strlen(input)));
	dataCmd->l_quote_len = l_quote;
	dataCmd->r_quote_len = r_quote;
	return (l_quote - r_quote);
}

void	quote_analyzer(t_shell *dataCmd, char *input)
{
	int	dif_quote;

	dif_quote = quote_analyzer_utils(dataCmd, input);
	if (dif_quote != 0)
		printf("Error de comillas\n");
	printf("dif_quote: %d\n", dif_quote);
}
