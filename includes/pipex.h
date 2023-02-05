#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/wait.h>

typedef	struct	s_pipex
{
	int		fd1;
	int		fd2;
	char	*cmd1;
	char	*cmd2;
	char	*cmd1path;
	char	*cmd2path;
}				t_pipex;

// Libft Functions
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memset(void *b, int c, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, unsigned int len);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// Util Functions
char	*util_strnew(size_t size);
void	*util_memalloc(size_t size);
char	*util_getenv(char **env, const char *name);
void	util_argcheck(int ac, char **av);

// Print Functions
void	print_usage_and_exit(void);
void	print_error_and_exit(t_pipex *pstruct, char *p);
void	print_strerror(char *msg, int len);

// Main Functions
void	dcmd(char **cmd);
void	dstruct(t_pipex *pstruct);
void	getpaths(char **envp, t_pipex *pstruct);
void	getpstruct(char **av, char **envp, t_pipex *pstruct);
void	pipex(t_pipex pstruct, char **envp);
int		main(int ac, char **av, char **envp);

#endif
