/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 02:51:54 by mouarsas          #+#    #+#             */
/*   Updated: 2021/11/28 19:11:42 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cmp1;
	unsigned char	*cmp2;

	i = 0;
	if (!s1 && !s2)
		return (0);
	cmp1 = (unsigned char *) s1;
	cmp2 = (unsigned char *) s2;
	while (i < n)
	{
		if (cmp1[i] != cmp2[i])
			return (cmp1[i] - cmp2[i]);
		i++;
	}
	return (0);
}
