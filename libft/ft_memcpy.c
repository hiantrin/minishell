/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 00:19:35 by mouarsas          #+#    #+#             */
/*   Updated: 2021/11/28 01:04:50 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ds;
	unsigned char	*sr;

	i = 0;
	if (!src && !dest)
		return (0);
	ds = (unsigned char *) dest;
	sr = (unsigned char *) src;
	while (i < n)
	{
		ds[i] = sr[i];
		i++;
	}
	return (ds);
}
