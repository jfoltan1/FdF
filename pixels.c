#include "fdf.h"
void    my_mlx_pixel_put(t_vars vars, int x, int y , int color)
{
    char    *dst;
	(void)color;
    if (x > 0 && y > 0 && x < 1280 && y < 720)
    {
        dst = vars.data + (y * vars.size_line + x * (vars.bits_per_pixel / 8));
        *(int *)dst = color;
    }
}
t_points *iso(t_points *points,int size_x,int size_y) 
{
    void *head;
    double angle_radians = 0.785398; 
    double zoom = 5;
    int offset_x = 1280 / 2;          
    int offset_y = 720 / 2;         
    head = points;
	
	while (points != NULL) 
	{
      
        double scaled_x = (points->x_pos - size_x / 2) * zoom;
        double scaled_y = (points->y_pos - size_y / 2) * zoom;
        double scaled_z = points->z_pos * zoom * 4 / 10;
        double projected_x = (scaled_x - scaled_y) * cos(angle_radians) + offset_x;
        double projected_y = (scaled_x + scaled_y) * sin(angle_radians) - scaled_z + offset_y;
        points->x_pos = (int)projected_x;
        points->y_pos = (int)projected_y;
        points = points->next;
    }

    return head;
}

void draw_line(t_vars *vars, int x1, int y1, int x2, int y2, int color)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        my_mlx_pixel_put(*vars ,x1 , y1 ,color);
        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}
void draw_lines_vertical(t_points *points, t_vars vars)
{
    t_points *temp;
    int s_x;
    int s_y;
    int n_x;
    int n_y;
	void *head;

	head = points;

	temp = points;
	while (temp && temp->column <= points->column)
	{
		temp = temp->next;
	}
	while (points != NULL)
{
    s_x = points->x_pos;
    s_y = points->y_pos;
    if (points->next)
    {
        n_x = temp->x_pos;
        n_y = temp->y_pos;
        	draw_line(&vars, s_x, s_y, n_x, n_y, points->color);

    }
    points = points->next;
	if (temp->next != NULL)
	temp = temp->next;
	else
		break;
}
	points = head;
}	