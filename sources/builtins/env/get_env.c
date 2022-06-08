#include "env.h"

void	*get_env()
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	env->env = g_shell->env;
	env->fd = g_shell->fd;
	return (env);
}
