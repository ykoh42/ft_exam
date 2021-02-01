/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoh <ykoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:44:11 by ykoh              #+#    #+#             */
/*   Updated: 2021/02/01 15:44:23 by ykoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
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
