#include "../../includes/minishell.h"

int	sizeof_group(t_token *tokens, int i, int size)
{
	int	sizeof_group;

	sizeof_group = 0;
	while (i < size)
	{
		sizeof_group++;
		if (tokens[i].type == T_PIPE)
			break ;
		i++;
	}
	return (sizeof_group);
}

t_parser	**group_tokens(t_parser **parser, t_token *tokens, int size)
{
	int	i;
	int	index;
	int	j;

	index = 0;
	i = -1;
	j = 0;
	while (++i < size)
	{
		printf("token[%d] = %s\n", i, tokens[i].data);
		if (tokens[i].type == T_PIPE)
		{
			index++;
			j = 0;
		}
		else if (tokens[i].type == T_CMD)
		{
			printf("entra aqui\ntoken = %s\n", tokens[i].data);
			parser[index]->cmd[j++] = ft_strdup(tokens[i].data);
		}
		else
			parser[index]->n_data = ft_strdup(tokens[i].data);
		parser[index]->n_type = tokens[i].type;
	}
	return (parser);
}


void	get_data_struct()
{
	t_parser	**parser;
	int			size;

	size = g_shell->numOfPipes + 1;
	printf("size: %d\n", size);
	parser = malloc(sizeof(t_parser *) * (size + 1));
	parser = group_tokens(parser, g_shell->tokens, g_shell->numOfArgs);

	int index = -1;
	int j = 0;
	while (parser[++index])
	{
		j = -1;
		while (parser[index]->cmd[++j])
			printf("CMD[%d]: %s\n", j, parser[index]->cmd[j]);
		printf("data[%d]: %s\n", index, parser[index]->n_data);
		printf("type[%d]: %d\n", index, parser[index]->n_type);
	}
}