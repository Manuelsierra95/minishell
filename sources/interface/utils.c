#include "interface.h"

void	put_builtins(t_map map[])
{
	put(map, "cd", ft_cd, get_cd);
	put(map, "echo", ft_echo, get_echo);
	put(map, "env", ft_env, get_env);
	put(map, "exit", ft_exit, get_exit);
	put(map, "export", ft_export, get_export);
	put(map, "pwd", ft_pwd, get_pwd);
	put(map, "unset", ft_unset, get_unset);
}
