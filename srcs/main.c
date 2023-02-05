#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pstruct;

	pstruct = (t_pipex){0};
	util_argcheck(argc, argv);
	getpstruct(argv, envp, &pstruct);
	pipex(pstruct, envp);
	dstruct(&pstruct);
	return (0);
}
