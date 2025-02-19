#ifndef MINISHELL_H
# define MINISHELL_H

# include "utils.h"

# include "libft.h"
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_shell
{
	char	**env;
	int		exit;
}	t_shell;

t_shell *g_shell;


#endif
