#ifndef CD_H
# define CD_H

# include "./libft.h"
# include "./minishell.h"

typedef struct s_cd
{
	char	**arg;
	t_list	*env;
} t_cd;

void	*get_cd();
int	ft_cd(char **arg, t_list *env);


#endif