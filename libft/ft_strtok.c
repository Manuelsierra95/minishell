# include "libft.h"

char *ft_strtok(char *str, const char *delim) {
    static char *next = NULL;

    if (str)
      next = str;
    if (!next || *next == '\0')
      return NULL;

    char *start = next;

    while (*start && ft_strchr(delim, *start))
      start++;
    if (*start == '\0') {
      next = NULL;
    	return NULL;
    }

    char *end = start;

    while (*end && !ft_strchr(delim, *end))
      end++;

    if (*end) {
    	*end = '\0';
      next = end + 1;
    } else
      next = NULL;

    return start;
}