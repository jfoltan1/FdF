/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:50:24 by jfoltan           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/08/03 21:21:57 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

=======
/*   Updated: 2022/12/19 10:50:25 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
>>>>>>> 078e68eb377fe1b4142a93e27cd82e51f01182b6
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*ptr;

	i = ft_strlen(s) + 1;
	ptr = (char *) malloc(sizeof(char) * i);
	if (!ptr)
		return (NULL);
	ptr = ft_memcpy(ptr, s, i);
	return (ptr);
}
