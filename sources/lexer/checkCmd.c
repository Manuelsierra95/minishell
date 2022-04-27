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

int	check_access(char *input)
{
	int		flag;
	int		i;
	char	*cmd;

	i = 0;
	if (ft_strchr(input, '/'))
	{
		if (check_cmd(input))
		{
			return (1);
		}
	}
	while (g_shell->path[i] && g_shell->envv != NULL)
	{
		cmd = ft_strjoin(g_shell->path[i], input);
		flag = check_cmd(cmd);
		if (flag == 1)
		{
			return (1);
		}
		i++;
	}
	// if (flag == -1)
	// 	// Error
	return (0);
}
