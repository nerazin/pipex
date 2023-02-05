#include "pipex.h"

void	print_error_and_exit(t_pipex *pstruct, char *p)
{
	free(p);
	dstruct(pstruct);
	perror("Error");
	exit(1);
}

void	print_usage_and_exit()
{
	write(2, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 37);
	exit(1);
}

void	print_strerror(char *msg, int len)
{
	write(2, msg, len);
}
