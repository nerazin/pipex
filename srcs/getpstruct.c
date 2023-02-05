#include "pipex.h"

void	getpstruct(char **argv, char **envp, t_pipex *pstruct)
{
	pstruct->fd1 = open(argv[1], O_RDONLY);
	if (pstruct->fd1 < 0)
	{
		perror(argv[1]);
		print_error_and_exit(pstruct, NULL);
	}

	pstruct->fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pstruct->fd2 < 0)
	{
		perror(argv[4]);
		print_error_and_exit(pstruct, NULL);
	}

	pstruct->cmd1 = ft_strdup(argv[2]);
	if (!pstruct->cmd1)
		print_error_and_exit(pstruct, NULL);

	pstruct->cmd2 = ft_strdup(argv[3]);
	if (!pstruct->cmd2)
		print_error_and_exit(pstruct, pstruct->cmd1);
	// TODO make it sufficient
	getpaths(envp, pstruct);
}
