#ifndef EXPORT_H
# define EXPORT_H

# include "libft.h"
# include "minishell.h"

typedef struct s_export
{
	char	**arg;
	t_list	*env;
	t_list	*secret;
	int		fd;
} t_export;

void	*ft_export(void *b_struct);
void	*get_export();

#endif