#include "fdf.h"

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

int		main(int argc, char **argv)
{
	int		fd;
	int		a;
	char	**array;
	char	*line;
	(void)argc;
	fd = open(argv[1],O_RDONLY);
	a = 0;
	while (1)
	{
		line = get_next_line(fd);
		array[a] = ft_split(line, ' ');
		if (array[a] == NULL)
			break;
		a++;
	}

}
/*     Pass each line to the ft_split function along with the delimiter (e.g., space or comma) to split it into an array of substrings.
    Store the resulting array of substrings.

Process the substrings and initialize the array of points:

    Iterate over the array of substrings.
    For each substring, parse the values (e.g., coordinates or color) and store them in your array of points. */
// based on that array think of next approach.
