#ifndef INTERFACE_H
# define INTERFACE_H

# include "./map_builder/map.h"
# include "./builtins/cd/cd.h"
# include "./builtins/echo/echo.h"
# include "./builtins/env/env.h"
# include "./builtins/exit/exit.h"
# include "./builtins/export/export.h"
# include "./builtins/pwd/pwd.h"
# include "./builtins/unset/unset.h"

// typedef struct s_interface
// {
// 	char	**arg;
// 	t_list	*env;
// 	int		fd;
// 	t_shell	*shell;
// 	t_list	*secret;
// } t_interface;

void	map_create(t_map map[]);


#endif