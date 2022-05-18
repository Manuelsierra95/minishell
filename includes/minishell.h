/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:00:27 by mbarylak          #+#    #+#             */
/*   Updated: 2022/05/18 12:02:09 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./lexer.h"
# include "./parser.h"
# include "./error.h"
# include "./builtins.h"
# include "./libft.h"

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

# define CYAN	"\033[36m"
# define RESET	"\033[0m"

typedef struct s_shell
{
	t_list	*secret;
	t_list	*env;
	int		exit;
	int		ret;
	int		exit_stat;
	// t_map	*map;

	char			**path;
	t_token			*tokens;
	int				numOfArgs;
	int				numOfPipes;
	int				index;
	t_tree			*tree;
}	t_shell;

typedef struct	s_builtin
{
	char	*builtin;
	int		(*f)();
}	t_builtin;

t_shell	*g_shell;


// typedef struct s_env   /* Estructura del entorno */
// {
// 	char			*content;
// 	struct s_env	*next;
// }	t_env;

// typedef struct s_shell
// {
	

// 	int				numOfCmd;
// 	int				numOfPipes;
// 	char			*outFile;
// 	char			*inFile; // Implementar el GNL (Ver errores que pueda haber en los infiles)
// 	char			*errFile;
// 	struct s_env	*env;
// 	int				exit;
// 	int				ret;
// }	t_shell;

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
void	shell_cmds(char *inpt, char **line);
void	shell_loop();

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
char	*env_2_str(t_list *env);
char	**env_2_arr(t_list *env);
void	sort_env(char **env_arr, int env_len);
int		print_secret(t_list *secret, int fd);

/*  BUILTINS  */

int		ft_cd(char **arg, t_list *env);
int		ft_echo(int fd, char **arg);
int		ft_env(t_list *env, int fd);
void	ft_exit(char **argv, t_shell *shell);
int		ft_export(char **arg, t_list *env, t_list *secret, int fd);
int		ft_pwd(int fd);
int		ft_unset(char **arg);

/*	EXECUTOR */

int		exe_cmd(char **argv, t_shell *shell);
int		exe_child(char **cmd, t_shell *shell);

/* EXPANDER */

t_token	*expander(t_token *tokens);
char	*exp_getenv(char *arg, t_list *env);

/* ERROR */

int	check_for_errors(t_token *tokens);


#endif
