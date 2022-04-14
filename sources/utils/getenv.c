#include "minishell.h"

char	*ft_getenv(char *arg, t_list *env)
{
	char	*s;

	while (env->next)
	{
		if (ft_strncmp(env->content, s, ft_strlen(s)) == 0)
		{
			s = ft_strdup(env->content);
			break ;
		}
		env = env->next;
	}
}
