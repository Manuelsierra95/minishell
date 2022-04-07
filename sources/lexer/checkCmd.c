#include "../../includes/minishell.h"

int	check_cmd(char *input)
{
	int i;

	i = access(input, X_OK);
	return (i);
}

// char	*checkAccess(t_dataInfo *data)
// {
// 	int		flag;
// 	int		i;
// 	char	*path;

// 	i = 0;
// 	if (ft_strchr(data->cmd[0], '/'))
// 	{
// 		if (checkCmd(data))
// 		{
// 			path = data->cmd[0];
// 			return (path);
// 		}
// 	}
// 	while (data->path[i] && data->env != NULL)
// 	{
// 		path = ft_strjoin(data->path[i], data->cmd[0]);
// 		flag = access(path, X_OK);
// 		if (flag == 0)
// 			return (path);
// 		i++;
// 	}
// 	if (flag == -1)
// 		ft_errormsg(flag);
// 	return (0);
// }
