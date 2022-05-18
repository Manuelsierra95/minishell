#ifndef PWD_H
# define PWD_H

# include "./libft.h"
# include "./minishell.h"

typedef struct s_pwd
{
	int	fd;
} t_pwd;

int		ft_pwd(int fd);
void	get_pwd();

#endif