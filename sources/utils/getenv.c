#include "minishell.h"

char	*ft_getenv(char *arg, t_list *env)
{
	char	*s;
	t_list	*aux;

	aux = env;
	while (aux->next)
	{
		if (ft_strncmp(aux->content, arg, ft_strlen(arg)) == 0)
		{
			s = ft_strdup(aux->content);
			break ;
		}
		aux = aux->next;
	}
	if (!s)
		return (NULL);
	else
		return (ft_strchr(s, '/'));
}

t_list	*until_name(char *name, t_list *env)
{
	t_list	*aux;
	char	*env_name;

	aux = env;
	env_name = ft_strdup("");
	while (aux && aux->next)
	{
		env_name = get_name(aux->content);
		if (ft_strcmp(name, env_name) == 0)
		{
			free(env_name);
			return (aux);
		}
		aux = aux->next;
	}
	free(env_name);
	return (NULL);
}
