#ifndef ECHO_H
# define ECHO_H

# include "libft.h"
# include "minishell.h"

typedef struct s_echo
{
	int		fd;
	char	**arg;
}	t_echo;

void	*ft_echo(void *b_struct);
void	*get_echo();

#endif
