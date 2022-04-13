#include "../../includes/minishell.h"

t_token	token_word(t_shell *dataCmd, char *input, char *last_data)
{
	t_token	new;
	int		flag;

	// printf("input: %s\n", input);
	flag = check_access(dataCmd, input);
	if (last_data && input[0] == '-')
		flag = 1;
	if (flag == 1)
	{
		new.type = T_CMD;
		new.data = input;
	}
	else
	{
		new.type = T_TEXT;
		new.data = input;
	}
	return (new);
}

t_token	token_no_word(int type)
{
	t_token	new;

	new.data = NULL;
	new.type = type;
	return (new);
}

t_token	token_finder(char input1, char input2)
{
	t_token	new;

	if (input2)
		new = (token_no_word(ft_isspecial(input1, input2)));
	else
		new = (token_no_word(ft_isspecial(input1, 0)));
	return (new);
}

t_token	new_token(t_shell *dataCmd, char *input, char *last_data)
{
	int 	i;
	t_token	new;

	i = -1;
	while (input[++i])
	{
		printf("Input: %c\n", input[i]);
		if (input[i] == S_QUOTE || ft_isalpha_edit(input[i]))
		{
			quote_analyzer(dataCmd, input);
			new = (token_word(dataCmd, input, last_data));
			break ;
		}
		else if (ft_isspecial(input[i], 0))
			new = token_finder(input[i], input[i + 1]);
	}
	return (new);
}

t_token	*lexer(t_shell *dataCmd, int args, char **input)
{
	int		i;
	int		index;
	char	*last_data;
	t_token	*token;

	token = malloc(sizeof(t_token));
	i = 0;
	index = 0;
	while (i < args)
	{
		if (token[index - 1].data && token[index - 1].type == 1)
			last_data = token[index - 1].data;
		else
			last_data = NULL;
		printf("input antes: %s\n", input[i]);
		token[index++] = new_token(dataCmd, input[i], last_data);
		i++;
	}
	dataCmd->numOfArgs = index;
	return (token);
}
