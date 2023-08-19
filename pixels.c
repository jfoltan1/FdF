#include "fdf.h"

t_points *iso(t_points *points)
{
	double iso_angle;
	double iso_cos;
	double iso_sin;
	void *head;

	head = points; 
	iso_angle = 0.523599;
	iso_cos = cos(iso_angle);
	iso_sin = sin(iso_angle);
	while (points != NULL)
	{
		double prev_x = points->x_pos; 
		points->x_pos = prev_x * iso_cos - points->y_pos * iso_cos;
		points->y_pos = prev_x * iso_sin + points->y_pos * iso_sin - points->z_pos;
		points = points->next;
	}
	return head;
}

void	scale_me_daddy(int x,int y, int *s_x, int *s_y)
{
	double	scale;
	int		center_x;
	int		center_y;

	center_x = 640;
	center_y = 360;
	scale = 25.0;

	*s_x = center_x + x * scale;
    *s_y = center_y + y * scale;

}
void draw_line(t_vars *vars, int x0, int y0, int x1, int y1, int color)
 {
    int dx = abs(x1 - x0); 
    int dy = abs(y1 - y0); 
    int sx = (x0 < x1) ? 1 : -1; 
    int sy = (y0 < y1) ? 1 : -1; 
    int err = dx - dy; 

    while (x0 != x1 || y0 != y1) {
        mlx_pixel_put(vars->mlx, vars->win, x0, y0, color); 
        int err2 = 2 * err; 
        if (err2 > -dy) 
		{
            err -= dy;
            x0 += sx; 
        }
        if (err2 < dx) 
		{
            err += dx;
            y0 += sy; 
        }
    }
}
void draw_grid_lines(t_vars *vars, t_points *points, int color) 
{
    t_points *current = points;

    while (current->next != NULL) 
	{
        int x1 = current->x_pos;
        int y1 = current->y_pos;
        int x2 = ((t_points *)(current -> next))->x_pos;
        int y2 = ((t_points *)(current -> next))->y_pos;

        draw_line(vars, x1, y1, x2, y1, color); // Horizontal line
        draw_line(vars, x2, y1, x2, y2, color); // Vertical line

        current = current->next;
    }
}