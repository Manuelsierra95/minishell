#include "minishell.h"

t_shell	*init_shell(char **env)
{
	t_shell	*shell;

	shell = malloc(sizeof (t_shell));
	shell->exit = 1;
	shell->ret = 0;
	shell->env = get_env(env);
	return (shell);
}

void	print_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}

int	main(int argc, char **argv, char **env)
{
	char	*inpt;
	char	**line;
	t_shell	*shell;

	(void) argc;
	(void) argv;
	shell = init_shell(env);
	while (shell->exit == 1)
	{
		inpt = readline("minishell> ");
		line = ft_split(inpt, ' ');
		if (ft_strncmp(line[0], "pwd", 3) == 0)
			ft_pwd();
		else if (ft_strncmp(line[0], "exit", 4) == 0)
			ft_exit(line, shell);
		else if (ft_strncmp(line[0], "env", 3) == 0)
			ft_env(shell->env);
		else
			printf("%s\n", inpt);
	}
	return (shell->ret);
}
