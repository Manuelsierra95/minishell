#include "../../includes/minishell.h"


t_tree	*newNode(char *string) // Para cada ejecucion de una linea de comandos
{
	t_tree	*node;

    node = (t_tree *) malloc(sizeof(t_tree));
	if (!node)
		return (NULL);
	node->cmd = string;
	node->left = NULL; // Hay que ir metiendo los cmds
    node->right = NULL;
    return node;
}

void	addCmd(t_tree *node, t_dataInfo data, char *string)
{
    if (data->numOfPipes) // Si existen pipes, ramificamos la derecha y metemos los cmd en la izquierda
    {
        if (node->right == NULL)
        {
            node->right = newNode(string);
        }
        else
        {
            addCmd(node->right, string); // Recursividad si esta ocupado el lugar para que pase al siguiente nodo
        }
		data->numOfPipes--;
    }
	else
	{
		// Si no existen pipes, directamente se ejecuta
	}
}

void	loopCmd(char *argv, t_tree *node, t_dataInfo *data)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (!argv)
		errormsg(-1);
	while (argv[i])
	{
		if (argv[i] >= 'a' && argv[i] <= 'z')
		{
			flag = 1;
			break ;
		}
		i++;
	}
	if (flag == 0)
		errormsg(-1);
	addCmd(node, data, ft_split(argv, ' '));
}
