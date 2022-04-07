#include "../../includes/minishell.h"

t_token	token_word(char *input)
{
	t_token	new;

	if (check_cmd(input) == 1)
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


t_token	new_token(char *input)
{
	int 	i;
	int 	j;
	t_token	new;

	i = -1;
	// printf("input: %s\tsize: %zu\n", input, ft_strlen(input));
	while (input[++i])
	{
		printf("input: %c\n\n", input[i]);
		if (input[i] == ' ')
			i++;
		else if (ft_isalpha(input[i]) || input[i] == '"')
		{
			j = i;
			while (ft_isalpha(input[i]) || input[i] == ' ')
				i++;
			new = (token_word(ft_substr(input, j, i)));
			i = i - 1;
		}
		else if (ft_isspecial(input[i], 0))
		{
			if (input[i + 1])
				new = (token_no_word(ft_isspecial(input[i], input[i + 1])));
			else
				new = (token_no_word(ft_isspecial(input[i], 0)));
		}
		// printf("Data: %s\n", token[index].data);
	}
	printf("new: %s\n", new.data);
	return (new);
}

t_token	*lexer(int argc, char **argv)
{
	int		i;
	int		index;
	t_token	*token;

	i = 1;
	index = 0;
	while (i < argc)
	{
		printf("Uno\n");
		token[index] = new_token(argv[i]);
		write(1, "Dos\n", 4);
		printf("token: %s\n", token[index].data);
		index++;
		i++;
	}
	return (token);
}

int main(int argc, char **argv)
{
	int i = 1;
	t_token *aux;

	aux = lexer(argc, argv);
	int index = 0;
	while (index < 2)
	{
		printf("Index: %d\tType: %d\tData: %s\n", index, aux[index].type, aux[index].data);
		index++;
	}

	// while (aux)
	// {
	// 	printf("Type: %d\tData: %s\n", aux->type, aux->data);
	// 	aux = aux->next;
	// }

}