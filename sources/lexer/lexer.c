#include "../../includes/minishell.h"

t_token	token_word(t_shell *dataCmd, char *input, char *last_data)
{
	t_token	new;
	int		flag;

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

	// printf("\tinput1: %c\tinput2: %d\n", input1, input2);
	if (input2 != 0)
		new = (token_no_word(d_isspecial(input1, input2)));
	else
		new = (token_no_word(s_isspecial(input1)));
	return (new);
}

t_token	new_token(t_shell *dataCmd, char *input, char *last_data)
{
	t_token	new;

	if (ft_isalpha_edit(input[0]) || input[0] == D_QUOTE || input[0] == S_QUOTE)
	{
		new = (token_word(dataCmd, input, last_data));
	}
	else if (s_isspecial(input[0]))
	{
		new = token_finder(input[0], input[1]);
	}
	else
		new.type = -1; // Tirar error aqui si se encuentra luego un -1 en type
	// printf("Antes /// Type: %d\tData: %s\n", new.type, new.data);
	return (new);
}

// t_token	loop_tokens(t_shell *dataCmd, char *input, char *last_data)
// {
// 	t_token	token;
// 	int		i;

// 	i = -1;
// 	if (ft_isalpha_edit(input[0]) || input[0] == D_QUOTE || input[0] == S_QUOTE)
// 	{
// 		token = new_token(dataCmd, input, last_data);
// 		// printf("***Input al quitar Comillas: %s\n", ft_substr(input, i, ft_strlen(input)));
// 	}
// 	else
// 	{
// 		token = new_token(dataCmd, input, last_data);
// 	}
// 	return (token);
// }

t_token	*lexer(t_shell *dataCmd, char **input) // Falta por arreglar todavia tema de comillas
{
	int		i;
	int		index;
	t_token	*tokens;
	char	*last_data;

	i = -1;
	index = 0;
	tokens = malloc(sizeof(t_token));
	while (input[++i])
	{
		if (tokens[dataCmd->index - 1].data && tokens[dataCmd->index - 1].type == 1)
			last_data = tokens[dataCmd->index - 1].data;
		else
			last_data = NULL;
		tokens[index++] = new_token(dataCmd, input[i], last_data);
		dataCmd->numOfArgs++;
	}
	return (tokens);
}
