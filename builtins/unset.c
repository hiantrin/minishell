/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:34:34 by mouarsas          #+#    #+#             */
/*   Updated: 2022/11/08 19:48:43 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*help_ft_unset_env(t_list *list, char *str)
{
	t_list	*tmp;
	char	*env;

	list->first = list;
	while (list->first->next)
	{
		env = get_key_env(list->first->next->str);
		if (ft_strcmp(str, env) == 0)
		{
			tmp = list->first->next;
			list->first->next = tmp->next;
			free(tmp->str);
			free(tmp);
			free(env);
			return (list);
		}
		free(env);
		list->first = list->first->next;
	}
	return (list);
}

t_list	*ft_unset_env(t_list *list, char *str)
{
	t_list	*tmp;
	char	*env;

	list->first = list;
	env = get_key_env(list->first->str);
	if (ft_strcmp(str, env) == 0)
	{
		tmp = list->first;
		list = tmp->next;
		free(tmp->str);
		free(tmp);
		free(env);
		return (list);
	}
	free(env);
	return (help_ft_unset_env(list, str));
}

t_list	*ft_unset(char **av, t_list *list)
{
	int	i;

	i = 0;
	if (list == NULL)
		return (list);
	while (av[++i])
		list = ft_unset_env(list, av[i]);
	return (list);
}
