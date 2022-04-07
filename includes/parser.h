#ifndef PARSER_H
# define PARSER_H


typedef struct s_tree
{
	char			*cmd; // todo el string de info
	struct s_tree	*left; // aqui ira la info del comando
	struct s_tree	*right; // aqui iran los pipes y se ira ramificando en funcion del numOfPipes
} t_tree;

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
	t_cmd			*cmd;
	// Control de argumentos separados
} t_dataCmd;

#endif