/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 20:52:48 by mouarsas          #+#    #+#             */
/*   Updated: 2021/11/28 01:22:00 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*stack;
	size_t	x ;

	i = 0;
	stack = (char *)haystack;
	x = ft_strlen(needle);
	if (x == 0)
		return (stack);
	while (stack[i] && i < len)
	{
		j = 0;
		while (stack[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return (&stack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
