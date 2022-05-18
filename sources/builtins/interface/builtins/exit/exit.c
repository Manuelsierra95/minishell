/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:58:45 by mbarylak          #+#    #+#             */
/*   Updated: 2022/05/18 13:44:07 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(char **argv, t_shell *shell)
{
	shell->exit = 0;
	ft_putendl_fd("exit", STDERR_FILENO);
	if (argv[1] && !ft_isnum(argv[1]))
	{
		shell->ret = 2;
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(argv[1], STDERR_FILENO);
		ft_putendl_fd(": numeric argument required", STDERR_FILENO);
	}
	else if (argv[1] && argv[2])
	{
		shell->ret = 1;
		ft_putendl_fd("minishell: exit: too many arguments", STDERR_FILENO);
	}
	else if (argv[1])
		shell->ret = ft_atoi(argv[1]) % 256;
	else
		shell->ret = 0;
}
