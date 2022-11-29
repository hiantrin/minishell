/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 02:35:00 by mouarsas          #+#    #+#             */
/*   Updated: 2021/11/28 23:53:12 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*test;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s == 0)
		return (0);
	while (s[start + i] && i < len)
		i++;
	test = (char *)malloc(sizeof(char) * (i + 1));
	if (!test)
		return (0);
	i = 0;
	while (s[i])
	{
		if (j < len && i >= start)
		{
			test[j] = s[i];
			j++;
		}
		i++;
	}
	test[j] = '\0';
	return (test);
}
