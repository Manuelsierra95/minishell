#ifndef MINISHELL_H
# define MINISHELL_H

# include "./lexer.h"
# include "./parser.h"


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


typedef struct s_dataInfo
{
	int		numOfCmd;
	int		numOfPipes;
	char	*outFile;
	char	*inFile; // Implementar el GNL (Ver errores que pueda haber en los infiles)
	char	*errFile;
	char	**env;
	char	**path;


} t_dataInfo;





// Utils
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);

#endif