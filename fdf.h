#ifndef FDF_H
#define FDF_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "./libft/libft.h"

typedef struct vars
{
	void *mlx;
	void *win;
	void *img;
	void *data;
	int	bits_per_pixel;
	int size_line;
	int endian;
	int x;
	int y;

}			t_vars;

typedef struct points
{
	long x_pos;
	long y_pos;
	long z_pos;
	int color;
	void *next;
	long column;
	long row;
}			t_points;

typedef struct map
{
	int		fd;
	int		a;
	char	**array;
	char	*line;
}			t_map;

t_points	*iso(t_points *points,int size_x,int size_y);
t_points	*parser(char **array, int *max_x, int *max_y);
void free_map(t_map map);
int	find_char(char *str, char findme);
t_points	*scale_me_daddy(t_points *points,int *max_x,int *max_y);
void draw_line(t_vars *vars, int x1, int y1, int x2, int y2, int color);
void	draw_lines_vertical(t_points *points, t_vars vars);
char	*get_next_line(int fd);

#endif
