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

	printf("input1: %c\tinput2: %d\n", input1, input2);
	if (input2 != 0)
		new = (token_no_word(d_isspecial(input1, input2)));
	else
		new = (token_no_word(s_isspecial(input1)));
	return (new);
}

t_token	new_token(t_shell *dataCmd, char *input, char *last_data)
{
	int 	i;
	t_token	new;

	i = -1;
	while (input[++i])
	{
		// printf("Input[%d]: %c\n", i, input[i]);
		if (ft_isalpha_edit(input[i]))
		{
			new = (token_word(dataCmd, input, last_data));
			break ;
		}
		else if (s_isspecial(input[i]))
		{
			// printf("%c\t%c\n", input[i], input[i + 1]);
			new = token_finder(input[i], input[i + 1]);
		}
	}
	// printf("Antes /// Type: %d\tData: %s\n", new.type, new.data);
	return (new);
}

t_token	*lexer(t_shell *dataCmd, int args, char **input)
{
	int		i;
	int		index;
	char	*aux_input;
	char	*last_data;
	t_token	*token;

	token = malloc(sizeof(t_token));
	i = 0;
	index = 0;
	printf("num of args: %d\n", args);
	while (i < args)
	{
		if (token[index - 1].data && token[index - 1].type == 1)
			last_data = token[index - 1].data;
		else
			last_data = NULL;
		if (check_quotes(input[i]) == 1)
			aux_input = take_off_quotes(input[i]);
		else
			aux_input = input[i];
		printf("input antes: %s\n", aux_input);
		token[index++] = new_token(dataCmd, aux_input, last_data);
		// printf("Index: %d\tType: %d\tData: %s\n", index, token[index - 1].type, token[index - 1].data);
		i++;
	}
	dataCmd->numOfArgs = index;
	return (token);
}
