#include "fdf.h"

int	hexCharToInt(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (c - '0');
	}
	else if (c >= 'A' && c <= 'F')
	{
		return (10 + (c - 'A'));
	}
	else if (c >= 'a' && c <= 'f')
	{
		return (10 + (c - 'a'));
	}
	else
	{
		return (-1);
	}
}

int	hexToInt(char *hex)
{
	int	result;
	int	digit;
	int		i;

	i = 0;
	result = 0;
	if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
		i += 2;
	while (hex[i])
	{
		digit = hexCharToInt(hex[i]);
		if (digit == -1)
			return (-1);
		result = (result << 4) | digit;
		i++;
	}
	free(hex);
	return (result);
}

int	find_char(char *str, char findme)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == findme)
			return (i+1);
		i++;
	}
	return (0);
}
t_points	*parser(t_points *points, char **array, int *max_x, int *max_y)
{
	t_points	*head;
	int			y;
	char		**line_split;
	int			x;
	t_points	*new_point;

	points = NULL;
	head = NULL;
	y = 0;
	while (array[y])
	{
		if(array[y])
			line_split = ft_split(array[y], ' ');
		else
			return(NULL);
		x = 0;
		while (line_split[x] != NULL)
		{
			new_point = ft_calloc(1, sizeof(t_points));
			if (!new_point)
				return (NULL);
			new_point->x_pos = x;
			new_point->y_pos = y;
			new_point->z_pos = ft_atoi(line_split[x]);
			if (find_char(line_split[x], ',') != 0)
					new_point->color = hexToInt(ft_substr(line_split[x],find_char(line_split[x], ','), 9));
			else
				new_point->color = 0xFFFFFF;
			new_point->next = NULL;
			new_point->column = y;
			if (points == NULL)
			{
				points = new_point;
				head = points;
			}
			else
			{
				points->next = new_point;
				points = points->next;
			}
			if (*max_x < x)
				*max_x = x;
			x++;
		}
		free_arr(line_split);
		y++;
	}
	*max_x += 1;
	*max_y = y;
	return (head);
}

void	free_arr(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
void	free_points(t_points *points)
{
	t_points	*temp;

	while (points->next != NULL)
	{
		temp = points;
		points = points->next;
		free(temp);
	}
	free(points);
}
