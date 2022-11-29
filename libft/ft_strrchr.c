/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:07:39 by mouarsas          #+#    #+#             */
/*   Updated: 2021/11/22 19:45:32 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*str;

	len = ft_strlen(s);
	str = (char *)s;
	while (len >= 0)
	{
		if (str[len] == (char)c)
		{
			return (&str[len]);
		}
		len--;
	}
	return (0);
}
