#ifndef MINISHELL_H
# define MINISHELL_H


typedef struct s_cmd
{
	char			*cmd[2]; // Si solo hay 1 cmd el 2 es NULL (hay que rellenarlo);
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
	char	**env; // Si nos la borran la guardamos en la data
	char	**path;


} t_dataInfo;








#endif