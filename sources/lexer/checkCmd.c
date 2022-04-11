#include "../../includes/minishell.h"

int	check_cmd(char *input)
{
	int flag;

	flag = access(input, X_OK);
	if (flag == 0)
		return (1);
	// else
	// 	// Error
	return (0);
}

int	check_access(t_dataCmd *data, char *input)
{
	int		flag;
	int		i;
	char	*cmd;

	i = 0;
	if (ft_strchr(input, '/'))
	{
		if (check_cmd(input))
		{
			data->cmd = input;
			return (1);
		}
	}
	while (data->path[i] && data->env != NULL)
	{
		cmd = ft_strjoin(data->path[i], input);
		flag = access(cmd, X_OK);
		if (flag == 0)
		{
			data->cmd = cmd;
			return (1);
		}
		i++;
	}
	// if (flag == -1)
	// 	// Error
	return (0);
}
