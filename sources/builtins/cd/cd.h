#ifndef CD_H
# define CD_H

# include "libft.h"
# include "minishell.h"

typedef struct s_cd
{
	char	**arg;
}	t_cd;

void	*get_cd();
void	*ft_cd(void *b_struct);

#endif
