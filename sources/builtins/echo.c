/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:01:12 by mbarylak          #+#    #+#             */
/*   Updated: 2022/05/17 16:37:03 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(int fd, char **arg)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (arg[i] && (ft_strncmp(arg[i], "-n", 2) == 0))
	{
		flag = 1;
		i++;
	}
	while (arg[i])
	{
		ft_putstr_fd(arg[i], fd);
		if (arg[i + 1] && arg[i] != NULL)
			write(fd, " ", 1);
		i++;
	}
	if (flag == 0)
		write(fd, "\n", 1);
	return (0);
}