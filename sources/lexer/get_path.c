#include "../../includes/minishell.h"

void	join_path()
{
	int		i;

	i = 0;
	while (g_shell->path[i])
	{
		g_shell->path[i] = ft_strjoin(g_shell->path[i], "/");
		i++;
	}
}

void	split_path()
{
	int		x;

	x = 0;
	while (g_shell->envv[x])
	{
		if (ft_strncmp(g_shell->envv[x], "PATH", 4) == 0)
		{
			g_shell->path = ft_split(ft_strchr(g_shell->envv[x], '/'), ':');
		}
		x++;
	}
}

void	get_path(char **env) // Cambiar por la ENV de Miguel
{
	if (env[0] != NULL)
	{
		g_shell->envv = env;
		split_path();
		join_path();
	}
}
