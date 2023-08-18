#include "fdf.h"
int	find_char(char *str, char findme)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == findme)
			return(i);
		i++;
	}
	return(0);
}