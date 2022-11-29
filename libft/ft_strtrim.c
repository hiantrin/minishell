/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:05:41 by mouarsas          #+#    #+#             */
/*   Updated: 2021/11/27 15:02:09 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	searchin_string(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(set))
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	j = 0;
	if (!s1 || !set)
		return (NULL);
	i = ft_strlen(s1);
	while (s1[j] && searchin_string(set, s1[j]))
		j++;
	while (i && searchin_string(set, s1[i]))
		i--;
	if (i <= 0)
		return (ft_strdup(""));
	return (ft_substr(s1, j, i - j + 1));
}
