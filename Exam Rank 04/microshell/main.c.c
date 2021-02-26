#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int 	std_out;
int 	std_in;

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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
			write(2, argv[1], ft_strlen(argv[1]));
			write(2, "\n", 1);
			exit(1);
		}
	}
	return (0);
}

int			is_pipe(char *argv[])
{
	int	ret;
	int i;

	ret = 0;
	i = 0;
	while (argv[i])
	{
		if (strncmp(argv[i], "|", 2) == 0)
		{
			ret = 1;
			argv[i] = 0;
			break ; // "|"
		}
		else if (strncmp(argv[i], ";", 2) == 0)
		{
			ret = 0;
			argv[i] = 0;
			break ; // ";"
		}
		i++;
	}
	return (ret);
}

/*
int			ft_execve(char *argv[], char *envp[], int condition, int *fd2)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
			write(2, "error: fatal\n", 13);
			exit(1);
	}
	else if (pid == 0)
	{
		if (execve(argv[0], argv, envp) < 0)
		{
			write(2, "error: cannot execute ", 22);
			write(2, argv[0], ft_strlen(argv[0]));
			write(2, "\n", 1);
			exit(1);
		}
	}
	else
	{

	}
	return (0);
}
*/

void		command(int init, int argc, char *argv[], char *envp[], int *fdA)
{
	int 	i;
	int		condition;
	pid_t	pid;
	int 	fdB[2];

	printf("%d %d\n", init, argc);
	if (init == argc)
	{
		close(fdA[0]);
		close(fdA[1]);
		fdA[0] = 0;
		fdA[1] = 1;
	}
	if (argc <= 1)
	{
		return ;
	}
	condition = is_pipe(argv); 




	pid = fork();
	if (pid == 0)
	{
		// ㅈㅏ식

		execve(argv[0], argv, envp);
	}
	else
	{
		waitpid(pid, 0, 0);
		


	}

	i = 0;
	while (argv[i])
		i++;

	// printf("argv : %s\n", *argv);
	// 다음껄로 넘어간 다음 다시 command 호출, argc 갯수 초과했는지 봐야할듯
	command(init, argc - 1 - i, argv + 1 + i, envp, fdB);
	fdA+=0;
}

int			main(int argc, char *argv[], char *envp[])
{
	int	fdA[2];

	argv++;

	pipe(fdA);

	command(argc, argc, argv, envp, fdA);

	// while (1);
	return (0);
}
