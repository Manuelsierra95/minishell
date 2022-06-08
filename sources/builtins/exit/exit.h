#ifndef EXIT_H
# define EXIT_H

# include "libft.h"
# include "minishell.h"

typedef struct s_exit
{
	char	**arg;
} t_exit;

void	*get_exit();
void	*ft_exit(void *b_struct);

#endif