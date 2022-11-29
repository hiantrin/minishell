/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qoute_slash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:53:50 by mouarsas          #+#    #+#             */
/*   Updated: 2022/11/02 22:12:36 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*move_slash(char *line)
{
	char	*str;
	int		a;

	a = count_slash(line);
	if (a != 0)
	{
		str = help_slash(line, a);
		free(line);
		return (str);
	}
	return (line);
}

char	*help_slash(char *line, int a)
{
	char	*str;
	int		j;
	char	c;

	str = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1 - a));
	str[ft_strlen(line) - a] = '\0';
	j = 0;
	a = 0;
	while (line[j])
	{
		c = line[j];
		if (c == 34 || c == 39)
		{
			j++;
			while (line[j] && line[j] != c)
				j++;
		}
		else if (c != 92)
			str[a++] = line[j];
		if (line[j] != '\0')
			j++;
	}
	return (str);
}

int	count_slash(char *line)
{
	int		i;
	int		count;
	char	c;

	i = 0;
	count = 0;
	while (line[i])
	{
		c = line[i];
		if (c == 34 || c == 39)
		{
			i++;
			while (line[i] && line[i] != c)
				i++;
		}
		else if (c == 92)
			count++;
		if (line[i] != '\0')
			i++;
	}
	return (count);
}

char	*move_quote(char *line, int i)
{
	char	c;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (line[i])
	{
		c = line[i];
		if (c == 34 || c == 39)
		{
			j = i;
			i++;
			while (line[i] != c)
				i++;
			str = ft_substr(line, j + 1, (i - (j + 1)));
			join_with_something(&line, str, i + 1, j);
			i--;
		}
		else
			i++;
	}
	return (line);
}
