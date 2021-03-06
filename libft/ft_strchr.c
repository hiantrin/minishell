/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-mab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 07:20:12 by zael-mab          #+#    #+#             */
/*   Updated: 2019/04/22 01:47:44 by zael-mab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*n;
	int		j;

	j = 0;
	n = (char *)s;
	while (n[j])
	{
		if (n[j] == (char)c)
			return (n + j);
		j++;
	}
	if (n[j] == c)
		return (&n[j]);
	return (0);
}
