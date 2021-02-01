#include "get_next_line.h"

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_addchr(char **line, char c)
{
	char	*ret;
	int		cnt;
	int		i;
	int		j;

	if (*line)
		cnt = ft_strlen(*line) + 2;
	else
		cnt = 2;
	ret = malloc(cnt * sizeof(char));
	if (*line)
	{
		i = 0;
		j = 0;
		while ((*line)[i])
			ret[j++] = (*line)[i++];
	}
	ret[cnt - 2] = c;
	ret[cnt - 1] = '\0';
	free(*line);
	*line = ret;
}

int		get_next_line(char **line)
{
	char	buf;
	int		ret;

	if (!line)
		return (-1);
	*line = NULL;
	while ((ret = read(0, &buf, 1)) && buf != '\n')
	{
		if (ret == -1)
			return (ret);
		ft_addchr(line, buf);
	}
	if (ret == 0 || (!*line && buf == '\n'))
	{
		*line = malloc(1 * sizeof(char));
		(*line)[0] = '\0';
	}
	return (ret);
}
