#include "../../includes/minishell.h"

void	getPath(t_dataInfo *data)
{
	int		x;

	x = 0;
	while (data->env[x])
	{
		if (ft_strncmp(data->env[x], "PATH", 4) == 0)
			data->path = ft_split(ft_strchr(data->env[x], '/'), ':');
		x++;
	}
}

void	getCmd(char *argv, t_dataInfo *data)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (!argv)
		errormsg(-1);
	while (argv[i])
	{
		if (argv[i] >= 'a' && argv[i] <= 'z')
		{
			flag = 1;
			break ;
		}
		i++;
	}
	if (flag == 0)
		errormsg(-1);
	data->cmd = ft_split(argv, ' '); // ir guardando en una struct de Cmds
}

void	joinPath(t_dataInfo *data)
{
	int		i;

	i = 0;
	while (data->path[i])
	{
		data->path[i] = ft_strjoin(data->path[i], "/");
		i++;
	}
}
