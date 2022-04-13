/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:00:27 by mbarylak          #+#    #+#             */
/*   Updated: 2022/04/11 18:11:48 by mbarylak         ###   ########.fr       */
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

typedef struct s_env   /* Estructura del entorno */
{
	char			*content;
	struct s_env	*next;
}	t_env;

typedef struct s_shell
{
	char			**path;
	char			**envv;
	t_token			*tokens;
	int				numOfArgs;
	int				l_quote_len;
	int				r_quote_len;

	int				numOfCmd;
	int				numOfPipes;
	char			*outFile;
	char			*inFile; // Implementar el GNL (Ver errores que pueda haber en los infiles)
	char			*errFile;
	struct s_env	*env;
	int				exit;
	int				ret;
}	t_shell;

/* UTILS */

void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *s);
int		ft_isnum(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
char	**ft_split(const char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
int		ft_isalpha_edit(int c);

/* BUILTIN  */

int		ft_pwd(void);
void	ft_exit(char **argv, t_shell *shell);
int		env_to_shell(char **arg, t_shell *shell); /* Pasa entorno de char ** a t_env */
int		ft_env(t_env *env);
int		ft_echo(char **arg);
int		ft_cd(char **arg, t_env *env);

/* LEXER */

void	get_path(t_shell *data, char **env);
t_token	*lexer(t_shell *dataCmd, int args, char **input);
int		check_access(t_shell *data, char *input);

#endif
