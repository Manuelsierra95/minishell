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

	// printf("		input:	%s\n", input);
	if (ft_isalpha_edit(input[0]))
	{
		new = (token_word(dataCmd, input, last_data));
	}
	else if (s_isspecial(input[0]))
	{
		// printf("%c\t%c\n", input[i], input[i + 1]);
		new = token_finder(input[0], input[1]);
	}
	else
		new.type = -1; // Tirar error aqui si se encuentra luego un -1 en type
	// printf("Antes /// Type: %d\tData: %s\n", new.type, new.data);
	return (new);
}

t_token	*loop_tokens(t_shell *dataCmd, char *input)
{
	char	*last_data;
	char	*aux_input;
	t_token	*token;
	int		i;

	i = -1;
	aux_input = NULL;
	token = malloc(sizeof(t_token));
	while (input[++i])
	{
		// printf(" ///// Input antes ya spliteado: %s\n", input);
		// input = take_off_quotes(input);
		if (token[dataCmd->index - 1].data && token[dataCmd->index - 1].type == 1)
			last_data = token[dataCmd->index - 1].data;
		else
			last_data = NULL;
		if ((ft_strchr(input, SPACE) || ft_strchr(input, D_QUOTE)
			|| ft_strchr(input, S_QUOTE)))
		{
			// printf(" ///// Input que entra: %s\n", ft_substr(input, i, ft_strlen(input)));
			// aux_input = take_off_spaces(input, i);
			token[dataCmd->index++] = new_token(dataCmd, aux_input, last_data);
			i += ft_strlen(aux_input) + 2;
			// printf("***Input al quitar Comillas: %s\n", ft_substr(input, i, ft_strlen(input)));
		}
		else
		{
			token[dataCmd->index++] = new_token(dataCmd, input, last_data);
			i += ft_strlen(token[dataCmd->index - 1].data) - 1;
		}
		printf("dataCmd->Index: %d\tType: %d\tData: %s\n", dataCmd->index - 1, token[dataCmd->index - 1].type, token[dataCmd->index - 1].data);
	}

	// printf("input antes: %s\n", input);
	return (token);
}

t_token	*lexer(t_shell *dataCmd, char **input) // Falta por arreglar todavia tema de comillas
{
	int		i;
	int		x;
	char	**split_input;
	t_token	*tokens;

	i = -1;
	while (input[++i])
	{
		split_input = edit_split(input[i], SPACE);
		x = -1;
		while (split_input[++x])
		{
			printf("input antes del loop: %s\n", split_input[x]);
			tokens = loop_tokens(dataCmd, split_input[x]);
		}

		printf("\n\nValor de la i: %d\n\n", i);
	}

	// printf("token: %s\n", tokens[0].data);

	// int index = 0;
	// 	while (index < dataCmd->index)
	// 	{
	// 		printf("Index: %d\tType: %d\tData: %s\n", index, tokens[index].type, tokens[index].data);
	// 		index++;
	// 	}

	// dataCmd->tokens = token;
	// int index = 0;
	// 	while (index < dataCmd->index)
	// 	{
	// 		printf("Index: %d\tType: %d\tData: %s\n", index, dataCmd->tokens[index].type, dataCmd->tokens[index].data);
	// 		index++;
	// 	}
	return (tokens);
}
