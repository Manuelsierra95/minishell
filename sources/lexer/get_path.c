#include "../../includes/minishell.h"

void	join_path(t_dataInfo *data)
{
	int		i;

	i = 0;
	while (data->path[i])
	{
		data->path[i] = ft_strjoin(data->path[i], "/");
		i++;
	}
}

void	split_path(t_dataInfo *data)
{
	int		x;

	x = 0;
	while (data->env[x])
	{
		if (ft_strncmp(data->env[x], "PATH", 4) == 0)
		{
			data->path = ft_split(ft_strchr(data->env[x], '/'), ':');
		}
		x++;
	}
}

void	get_path(t_dataInfo *data, char **env)
{
	if (env[0] != NULL)
	{
		data->env = env;
		split_path(data);
		join_path(data);
	}
}