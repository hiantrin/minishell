/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_for_all2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:44:40 by mouarsas          #+#    #+#             */
/*   Updated: 2022/11/05 23:14:01 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	some_name(int *i, int *j, char *str, char c)
{
	int				b;
	int				count;
	t_some_norme	norme;

	b = i[0];
	count = 0;
	while (str[*i] == c)
	{
		(*i)++;
		count++;
	}
	if (j[0] == b && c == '&' && count == 1 && b - 1 != 0 && \
		(str[b - 1] == '>' || str[b - 1] == '<') && \
		str[b - 2] != '<' && str[b - 2] != '>')
	{
		j[0] = i[0];
		(*i)--;
		return (1);
	}
	norme.c = c;
	norme.count = count;
	norme.b = b;
	norme.str = str;
	return (some_name_norme(norme, &(*j), &(*i)));
}

int	some_name_norme(t_some_norme norme, int *j, int *i)
{
	char	*new;

	if (j[0] == norme.b && norme.c != '>' && norme.c != '<')
		return (print_and_of_number(norme.c, norme.count));
	new = ft_substr(norme.str, j[0], norme.b - j[0]);
	if (search_no_espace(new) == 0 && norme.c != '<' && norme.c != '>')
	{
		free(new);
		return (print_and_of_number(norme.c, norme.count));
	}
	free(new);
	if (norme.c != ';' && norme.count > 2)
		return (print_number_of_and(norme.c, norme.count));
	if (norme.c == ';' && norme.count > 1)
		return (print_and_of_number(norme.c, norme.count));
	j[0] = i[0];
	(*i)--;
	return (1);
	return (1);
}

int	print_number_of_and(char s, int count)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	if (count == 3)
		ft_putchar_fd(s, 2);
	if (count > 3)
	{
		ft_putchar_fd(s, 2);
		ft_putchar_fd(s, 2);
	}
	ft_putendl_fd("'", 2);
	return (0);
}

int	print_and_of_number(char s, int count)
{
	if (s == '<' || s == '>')
		return (print_fu_redirect_error());
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	if (count == 1)
		ft_putchar_fd(s, 2);
	if (count > 1)
	{
		ft_putchar_fd(s, 2);
		ft_putchar_fd(s, 2);
	}
	ft_putendl_fd("'", 2);
	return (0);
}

int	print_fu_redirect_error(void)
{
	ft_putendl_fd("minishell: syntax error near unexpected token `newline'", 2);
	return (0);
}
