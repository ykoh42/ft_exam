#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct	s_data {
	int			is_pipe;
	char		**argv;
	char		**envp;
}				t_data;

int			ft_execve(char *path, char *argv[], char *envp[], int is_pipe)
{
	int		fd[2];
	pid_t	pid;
	int		i;

	if (is_pipe)
	{
		if (pipe(fd) < 0)
		{
			write(2, "error: fatal\n", 13);
			exit(1);
		}
	}
	pid = fork();
	if (pid < 0)
	{
			write(2, "error: fatal\n", 13);
			exit(1);
	}
	else if (pid == 0)
	{
		if (execve(path, argv, envp) < 0)
		{
			write(2, "error: cannot execute ", 22);
			i = 0;
			while (path[i])
				i++;
			write(2, path, i);
			write(2, "\n", 1);
			exit(1);
		}
	}
	else
	{


	}





	return (0);
	path +=0;
	argv+=0;
	envp+=0;
}

int			ft_cd(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (i != 2)
	{
		write(2, "error: cd: bad arguments\n", 25);
		exit(1);
	}
	else
	{
		if (chdir(argv[1]) < 0)
		{
			write(2, "error: cd: cannot change directory to ", 38);
			i = 0;
			while (argv[1][i])
				i++;
			write(2, argv[1], i);
			write(2, "\n", 1);
			exit(1);
		}
	}
	return (0);
}

int			command(char *argv[], char *envp[])
{
	int	is_pipe;
	int i;

	is_pipe = 0;
	i = 0;
	while (argv[i])
	{
		if (strncmp(argv[i], "|", 2) == 0)
		{
			is_pipe = 1;
			argv[i] = 0;
			break ;
		}
		else if (strncmp(argv[i], ";", 2) == 0)
		{
			is_pipe = 0;
			argv[i] = 0;
			break ;
		}
		i++;
	}
	if (strncmp(argv[0], "cd", 3) == '\0')
		ft_cd(argv);
	else
	 	ft_execve(argv[0], argv, envp, is_pipe);
	return (i);
}

int			main(int argc, char *argv[], char *envp[])
{
	int		i;

	argv++;
	i = 0;
	while (i < argc - 1)
	{

		// printf("argv[%d] : %s\n",i, argv[i]);
		i += command(argv + i, envp);
		i++;
	}




	return (0);
	envp+=0;
}
