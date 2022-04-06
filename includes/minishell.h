#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_tree
{
	char			*cmd;
	struct s_tree	*left; // aqui ira la info del comando
	struct s_tree	*right; // aqui iran los pipes y se ira ramificando en funcion del numOfPipes
} t_tree;

typedef struct s_cmd
{
	char			**cmd;
	struct s_cmd	*next;
	

} t_cmd;


// Sacamos todos los argumentos y los separamos en comandos simples
typedef struct s_dataCmd
{
	int				numOfAvArgs; 
	int				numOfArgs;
	char			**args;
	struct	s_cmd	*cmd;
	// Control de argumentos separados
} t_dataCmd;

// Cojemos todos los cmds sacados de la anterior struct y los contabilizamos en esta struct
typedef struct s_dataInfo
{
	int		numOfCmd;
	int		numOfPipes;
	char	*outFile;
	char	*inFile; // Implementar el GNL (Ver errores que pueda haber en los infiles)
	char	*errFile;
} t_dataInfo;

typedef struct s_exec
{
	struct	s_dataInfo	*dataInfo;
} t_exec;

typedef struct s_minishell
{
	char	**env;
	char	**path;
	// historial
	// dataInfo
	// exeInfo
} t_minishell;








#endif