
#include "fdf.h"

int	get_out_on_key(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		//for esc
		
		mlx_destroy_image(vars->mlx,vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free_points(vars->points);
		free(vars->mlx);
		free(vars);
		exit(2);
	}
	return (0);
}
int	get_out(t_vars *vars)
{
	mlx_destroy_image(vars->mlx,vars->img);
	mlx_destroy_window(vars->mlx, vars->win);	
	mlx_destroy_display(vars->mlx);
	free_points(vars->points);
	free(vars->mlx);
	free(vars);
	exit(2);
}
void	check_init(t_vars *vars)
{
	if (vars->mlx == NULL || vars->win == NULL)
	{
		free(vars->mlx);
		free(vars->win);
		exit(2);
	}
}
char	**get_map(char **argv)
{
	int		a;
	int		fd;
	char	**array;
	char	*line;

	line = NULL;
	a = 0;
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			{
				free(line);
				break;
			}
		free(line);
		a++;
	}
	array = ft_calloc(a + 1,sizeof (char**));
	close(fd);
	fd = open(argv[1], O_RDONLY);
	a = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			{
				free(line);
				break;
			}
		array[a] = ft_strdup(line);
		free(line);
		a++;
	}
	free(line);
	return (array);
}

int	main(int argc, char **argv)
{
	t_vars		*vars;
	t_map		map;
	void	*head;
	int			s_x;
	int			s_y;
	int			n_x;
	int			n_y;
	vars = ft_calloc(1, sizeof(t_vars));
	vars->bits_per_pixel = 256;
	vars->endian = 1;
	vars->size_line = 1280 *(256 / 8);
	int			size_x;
	int			size_y;
	size_x = 0;
	size_y = 0;
	map.array = NULL;
	vars->x = 0;
	vars->y = 0;
	if (argc == 2)
		map.array = get_map(argv);//leak sorted
	{ 
		vars->mlx = mlx_init();
		vars->win = mlx_new_window(vars->mlx, 1280,720, "fdf my guy is FAAAAB");
		vars->img = mlx_new_image(vars->mlx,1280,720);
		vars->data = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,&vars->size_line,&vars->endian);

		check_init(vars);
		vars->points = parser(vars->points, map.array,&size_x,&size_y);
		free_arr(map.array);
		vars->points = iso(vars->points,size_x,size_y); 
	 	draw_lines_vertical(vars->points,*vars);
		head = vars->points;	
	while (vars->points != NULL)
	{
    	s_x = vars->points->x_pos;
    	s_y = vars->points->y_pos;
		if (vars->points->next && vars->points->column == ((t_points *)(vars->points->next))->column)
    	{
       	n_x = ((t_points *)(vars->points->next))->x_pos;
      	n_y = ((t_points *)(vars->points->next))->y_pos;
		draw_line(vars, s_x, s_y, n_x, n_y, vars->points->color);
		}
    	vars->points = vars->points->next;
	}
		vars->points = head;
		mlx_hook(vars->win, 17, 1L << 17, get_out, vars);
		mlx_hook(vars->win, 2, 1L << 0, get_out_on_key, vars);
		//mlx_key_hook(vars->win,key_move,vars);
		mlx_put_image_to_window(vars->mlx,vars->win,vars->img,0,0);
		mlx_loop(vars->mlx);
	}
	return (0);
}
/*
int	main(int argc, char **argv)
{
	t_points	*points;
	t_map		map;

	//vars = NULL;

	map.array = NULL;
	if (argc == 2)
		map.array = get_map(argv);
	points = scale_me_daddy(iso(parser(map.array)));
	while (points)
	{
		printf("%ld ",points->x_pos);
		printf("%ld\n",points->y_pos);
		points = points->next;
	}
}

//TODO:
	//- exit function with freeing upon error of creating stuff,pass the vars to it and free all
	//- segfault on esc happens when I start to parse map.
	//- bresenham algorithm
	// y+1 for vertical?*/
	//implement integer pointers for pixel put!