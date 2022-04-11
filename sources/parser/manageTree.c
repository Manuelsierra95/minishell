// https://parzibyte.me/blog/2021/01/13/c-arbol-binario-cadenas/
// https://github.com/JAS0NHUANG/MiniShell

#include "../../includes/minishell.h"


t_tree	*newNode(char *data, int type) // Para cada ejecucion de una linea de comandos
{
	t_tree	*node;

    node = (t_tree *) malloc(sizeof(t_tree));
	if (!node)
		return (NULL);
	node->node;
	node->right = NULL; // Hay que ir metiendo los cmds
    node->left = NULL;
    return node;
}

void	addCmd(t_tree *node, t_dataInfo data, char *str1, char *str2)
{
    if (data->numOfPipes) // Si existen pipes, ramificamos la derecha y metemos los cmd en la izquierda
    {
        if (node->left == NULL)
			node->left = newNode(str1, str2);
        else
            addCmd(node->left, data, str1, str2); // Recursividad si esta ocupado el lugar para que pase al siguiente nodo
		data->numOfPipes--;
    }
	else
	{
		if (node->right == NULL)
			node->right = newNode(str1, str2);
		else
   			 addCmd(node->right, data, str1, str2);
	}
}

void	loopCmd(t_tree *node, t_dataInfo data, char *str) // O metemos un loop o lo hacemos todo en el arbol
{
	int		i;
	int		j;

	i = ft_strlen(str);
	j = ft_strlen(str);
	while (str[i])
	{
		if (str[i] == '|')
		{
			addCmd(node, data, ft_substr(str, j, i), NULL);
			j = i;
		}
		i--;
	}
	j = i;
	while (str[i])
	{
		if (str[i] == " ")
			addCmd(node, data, ft_substr(str, j, i), ft_substr(str, 0, i));
		i--;
	}
}

int	main(int argc, char **argv)
{
	// t_tree		*node;
	// t_dataInfo	*data;

	// loopCmd(node, data, str);

}
