#include "pipex.h"

char	*util_getenv(char **env, const char *name)
{
	const char	*count_pointer;
	char		**p;
	char		*envptr;
	int			len;

	count_pointer = name;
	while (*count_pointer && *count_pointer != '=')
		count_pointer++;
	len = count_pointer - name;
	p = env;
	while ((envptr = *p) != NULL)
	{
		if (ft_strncmp(envptr, name, len) == 0 && envptr[len] == '=')
			return (ft_strdup(envptr + len + 1));
		p++;
	}
	return (NULL);
}
