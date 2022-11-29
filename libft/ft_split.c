/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 23:20:48 by mouarsas          #+#    #+#             */
/*   Updated: 2021/11/28 23:47:25 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char const *s, char c)
{
	unsigned int	i;
	int				n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			n++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (n);
}

static	char	*ft_allocate(char **str, const char *s, size_t n)
{
	char	*copy;

	copy = (char *)malloc(sizeof(char) * (n + 1));
	if (!copy)
	{
		while ((*str)--)
			free(*str);
		free(str);
		return (0);
	}
	ft_strlcpy(copy, s, (n + 1));
	return (copy);
}

char	**ft_split(char const *s, char c)
{
	char	**splited;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (0);
	splited = (char **)malloc(sizeof(char *) * count(s, c) + 1);
	if (!splited)
		return (0);
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
			splited[k++] = ft_allocate(splited, s + j, i - j);
	}
	splited[k] = 0;
	return (splited);
}
