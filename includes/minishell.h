/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:00:27 by mbarylak          #+#    #+#             */
/*   Updated: 2022/04/18 20:36:19 by mbarylak         ###   ########.fr       */
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
int		env_to_shell(char **env_arr);
int		secret_to_shell(char **env_arr);
int		arr_len(char **arr);

/* FREE TOOLS */

void	free_arr(char **arr);
void	free_env(t_list *env);

/*  BUILTINS TOOLS  */

t_list	*until_name(char *name, t_list *env);
char	*get_name(char *arg);
int		name_in_env(char *name, t_list *env);
int		is_valid(char *arg);
int		add_2_env(char *arg, t_list *env);
int		is_in_env(char *arg, int ret, t_list *env);
char	*env_2_str(t_list *env);
void	sort_env(char **env_arr, int env_len);
int		print_secret(t_list *secret, int fd);

/*  BUILTINS  */

int		ft_pwd(int fd);
void	ft_exit(char **argv);
int		ft_env(t_list *env);
int		ft_echo(int fd, char **arg);
int		ft_cd(char **arg, t_list *env);
int		ft_export(char **arg, t_list *env, t_list *secret, int fd);

#endif
