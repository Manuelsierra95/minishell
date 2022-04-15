/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:00:27 by mbarylak          #+#    #+#             */
/*   Updated: 2022/04/13 18:12:25 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./lexer.h"
# include "./parser.h"
# include "libft.h"


# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <readline/history.h>
# include <limits.h>

typedef struct s_shell
{
	t_list	*secret;
	t_list	*env;
	char	**envv;
	int		exit;
	int		ret;
	int		exit_stat;
}	t_shell;

t_shell	*g_shell;

/* UTILS */

int		ft_isnum(const char *s);
char	*ft_getenv(char *arg, t_list *env);

/* BUILTIN  */

int		ft_pwd(void);
void	ft_exit(char **argv, t_shell *shell);
int		env_to_shell(char **arg, t_shell *shell); /* Pasa entorno de char ** a t_env */
int		ft_env(t_list *env);
int		ft_echo(int fd, char **arg);
int		ft_cd(char **arg, t_list *env);

#endif
