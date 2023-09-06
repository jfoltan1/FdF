#include "fdf.h"
int hexCharToInt(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'F') {
        return 10 + (c - 'A');
    } else if (c >= 'a' && c <= 'f') {
        return 10 + (c - 'a');
    } else {
        return -1; // Invalid character
    }
}

int hexToInt(const char *hex) {
    int result = 0;
    int digit;

    // Skip "0x" or "0X" prefix if present
    if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X')) {
        hex += 2;
    }

    while (*hex) {
        digit = hexCharToInt(*hex);
        if (digit == -1) {
            return -1; // Invalid hex input
        }
        result = (result << 4) | digit;
        hex++;
    }

    return result;
}

int	find_char(char *str, char findme)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == findme)
			return (i);
		i++;
	}
	return (0);
}
t_points	*parser(char **array,int *max_x,int *max_y)
{
	t_points	*points;
	t_points	*head;
	int			y;
	char		**line_split;
	int			x;
	t_points	*new_point;
	// char 		*temp_col;

	points = NULL;
	head = NULL;
	y = 0;
	// temp_col = NULL;
	while (array[y])
	{
		line_split = ft_split(array[y], ' ');
		x = 0;
		while (line_split[x] != NULL)
		{
			new_point = malloc(sizeof(t_points));
			if (!new_point)
			{
				// Handle memory allocation error
				// might want to free previously allocated memory before returning NULL
				return (NULL);
			}
			new_point->x_pos = x;
			new_point->y_pos = y;
			new_point->z_pos = ft_atoi(line_split[x]);
			if (find_char(line_split[x], ',') != 0)
				new_point->color = hexToInt(ft_substr(line_split[x],find_char(line_split[x], ',') + 1, 8));
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
		y++;
	}
	*max_x += 1;
	*max_y = y;
	return (head);
}
void free_map(t_map map)
{
	int i;
	i = 0;
	while(map.array[i])
	{
		free(map.array[i]);
		i++;
	}
	free(map.array);
	// free(map.line);
}
