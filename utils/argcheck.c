#include "pipex.h"

void	util_argcheck(int argc, char **argv)
{
	int	i;

	if (argc != 5)
		print_usage_and_exit();
	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
		{
			print_strerror("Error: empty argument\n", 24);
			print_usage_and_exit();
		}
		i++;
	}
}
