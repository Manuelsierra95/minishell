#ifndef ENV_H
# define ENV_H

# include "./libft.h"
# include "./minishell.h"

typedef struct s_env
{
	t_list	*env;
	int		fd;
} t_env;

int	ft_env(t_list *env, int fd);
void	get_env();

#endif