/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:51:08 by mouarsas          #+#    #+#             */
/*   Updated: 2021/11/28 19:10:13 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count(long nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
	{
		nb *= -1;
		i++;
	}
	while (nb != '\0')
	{
		i++;
		nb /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t		len;
	char		*str;
	long		nb;

	nb = n;
	len = count(n);
	str = (char *) malloc(sizeof (char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	if (nb < 0)
		nb *= -1;
	while (len--)
	{
		str[len] = (nb % 10) + 48;
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
