/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_stock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:42:55 by mouarsas          #+#    #+#             */
/*   Updated: 2022/11/05 22:59:14 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	quote2eme(int len, char *cont, int index)
{
	len++;
	while (cont[len])
	{
		if (cont[len] == index)
			return (len);
		len++;
	}
	return (0);
}

int	ft_deuxv2(char *cont, int i)
{
	while (cont[i] && cont[i] != ' ' && cont[i] != '\t')
	{
		if (cont[i] == 34 || cont[i] == 39)
			i = quote2eme(i, cont, ((int)cont[i]));
		i++;
	}
	return (i);
}

char	**ft_deux(char *count, char **argv)
{
	int	past;
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (count[i])
	{
		if (i == 0)
			while (count[i] && (count[i] == ' ' || count[i] == '\t'))
				i++;
		past = i;
		if (count[i] && count[i] != ' ' && count[i] != '\t')
			i = ft_deuxv2(count, i);
		if (count[i] == ' ' || count[i] == '\t' || count[i] == '\0')
		{
			argv[j++] = ft_substr(count, past, (i - past));
			while (count[i] && (count[i] == ' ' || count[i] == '\t'))
				i++;
		}
		else
			i++;
	}
	return (argv);
}

int	ft_number_words(char *cnt)
{
	int	past;
	int	i;
	int	nbr;

	nbr = 0;
	i = -1;
	while (cnt[++i])
	{
		if (i == 0)
			while (cnt[i] && (cnt[i] == ' ' || cnt[i] == '\t'))
				i++;
		past = i;
		if (cnt[i] == 34 || cnt[i] == 39)
			i = quote2eme(i, cnt, ((int)cnt[i]));
		if (past + 1 == i && cnt[i + 1] == '\0')
			nbr++;
		if ((cnt[i + 1] == ' ' || cnt[i + 1] == '\t' || cnt[i + 1] == '\0') \
				&& past != i - 1)
		{
			nbr++;
			while (cnt[i + 1] && (cnt[i + 1] == ' ' || cnt[i + 1] == '\t'))
				i++;
		}
	}
	return (nbr);
}
