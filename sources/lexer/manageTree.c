// https://parzibyte.me/blog/2021/01/13/c-arbol-binario-cadenas/


#include "../../includes/minishell.h"


t_tree	*newNode(char *string) // Para cada ejecucion de una linea de comandos
{
	t_tree	*node;

    node = (t_tree *) malloc(sizeof(t_tree));
	if (!node)
		return (NULL);
    strcpy(node->string, string);
	node->left = cmd; // Hay que ir metiendo los cmds
    node->right = NULL;
    return node;
}

void	addCmd(t_tree *node, t_dataInfo data, char *string)
{
    if (data->numOfPipes > 0)
    {
        if (node->right == NULL)
        {
            node->right = newNode(string);
        }
        else
        {
            addCmd(node->right, string); // Recursividad si esta ocupado el lugar para que pase al siguiente nodo
        }
    }
}

void	loopCmd(t_tree *node, t_dataInfo data, char *string)
{
	int		i;
	int		j;
	char	tok;

	i = 0;
	j = 0;
	while (string[i])
	{
		if (string[i] == '|')
		{
			tok = ft_substr(string, j, i);
			addCmd(node, data, tok);
			j = i + 1;
		}
		i++;
	}
}
