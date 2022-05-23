/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:58:29 by mbarylak          #+#    #+#             */
/*   Updated: 2022/05/23 19:00:52 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(int fd, t_shell *shell)
{
	char	buf[PATH_MAX];

	if (getcwd(buf, PATH_MAX))
	{
		ft_putendl_fd(buf, fd);
		if (shell->pipes != 0)
			exit(0);
		return (0);
	}
	return (1);
}
