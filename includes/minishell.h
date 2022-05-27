/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:00:27 by mbarylak          #+#    #+#             */
/*   Updated: 2022/05/27 19:53:47 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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
# include <sys/errno.h>
# include <unistd.h>
# include <readline/history.h>
# include <limits.h>

typedef struct s_shell
{
	t_list	*secret;
	t_list	*env;
	int		exit;
	int		ret;
	int		pipes;
}	t_shell;

typedef struct s_cmd
{
	char			**arg;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

typedef struct s_exec
{
	t_cmd	*cmds;
	int		fd_in;
	int		fd_out;
	int		oldfd[2];
}	t_exec;

t_shell	*g_shell;

/* UTILS */

int		ft_isnum(const char *s);
char	*ft_getenv(char *arg, t_list *env);
int		env_to_shell(char **env_arr);
int		secret_to_shell(char **env_arr);
int		arr_len(char **arr);
void	print_env(char **env);
void	print_list(t_list *env);

/* FREE TOOLS */

void	free_arr(char **arr);
void	free_env(t_list *env);
void	free_cmds(t_cmd *cmd);

/*  BUILTINS TOOLS  */

t_list	*until_name(char *name, t_list *env);
char	*get_name(char *arg);
char	*get_value(char *arg);
int		name_in_env(char *name, t_list *env);
int		is_valid(char *arg);
int		add_2_env(char *arg, t_list *env);
int		is_in_env(char *arg, int ret, t_list *env);
char	**env_2_arr(t_list *env);
void	sort_env(char **env_arr, int env_len);
int		print_secret(t_shell *shell, int fd);

/*  BUILTINS  */

int		ft_pwd(int fd, t_shell *shell);
void	ft_exit(char **argv, t_shell **shell, int fd);
int		ft_env(t_shell *shell, int fd);
int		ft_echo(int fd, char **arg, t_shell *shell);
int		ft_cd(char **arg, t_shell *shell);
int		ft_export(char **arg, t_shell **shell, int fd);
int		ft_unset(char **arg, t_shell *shell);

/* MY LEXER */

void	pipe_counter(char *input, t_shell *shell);
int		has_pipes(char *input);

/*	EXECUTOR */

int		exe_cmd(char **argv, t_shell *shell);
int		exe_single_child(char **cmd, t_shell *shell, int fd);
int		exe_child(char **cmd, t_shell *shell, int fd);
int		exe_pipes(t_exec *exe, t_shell *shell);
int		exec(t_exec *exe, t_shell *shell);
int		is_builtin(char *cmd);
int		exec_builtin(char **cmd, t_shell *shell, int fd);
t_cmd	*add_cmds(char *arg, t_cmd *cmd, int i);

#endif
