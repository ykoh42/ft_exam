#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int		is_drawable(float x, float y, char circle, float circle_x, float circle_y, float radius)
{
	float	distance = sqrtf(powf(x - circle_x, 2.) + powf(y - circle_y, 2.));
	if (distance <= radius)
	{
		if (radius - distance < 1.00000000)
			return (1);
		if (circle == 'C')
			return (1);
		else
			return (0);
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	FILE	*file;
	char	*zone;
	int		zone_width, zone_height;
	char	background;
	int		ret, x, y;
	char	circle, color;
	float	circle_x, circle_y, radius;

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
	while ((ret = fscanf(file, "%c %f %f %f %c\n", &circle, &circle_x, &circle_y, &radius, &color)) == 5)
	{
		if (!(radius > 0) ||
			!(circle == 'c' || circle == 'C'))
			break ;
		y = 0;
		while (y < zone_height)
		{
			x = 0;
			while (x < zone_width)
			{
				if (is_drawable((float)x, (float)y, circle, circle_x, circle_y, radius))
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