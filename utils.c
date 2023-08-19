#include "fdf.h"
int	find_char(char *str, char findme)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == findme)
			return(i);
		i++;
	}
	return(0);
}
t_points *parser(char **array)
{
	t_points *points;
	int	i;
	int y;
	int x;
	char **line_split;
	void	*head;

	y = 0;
	x = 0;
	i = 0;
	points = malloc(sizeof(t_points));
	head = points;
	while (array[y] != NULL)
	{
		line_split = ft_split(array[y], ' ');
		while (*line_split)
		{
				points->x_pos = x;
				points->y_pos = y;
				points->z_pos = ft_atoi(*line_split);
				if (find_char(*line_split, ',') != 0)
					 points->color = ft_substr(*line_split,(unsigned int)find_char(*line_split, ',') + 1, 8);
				else
					points->color = NULL;
			points -> next = malloc(sizeof(t_points));
			points = points -> next;
			line_split++;				
			x++;
		}
		x = 0;
		y++;
	}
	return(head);
}