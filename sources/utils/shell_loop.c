#include "../../includes/minishell.h"

void	shell_loop()
{
	
}

void	shell_cmds(char *inpt, char **line)
{
	if (inpt != NULL || ft_strcmp(inpt, "\n") == 0)
			line = ft_split(inpt, ' ');
	if (line[0] && ft_strcmp(line[0], "pwd") == 0)
		ft_pwd(1);
	else if (line[0] && ft_strcmp(line[0], "exit") == 0)
		ft_exit(line);
	else if (line[0] && ft_strcmp(line[0], "env") == 0)
		ft_env(g_shell->env, 1);
	else if (line[0] && ft_strcmp(line[0], "echo") == 0)
		ft_echo(1, line);
	else if (line[0] && ft_strcmp(line[0], "cd") == 0)
		ft_cd(line, g_shell->env);
	else if (line[0] && ft_strcmp(line[0], "export") == 0)
		ft_export(line, g_shell->env, g_shell->secret, 1);
	else if (line[0] && ft_strcmp(line[0], "secret") == 0)
		ft_env(g_shell->secret, 1);
	else if (line[0] && ft_strcmp(line[0], "unset") == 0)
		ft_unset(line);
	else
		printf("%s", inpt);
}
