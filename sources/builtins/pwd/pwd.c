/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:58:29 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/20 10:10:22 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pwd.h"
#include "minishell.h"

void	*ft_pwd(void *b_struct)
{
	char	buf[2048];
	t_pwd	*pwd;

	pwd = (t_pwd *)b_struct;
	pwd->fd = pwd->fd;
	if (getcwd(buf, 2048))
	{
		ft_putendl_fd(buf, 1);
		if (g_shell->numOfPipes != 0)
			exit(0);
		return (0);
	}
	return ((int *)1);
}
