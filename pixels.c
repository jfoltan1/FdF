#include "fdf.h"

t_points *parser(char **array)
{
	t_points *points;
	int	i;
	int y;
	int x;
	char **line_split;


	y = 0;
	x = 0;
	i = 0;
	points = malloc(sizeof(t_points));
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
		}
		x = 0;
		y++;
	}
	points->next = NULL;
	return(points);
}

t_points	*iso(t_points *points)
{
	double iso_angle;
	double iso_cos;
	double iso_sin;
	void *head;

	head = &points;

	iso_angle = 0.523599;
	iso_cos = cos(iso_angle);
	iso_sin = sin(iso_angle);
	while (points != NULL)
	{
		points->x_pos = points->x_pos * iso_cos - points->y_pos * iso_cos;
		points -> y_pos =  points->x_pos * iso_sin + points->y_pos * iso_sin - points->z_pos;
		points = points -> next;
	}
	return(head);
}