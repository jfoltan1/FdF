#ifndef FDF_H
#define FDF_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./gnl/get_next_line.h"
#include "./libft/libft.h"

typedef struct vars
{
	void *mlx;
	void *win;
}			t_vars;

typedef struct points
{
	int x_pos;
	int y_pos;
	int z_pos;
	char *color;
	void *next;

}			t_points;

typedef struct map
{
	int		fd;
	int		a;
	char	**array;
	char	*line;
}			t_map;

void	get_size(char **array,int *xnum, int *ynum);
int	get_lenght(char **str, char deli,int y);
t_points	*iso(t_points *points);
t_points *parser(char **array);
int	find_char(char *str, char findme);
void	scale_me_daddy(int x,int y, int *s_x, int *s_y);
void draw_line(t_vars *vars, int x0, int y0, int x1, int y1, int color);
void draw_grid_lines(t_vars *vars, t_points *points, int color);

#endif