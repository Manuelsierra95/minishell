#ifndef UNSET_H
# define UNSET_H

# include "./libft.h"
# include "./minishell.h"

typedef struct s_unset
{
	char	**arg;
} t_unset;

void	get_unset();
int		ft_unset(void *b_struct);

#endif