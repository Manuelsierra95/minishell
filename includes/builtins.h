#ifndef MINISHELL_H
# define MINISHELL_H

int		ft_pwd(void);
void	ft_exit(char **argv, t_shell *shell);
t_env	*env_to_lst(char **arg); /* Pasa entorno de char ** a t_env */
int		ft_env(t_env *env);

# endif
