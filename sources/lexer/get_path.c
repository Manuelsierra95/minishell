#include "minishell.h"

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
	t_list	*aux;

	aux = g_shell->env;
	while (aux)
	{
		if (ft_strncmp(aux->content, "PATH", 4) == 0)
		{
			g_shell->path = ft_split(ft_strchr(aux->content, '/'), ':');
		}
		aux = aux->next;
	}
}

void	get_path(void) // Cambiar por la ENV de Miguel
{
	if (g_shell->env->content != NULL)
	{
		split_path();
		join_path();
	}
}
