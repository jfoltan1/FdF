#include <mlx.h>

int main(void)
{
    void *mlx;
    void *win;
    int width = 800;
    int height = 600;
    int x = 100;
    int y = 100;

    mlx = mlx_init();
    win = mlx_new_window(mlx, width, height, "Rectangle Example");

    // Draw rectangle - Top line
    int i = x;
    while (i < x + 200)
    {
        if (i >= 0 && i < width && y >= 0 && y < height)
            mlx_pixel_put(mlx, win, i, y, 0xFFFFFF);
        i++;
    }

    // Draw rectangle - Bottom line
    i = x;
    while (i < x + 200)
    {
        if (i >= 0 && i < width && y + 150 >= 0 && y + 150 < height)
            mlx_pixel_put(mlx, win, i, y + 150, 0xFFFFFF);
        i++;
    }

    // Draw rectangle - Left line
    i = y;
    while (i < y + 150)
    {
        if (x >= 0 && x < width && i >= 0 && i < height)
            mlx_pixel_put(mlx, win, x, i, 0xFFFFFF);
        i++;
    }

    // Draw rectangle - Right line
    i = y;
    while (i < y + 150)
    {
        if (x + 200 >= 0 && x + 200 < width && i >= 0 && i < height)
            mlx_pixel_put(mlx, win, x + 200, i, 0xFFFFFF);
        i++;
    }

    mlx_loop(mlx);
    return (0);
}

/*  cc -Wall -Werror -Wextra -o fdf fdf.c -L./minilibx-linux -lmlx -lXext -lX11 -lm*/