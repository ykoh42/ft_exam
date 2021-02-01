#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if (*s == c)
			return ((char *)s);
		if (*s == '\0')
			return (NULL);
		s++;
	}
}

int		main(int argc, char *argv[])
{
	int		i;
	char	*p1;
	char	*p2;

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			if ((p1 = ft_strchr(argv[1], argv[1][i])) &&
				(p2 = ft_strchr(argv[2], argv[1][i])))
			{
				if (p1 >= &argv[1][i])
					write(1, p1, 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
