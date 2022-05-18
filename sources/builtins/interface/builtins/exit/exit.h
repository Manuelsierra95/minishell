#ifndef EXIT_H
# define EXIT_H

# include "./libft.h"
# include "./minishell.h"

typedef struct s_exit
{
	char	**arg;
	t_shell	*shell;
} t_exit;

void	get_exit();
void	ft_exit(char **argv, t_shell *shell);

#endif