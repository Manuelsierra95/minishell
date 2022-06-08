#ifndef INTERFACE_H
# define INTERFACE_H

# include "map.h"
# include "cd.h"
# include "echo.h"
# include "env.h"
# include "exit.h"
# include "export.h"
# include "pwd.h"
# include "unset.h"

// typedef struct s_interface
// {
// 	char	**arg;
// 	t_list	*env;
// 	int		fd;
// 	t_shell	*shell;
// 	t_list	*secret;
// } t_interface;

void	put_builtins(t_map map[]);


#endif