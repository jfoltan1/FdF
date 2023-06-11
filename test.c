#include <mlx.h>
#include <mlx_int.h>

/* cc test.c -I./minilibx-linux -L./minilibx-linux -lmlx -lX11 -lXext -lm
 */
#include <mlx.h>

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

int		main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "Rectangle Example");

	// Draw a rectangle
	int x = 100;
	int y = 100;
	int width = 200;
	int height = 150;
	mlx_string_put(vars.mlx, vars.win, 10, 10, 0xFFFFFF, "Press any key to exit.");
	mlx_string_put(vars.mlx, vars.win, x + 10, y + 10, 0xFFFFFF, "Rectangle");

	// Draw horizontal lines
	for (int i = 0; i <= width; i++)
	{
		mlx_pixel_put(vars.mlx, vars.win, x + i, y, 0xFFFFFF); // Top line
		mlx_pixel_put(vars.mlx, vars.win, x + i, y + height, 0xFFFFFF); // Bottom line
	}

	// Draw vertical lines
	for (int i = 0; i <= height; i++)
	{
		mlx_pixel_put(vars.mlx, vars.win, x, y + i, 0xFFFFFF); // Left line
		mlx_pixel_put(vars.mlx, vars.win, x + width, y + i, 0xFFFFFF); // Right line
	}

	mlx_loop(vars.mlx);
	return (0);
}

