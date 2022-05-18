#ifndef EXPORT_H
# define EXPORT_H

# include "./libft.h"
# include "./minishell.h"

typedef struct s_export
{
	char	**arg;
	t_list	*env;
	t_list	*secret;
	int		fd;
} t_export;

int	ft_export(char **arg, t_list *env, t_list *secret, int fd);
void	get_export();

#endif