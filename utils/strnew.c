#include "pipex.h"

char	*util_strnew(size_t size)
{
	char	*str;

	str = (char *) malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	ft_memset(str, 0, size + 1);
	return (str);
}
