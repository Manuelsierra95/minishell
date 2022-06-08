#ifndef PWD_H
# define PWD_H

# include "libft.h"

typedef struct s_pwd
{
	int	fd;
} t_pwd;

void	*ft_pwd(void *b_struct);
void	*get_pwd();

#endif