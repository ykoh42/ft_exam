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

void		command(int argc, char *argv[], char *envp[], int *fd_before)
{
	int 	i;
	int		condition;
	pid_t	pid;
	int 	fd_new[2];
	// 종료 조건
	if (argc <= 1)
		return ;
	// pipe 인지 확인하고 NULL 삽입
	condition = is_pipe(argv);
	// printf("condition : %d\n", condition);
	dup2(fd_before[0], 0);
	close(fd_before[0]);
	close(fd_before[1]);
	fd_new[0] = 0;
	fd_new[1] = 1;
	if (condition)
	{
		pipe(fd_new);
		// close(fd_new[0]);
		dup2(fd_new[1], 1);
		close(fd_new[1]);
	}
	else
	{
		dup2(std_out, 1);
	}
	
	pid = fork();
	if (pid == 0)
	{
		// dup2(fd_before[1], 1);
		// dup2(fd_new[1], 1);
		// if (fd_before[0] != 0)
		// 	close(fd_before[0]);
		// if (fd_before[1] != 1)
		// 	close(fd_before[1]);
		if (execve(argv[0], argv, envp) < 0)
		{
			write(2, "error: cannot execute\n", 22);
			exit(1);
		}
	}
	else
	{
		waitpid(pid, 0, 0);
	}

	i = 0;
	while (argv[i])
		i++;

	// 다음껄로 넘어간 다음 다시 command 호출, argc 갯수 초과했는지 봐야할듯
	command(argc - 1 - i, argv + 1 + i, envp, fd_new);
}

int			main(int argc, char *argv[], char *envp[])
{
	int	fd[2];

	std_in = dup(0);
	std_out = dup(1);
	argv++;
	if (pipe(fd) < 0)
	{
		write(2, "error: fatal\n", 13);
		exit(1);
	}

	// printf("before : %d %d\n", fd1[0], fd1[1]);
	command(argc, argv, envp, fd);
	// printf("after  : %d %d\n", fd1[0], fd1[1]);
	while (1);
		// dup2(std_in, 0);
	return (0);
}
