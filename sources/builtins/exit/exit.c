/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:58:45 by mbarylak          #+#    #+#             */
/*   Updated: 2022/05/22 22:25:58 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

void	*ft_exit(void *b_struct)
{
	t_exit	*exit;

	exit = (t_exit*)b_struct;
	g_shell->exit = 0;
	ft_putendl_fd("exit", STDERR_FILENO);
	if (exit->arg[1] && !ft_isnum(exit->arg[1]))
	{
		g_shell->ret = 2;
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(exit->arg[1], STDERR_FILENO);
		ft_putendl_fd(": numeric argument required", STDERR_FILENO);
	}
	else if (exit->arg[1] && exit->arg[2])
	{
		g_shell->ret = 1;
		ft_putendl_fd("minishell: exit: too many arguments", STDERR_FILENO);
	}
	else if (exit->arg[1])
		g_shell->ret = ft_atoi(exit->arg[1]) % 256;
	else
		g_shell->ret = 0;
	return (NULL);
}
