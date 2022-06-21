/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:01:12 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/21 16:27:11 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "echo.h"

void	*ft_echo(void *b_struct)
{
	int		i;
	int		flag;
	t_echo	*echo;

	echo = (t_echo *)b_struct;
	i = 1;
	flag = 0;
	if (echo->arg[i] && (ft_strncmp(echo->arg[i], "-n", 2) == 0))
	{
		flag = 1;
		i++;
	}
	while (echo->arg[i])
	{
		ft_putstr_fd(echo->arg[i], 1);
		if (echo->arg[i + 1] && echo->arg[i] != NULL)
			write(echo->fd, " ", 1);
		i++;
	}
	if (flag == 0)
		write(1, "\n", 1);
	if (g_shell->numOfPipes != 0)
		exit(0);
	return (0);
}
