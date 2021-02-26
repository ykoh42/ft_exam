#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		is_drawable(float x, float y, char rectangle, float rectangle_x, float rectangle_y, float rectangle_width, float rectangle_height)
{
	if (x < rectangle_x || x > rectangle_x + rectangle_width ||
		y < rectangle_y || y > rectangle_y + rectangle_height)
		return (0);
	if (x - rectangle_x < 1.00000000 || (rectangle_x + rectangle_width) - x < 1.00000000 ||
		y - rectangle_y < 1.00000000 || (rectangle_y + rectangle_height) - y < 1.00000000)
		return (1);
	if (rectangle == 'R')
		return (1);
	else
		return (0);
}

int		main(int argc, char *argv[])
{
	FILE	*file;
	char	*zone;
	int		zone_width, zone_height;
	char	background;
	int		ret, x, y;
	char	rectangle, color;
	float	rectangle_x, rectangle_y, rectangle_width, rectangle_height;

	if (argc != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	if (!(file = fopen(argv[1], "r")) ||
		fscanf(file, "%d %d %c\n", &zone_width, &zone_height, &background) != 3 ||
		!(zone_width > 0 && zone_width <= 300) ||
		!(zone_height > 0 && zone_height <= 300))
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	zone = malloc(zone_width * zone_height * sizeof(char));
	memset(zone, background, zone_width * zone_height);
	while ((ret = fscanf(file, "%c %f %f %f %f %c\n", &rectangle, &rectangle_x, &rectangle_y, &rectangle_width, &rectangle_height, &color)) == 6)
	{
		if (!(rectangle_width > 0) || !(rectangle_height > 0) ||
			!(rectangle == 'r' || rectangle == 'R'))
			break ;
		y = 0;
		while (y < zone_height)
		{
			x = 0;
			while (x < zone_width)
			{
				if (is_drawable((float)x, (float)y, rectangle, rectangle_x, rectangle_y, rectangle_width, rectangle_height))
					zone[y * zone_width + x] = color;
				x++;
			}
			y++;
		}
	}
	if (ret != -1)
	{
		free(zone);
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	y = 0;
	while (y < zone_height)
	{
		write(1, zone + y * zone_width, zone_width);
		write(1, "\n", 1);
		y++;
	}
	free(zone);
	fclose(file);
	return (0);
}