/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:30:46 by mouarsas          #+#    #+#             */
/*   Updated: 2021/11/14 23:14:14 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*cmp1;
	unsigned char	*cmp2;

	i = 0;
	cmp1 = (unsigned char *)s1;
	cmp2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (cmp1[i] && cmp2[i] && cmp1[i] == cmp2[i] && i < n - 1)
		i++;
	return (cmp1[i] - cmp2[i]);
}
