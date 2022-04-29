#include "../../includes/minishell.h"

t_token	token_word(char *input, char *last_data)
{
	t_token	new;
	int		flag;

	flag = check_access(input);
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
	if (type == T_PIPE)
		g_shell->numOfPipes++;
	return (new);
}

t_token	token_finder(char input1, char input2)
{
	t_token	new;

	if (input2 != 0)
		new = (token_no_word(d_isspecial(input1, input2)));
	else
		new = (token_no_word(s_isspecial(input1)));
	return (new);
}

t_token	new_token(char *input, char *last_data)
{
	t_token	new;

	if (ft_isalpha_edit(input[0]) || input[0] == D_QUOTE || input[0] == S_QUOTE)
		new = (token_word(input, last_data));
	else if (s_isspecial(input[0]))
		new = token_finder(input[0], input[1]);
	else
	{
		new.type = -1; // Tirar error aqui si se encuentra luego un -1 en type
		// new.data = ft_strdup(input);
	}
	return (new);
}

t_token	*lexer(char **input) //Tratar si solo el problema de las flags ocurre con "echo"
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
		if (tokens[index - 1].data && tokens[index - 1].type == 1
			&& !(ft_strnstr(tokens[index - 1].data, "echo", ft_strlen(tokens[index - 1].data ))))
			last_data = tokens[index - 1].data;
		else
			last_data = NULL;
		tokens[index++] = new_token(input[i], last_data);
		g_shell->numOfArgs++;
	}
	return (tokens);
}
