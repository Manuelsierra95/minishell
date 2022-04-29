#include "../../includes/minishell.h"

void	mng_errors(int flag, char *data)
{
	if (flag == 1)
	{
		printf("bash: %s command not found", data);
	}
}

int	check_for_errors(t_token *tokens)
{
	int	index;
	int	size;
	int	flag;

	flag = 0;
	index = 0;
	size = g_shell->numOfArgs;
	while (index < size && flag == 0)
	{
		if (tokens[0].type != T_CMD)
			flag = 1;
		index++;
	}
	if (flag == 1)
			mng_errors(1, tokens[0].data);
	return (flag);
}
