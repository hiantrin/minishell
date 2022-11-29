/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:33:51 by mouarsas          #+#    #+#             */
/*   Updated: 2022/11/08 18:40:41 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(char **av, t_list *list, t_pi pi)
{
	if (!list)
		return ;
	else if (av[1])
	{
		ft_putstr_fd(av[1], pi.pipe[2][1]);
		ft_putstr_fd(": No such file or directory", pi.pipe[2][1]);
		ft_putstr_fd("\n", pi.pipe[2][1]);
	}
	else
	{
		list->first = list;
		while (list->first)
		{
			ft_putstr_fd(list->first->str, pi.pipe[1][1]);
			ft_putstr_fd("\n", pi.pipe[1][1]);
			list->first = list->first->next;
		}
	}
}
