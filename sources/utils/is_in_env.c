#include "minishell.h"

int	is_in_env(char *arg, int ret, t_list *env, t_list *secret)
{
	char	*name;
	t_list	*first;

	name = get_name(arg);
	first = env;
	if (ret == 1 && name_in_env(name, env))
	{
		env = until_name(name, env);
		free(env->content);
		env->content = ft_strdup(arg);
		free(name);
		env = first;
		return (1);
	}
	else if (ret == 0 && name_in_env(name, secret))
	{	
		free(name);
		return (1);
	}
	return (0);
}

char	*get_name(char *arg)
{
	char	*name;
	int		i;

	i = 0;
	name = malloc(ft_strlen(arg));
	if (!name)
		return (NULL);
	while (arg[i] && arg[i] != '=')
	{
		name[i] = arg[i];
		i++;
	}
	name[i] = '\0';
	return (name);
}

int	name_in_env(char *name, t_list *env)
{
	char	*env_name;
	t_list	*aux;

	env_name = ft_strdup("");
	aux = env;
	while (aux && aux->next)
	{
		env_name = get_name(aux->content);
		if (ft_strcmp(name, env_name) == 0)
		{
			free(env_name);
			return (1);
		}
		aux = aux->next;
	}
	free(env_name);
	return (0);
}
