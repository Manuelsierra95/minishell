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

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "readline/history.h"
# include "readline/readline.h"

typedef struct s_tree
{
	char			*string; // todo el string de info
	struct s_tree	*left; // aqui ira la info del comando
	struct s_tree	*right; // aqui iran los pipes y se ira ramificando en funcion del numOfPipes
} t_tree;

typedef struct s_env   /* Estructura del entorno */
{
	char			*content;
	struct s_env	*next;
}	t_env;


// Sacamos todos los argumentos y los separamos en comandos simples
typedef struct s_dataCmd
{
	int				numOfAvArgs; 
	int				numOfArgs;
	char			**args;
	struct	s_cmd	*cmd;
	// Control de argumentos separados
} t_dataCmd;

typedef struct s_shell
{
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

/* BUILTINS */

int		ft_pwd(void);
void	ft_exit(char **argv, t_shell *shell);
t_env	*env_to_lst(char **arg); /* Pasa entorno de char ** a t_env */
int		ft_env(t_env *env);

#endif
