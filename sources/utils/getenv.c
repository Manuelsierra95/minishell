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

char	*get_name(char *arg)
{
	char	*name;
	int		i;

	i = 0;
	name = malloc(ft_strlen(arg));
	while (arg[i] && arg[i] != '=')
	{
		name[i] = arg[i];
		i++;
	}
	name[i] = '\0';
}

int	name_in_env(char *arg, t_list *env)
{
	int		i;
	char	*name;
	t_list	*aux;

	i = 0;
	name = get_name(arg);
	aux = env;
	while (aux && aux->next)
	{
		i++;
		if (ft_strncmp(name, aux->content, ft_strlen(name)) == 0)
		{	
			free(name);
			return (i);
		}
		aux = aux->next;
	}
	free(name);
	return (0);
}

int	value_in_env(char *arg, t_list *env)
{
	char	*value;
	int		i;
	int		n;

	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	if (arg[i + 1])
		value = ft_strdup(&arg[i]);
	value = ft_strdup("");
	n = name_in_env(arg, env);
	while (n > 0 && aux)
	{
		n--;
		aux = aux->next;
	}
}
