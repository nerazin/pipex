#include "pipex.h"

void	pathmdlwr(char **cmd1path, char **cmd2path, t_pipex *pstruct, char **pathsi)
{
	char	*path;
	char	**cmd1, **cmd2;
	char	*slashpath;
	char	*base_cmd1, *base_cmd2;

	path = ft_strdup(*pathsi);
	free(*pathsi);
	if (path[ft_strlen(path) - 2 != '/'])
		slashpath = ft_strjoin(path, "/");
	cmd1 = ft_split(pstruct->cmd1, ' ');
	cmd2 = ft_split(pstruct->cmd2, ' ');
	base_cmd1 = ft_strdup(cmd1[0]);
	dcmd(cmd1);
	base_cmd2 = ft_strdup(cmd2[0]);
	dcmd(cmd2);
	*cmd1path = ft_strjoin(slashpath, base_cmd1);
	*cmd2path = ft_strjoin(slashpath, base_cmd2);
	free(base_cmd1);
	free(base_cmd2);
	free(path);
	free(slashpath);
}

void	pstruct_writer(t_pipex *pstruct)
{
	if (pstruct->cmd1path == NULL)
	{
		print_strerror(pstruct->cmd1, ft_strlen(pstruct->cmd1));
		print_strerror(": command not found\n", 20);
	}
	if (pstruct->cmd2path == NULL)
	{
		print_strerror(pstruct->cmd2,  ft_strlen(pstruct->cmd2));
		print_strerror(": command not found\n", 20);
		print_error_and_exit(pstruct, NULL);
	}
}

void	getpaths(char **envp, t_pipex *pstruct)
{
	int		i;
	struct	stat statbuf;
	char	*pathenv;
	char	**paths;
	char	*cmd1path;
	char	*cmd2path;

	pathenv = util_getenv(envp, "PATH"),
	paths = ft_split(pathenv, ':');
	free(pathenv);
	i = -1;
	while (paths[++i])
	{
		pathmdlwr(&cmd1path, &cmd2path, pstruct, &paths[i]);
		if (stat(cmd1path, &statbuf) != -1)
			pstruct->cmd1path = ft_strdup(cmd1path);
		free(cmd1path);
		if (stat(cmd2path, &statbuf) != -1)
			pstruct->cmd2path = ft_strdup(cmd2path);
		free(cmd2path);
	}
	free(paths);
	pstruct_writer(pstruct);
}
