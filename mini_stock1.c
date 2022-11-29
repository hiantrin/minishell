/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_stock1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:44:11 by mouarsas          #+#    #+#             */
/*   Updated: 2022/11/02 22:30:13 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	my_magic2(t_list *list)
{
	int	cont;

	cont = 0;
	list->first = list;
	while (list->first)
	{
		cont++;
		list->first = list->first->next;
	}
	return (cont);
}

char	**my_magic(t_list *list)
{
	char	**env;
	int		i;

	env = (char **)malloc(sizeof(char *) * my_magic2(list) + 1);
	env[my_magic2(list)] = NULL;
	list->first = list;
	i = 0;
	while (list->first)
	{
		env[i] = list->first->str;
		list->first = list->first->next;
		i++;
	}
	return (env);
}

int	mylen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}
