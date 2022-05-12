/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:12:54 by mbarylak          #+#    #+#             */
/*   Updated: 2022/05/12 19:21:13 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_builtin	init_builtins(void)
{
	t_builtin	b_arr[7];

	b_arr[0].builtin = ft_strdup("pwd");
	b_arr[0].f = &ft_pwd;
	b_arr[1].builtin = ft_strdup("exit");
	b_arr[1].f = &ft_exit;
	b_arr[2].builtin = ft_strdup("env");
	b_arr[2].f = &ft_env;
	b_arr[3].builtin = ft_strdup("echo");
	b_arr[3].f = &ft_echo;
	b_arr[4].builtin = ft_strdup("cd");
	b_arr[4].f = &ft_cd;
	b_arr[5].builtin = ft_strdup("export");
	b_arr[5].f = &ft_export;
	b_arr[6].builtin = ft_strdup("unset");
	b_arr[6].f = &ft_unset;
	return (b_arr);
}

int	exec_builtin(char **cmd, t_shell *shell, int fd)
{
	t_builtin	b_arr[7];
	int			ret;
	int			i;

	b_arr = init_builtin();
	i = 0;
	while (i < 7)
		if (ft_strcmp(cmd[0], b_arr[i].builtin) == 0)
			b_arr[i].f;
}
