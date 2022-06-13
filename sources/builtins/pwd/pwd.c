/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:58:29 by mbarylak          #+#    #+#             */
/*   Updated: 2022/05/23 09:31:02 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pwd.h"

void	*ft_pwd(void *b_struct)
{
	char	buf[2048];
	t_pwd	*pwd;

	pwd = (t_pwd*)b_struct;
	if (getcwd(buf, 2048))
	{
		pwd->fd = 1;
		ft_putendl_fd(buf, 1);
		return (0);
	}
	return ((int*)1);
}
