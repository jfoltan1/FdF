#include "fdf.h"

int	get_out_on_key (int keycode, t_vars *vars,t_map	map)
{
	if (keycode == 65307)
	{	
		mlx_destroy_window(vars->mlx,vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		free(map.line); //sort this still
		exit(2);
	}
	return(0);
}
int get_out(int keycode,t_vars *vars)
{
		(void)keycode;
		mlx_destroy_window(vars->mlx,vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(2); //still segfaults fml and has leaks!
}
void check_init(t_vars vars)
{
	if(vars.mlx == NULL || vars.win == NULL)
		{
			free(vars.mlx);
			free(vars.win);
			exit(2);
		}
}
char 	**get_map(char **argv)
{
	int		a;
	int		fd;
	char	**array;
	char	*line;
	
	a = 0;
	fd = open(argv[1], O_RDONLY);
	array = malloc(sizeof(char *)*12);
	while (1)
	{
		line = get_next_line(fd);
		if(line == NULL)
			break;
		array[a] = *ft_split(line, '\n');
		a++;
	}
	array[a] = NULL;
	free(line);
	return(array);
}
int main(int argc, char **argv)
{
	t_vars		vars;
	t_map	map;
	(void)argv;
	t_points *points;

	map.array = NULL;
	if (argc == 2)
	{
		map.array = get_map(argv);
		vars.mlx = mlx_init();
		//vars.win = mlx_new_window(vars.mlx, 800, 600, "fdf my guy is FAAAAB");
		check_init(vars);
		points = iso(parser(map.array));
		//mlx_hook(vars.win,2,1L<<0,get_out_on_key, &vars);
		//mlx_hook(vars.win,17,0,get_out, &vars);/* still segfaulting */
		//mlx_loop(vars.mlx);
	}
	return(0);
}
/* 
TODO:
	- exit function with freeing upon error of creating stuff,pass the vars to it and free all 
	- segfault on esc happens when I start to parse map. 
	- bresenham algorithm


 */