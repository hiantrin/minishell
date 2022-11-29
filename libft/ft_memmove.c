/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:30:11 by mouarsas          #+#    #+#             */
/*   Updated: 2021/11/28 18:04:26 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ds;
	unsigned char	*sr;

	ds = (unsigned char *)dst;
	sr = (unsigned char *)src;
	if (!ds && !sr)
		return (0);
	if (ds > sr)
	{
		while (0 < len)
		{
			ds[len - 1] = sr[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(ds, sr, len);
	return (dst);
}
