/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_v4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 03:52:07 by hiantrin          #+#    #+#             */
/*   Updated: 2020/10/23 04:30:28 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*to_move_s_q(char **str, char c, int *start, int *end)
{
	start[0] = start[0] + 1;
	while (str[0][start[0]] && str[0][start[0]] != c)
	{
		if (str[0][start[0]] == 92 && c == 34)
			start[0] = start[0] + 2;
		else
			start[0] = start[0] + 1;
	}
	start[0] = start[0] + 1;
	str[0] = replace_by_s_q(str[0], &start[0], &end[0], 1);
	return (str[0]);
}

void	another_help_f_s_q(int *start, int *type)
{
	start[0] = start[0] + 2;
	type[0] = 0;
}

int		norme_s_q(int i, char *line, char c)
{
	i++;
	while (line[i] != c)
	{
		if (line[i] == 92 && c == 34)
		{
			i++;
			break ;
		}
		else
			i++;
	}
	return (i);
}

int		help_c_c_and(char *str, char c, int i)
{
	i++;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*while_for_q_s(char *str)
{
	int fi;

	fi = 0;
	while (1)
	{
		str = ft_filter_quote(str, 0);
		str = finish_slach(str, &fi);
		if (fi == 0)
			break ;
	}
	return (str);
}
