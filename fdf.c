#include "fdf.h"

int	get_out_on_key(int keycode, t_vars *vars, t_map map)
{
	if (keycode == 65307)
	{
		mlx_destroy_display(vars->mlx);
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->mlx);
		free(vars->win);
		free(map.line); // sort this still1
		exit(2);
	}
	return (0);
}
int	get_out(int keycode, t_vars *vars)
{
	(void)keycode;
	mlx_destroy_display(vars->mlx);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	free(vars->win);
	exit(2); // still segfaults fml and has leaks!
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
	int		fd2;
	char	**array;
	char	*line;

	line = NULL;

	a = 0;
	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[1], O_RDONLY);
	while (get_next_line(fd))
		a++;
	array = malloc(sizeof(char *) * a + 2);
	a = 0;
	while (1)
	{
		line = get_next_line(fd2);
		if (!line)
			{
				// array[a] = NULL; // toto mozno bude problem
			free(line);
				break;
			}
		array[a] = ft_strdup(line);
		a++;
	}
	return (array);
}
int key_move(int keycode,t_vars *vars)
{
	//(void)vars;
	if (keycode == 65361)
		vars->x+= 5;
	if (keycode == 65363)
		vars->x-= 5;
	if (keycode == 65362)
		vars->y += 5;
	if (keycode == 65364)
		vars->y -= 5;
	//mlx_clear_window(vars->mlx,vars->win);
	mlx_put_image_to_window(vars->mlx,vars->win,vars->img,vars->x,vars->y);
	return (0);
}
int	main(int argc, char **argv)
{
	t_vars		vars;
	t_map		map;
	t_points	*points;
	int			s_x;
	int			s_y;
	int			n_x;
	int			n_y;
	vars.bits_per_pixel = 256;
	vars.endian = 1;
	vars.size_line = 1280 *(256 / 8);
	int			size_x;
	int			size_y;
	// vars = NULL;
	size_x = 0;
	size_y = 0;
	map.array = NULL;
	vars.x = 0;
	vars.y = 0;
	if (argc == 2)
	{
		map.array = get_map(argv);
		/*vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, 1280,720, "fdf my guy is FAAAAB");
		vars.img = mlx_new_image(vars.mlx,3840,2160);
		vars.data = mlx_get_data_addr(vars.img, &vars.bits_per_pixel,&vars.size_line,&vars.endian);
	}
		check_init(&vars);
		points = parser(map.array,&size_x,&size_y);
		points = iso(points,size_x,size_y);
	 	draw_lines_vertical(points,vars);
	while (points != NULL)
	{
    	s_x = points->x_pos;
    	s_y = points->y_pos;
		if (points->next && points->column == ((t_points *)(points->next))->column)
    	{
       	n_x = ((t_points *)(points->next))->x_pos;
      	n_y = ((t_points *)(points->next))->y_pos;
		draw_line(&vars, s_x, s_y, n_x, n_y, points->color);
		}
    	points = points->next;
	}
		mlx_hook(vars.win, 2, 1L << 0, get_out_on_key, &vars);
		mlx_hook(vars.win, 17, 0, get_out, &vars); // still segfaulting
		mlx_key_hook(vars.win,key_move,&vars);
		mlx_put_image_to_window(vars.mlx,vars.win,vars.img,0,0);
		mlx_loop(vars.mlx);*/
}
	// free(vars.mlx);
	free_map(map);
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
