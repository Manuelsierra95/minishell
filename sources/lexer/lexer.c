#include "../../includes/minishell.h"

t_token	token_word(t_dataCmd *dataCmd, char *input, char *last_data)
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

	printf("Type: %d\n", type);
	new.data = NULL;
	new.type = type;
	return (new);
}


t_token	new_token(t_dataCmd *dataCmd, char *input, char *last_data)
{
	int 	i;
	int 	j;
	t_token	new;

	i = -1;
	while (input[++i])
	{
		if (input[i] == ' ')
			i++;
		else if (ft_isalpha_edit(input[i]))
		{
			j = i;
			while (ft_isalpha_edit(input[i]) || input[i] == ' ')
				i++;
			printf("input: %s\n", ft_substr(input, j, i));
			new = (token_word(dataCmd, ft_substr(input, j, i--), last_data));
		}
		else if (ft_isspecial(input[i], 0))
		{
			printf("input: %c\n", input[i]);
			if (input[i + 1])
				new = (token_no_word(ft_isspecial(input[i], input[i + 1])));
			else
				new = (token_no_word(ft_isspecial(input[i], 0)));
		}
	}
	return (new);
}

t_token	*lexer(t_dataCmd *dataCmd, int argc, char **argv)
{
	int		i;
	int		index;
	char	*last_data;
	t_token	*token;

	token = malloc(sizeof(t_token));
	i = 1;
	index = 0;
	while (i < argc)
	{
		if (token[index - 1].data && token[index - 1].type == 1)
			last_data = token[index - 1].data;
		else
			last_data = NULL;
		token[index] = new_token(dataCmd, argv[i], last_data);
		index++;
		i++;
	}
	dataCmd->numOfArgs = index;
	return (token);
}
/*
int main(int argc, char **argv, char **env)
{
	int i = 1;
	t_token 	*tokens;
	t_dataInfo	*dataInfo;
	t_dataCmd	*dataCmd;

	dataInfo = malloc(sizeof(t_dataInfo));
	dataCmd = malloc(sizeof(t_dataCmd));

	get_path(dataInfo, env);

	dataCmd->env = dataInfo->env;
	dataCmd->path = dataInfo->path;
	tokens = lexer(dataCmd, argc, argv);
	dataInfo->tokens = tokens;

	int index = 0;
	while (index < dataCmd->numOfArgs)
	{
		// printf("Index: %d\tType: %d\tData: %s\n", index, tokens[index].type, tokens[index].data);
		//printf("POINTER %p\n", dataInfo->tokens);
		printf("Index: %d\tType: %d\n", index, dataInfo->tokens[index].type);
		index++;
	}
	

	// while (aux)
	// {
	// 	printf("Type: %d\tData: %s\n", aux->type, aux->data);
	// 	aux = aux->next;
	// }

}*/
