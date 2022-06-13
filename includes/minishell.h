/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:00:27 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/08 13:10:22 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "lexer.h"
# include "parser.h"
# include "error.h"
# include "builtins.h"
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

# define CYAN	"\033[36m"
# define RESET	"\033[0m"

typedef struct s_shell
{
	t_list	*secret;
	t_list	*env;
	int		exit;
	int		ret;
	int		exit_stat;
	t_map	map[NUM_OF_ELEMENTS];
	char	**arg;

	int		fd[2];
	int		oldfd[2]; // De momento vale 1

	char			**path;
	t_token			*tokens;
	int				numOfArgs;
	int				numOfPipes;
	int				index;
	t_tree			*tree;
}	t_shell;

t_shell *g_shell;

/* UTILS */

void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_isnum(const char *s);
char	*ft_getenv(char *arg, t_list *env);
int		env_to_shell(char **env_arr);
int		secret_to_shell(char **env_arr);
int		arr_len(char **arr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
char	**ft_split(const char *s, char c);
int		ft_isalpha_edit(int c);
void	*shell_cmds(char **cmd);
void	shell_loop();
void	print_env(char **env);
void	print_list(t_list *env);

/* FREE TOOLS */

void	free_arr(char **arr);
void	free_env(t_list *env);

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

/*	EXECUTOR */

int		exe_cmd(char **argv, t_shell *shell);
int		exe_single_child(t_tree *tree, int fd);
int		exe_child(char **cmd, t_shell *shell, int fd);
int		exe_pipes(t_tree *tree);
int		exec(t_tree *tree, t_shell *shell);
int		is_builtin(char *cmd);
int		exec_builtin(char **cmd, t_shell *shell, int fd);
void	add_cmds(char *cmd);

/* EXPANDER */

t_token	*expander(t_token *tokens);
char	*exp_getenv(char *arg, t_list *env);


#endif
