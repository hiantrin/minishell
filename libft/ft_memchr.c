/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 02:38:37 by mouarsas          #+#    #+#             */
/*   Updated: 2021/11/28 01:04:05 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*src;

	i = 0;
	if (!s && !n)
		return (0);
	src = (unsigned char *) s;
	while (i < n)
	{
		if (src[i] == (unsigned char)c)
		{
			return (&src[i]);
		}
		i++;
	}
	return (0);
}
