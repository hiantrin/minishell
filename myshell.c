/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myshell.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:01:29 by mouarsas          #+#    #+#             */
/*   Updated: 2022/11/09 19:49:26 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	affichage_myenv(t_list *list, t_pi pi)
{
	list->first = list;
	if (pi.pipe[1][1] != -1)
	{
		while (list->first)
		{
			if (pi.pipe[1][1] != 0)
				ft_putendl_fd(list->first->str, pi.pipe[1][1]);
			list->first = list->first->next;
		}
	}
}

t_list	*ft_myshell(char **argv, int com, t_list *list, t_status *status)
{
	int	len;
	int	st;

	st = 0;
	len = 0;
	while (argv[len])
		len++;
	if (com == 1)
		ft_echo(argv, status->pi, 1);
	else if (com == 2)
		ft_cd(argv, list, status->pi, &st);
	else if (com == 4 && status->pi.new == NULL)
		list = ft_unset(argv, list);
	else if (com == 5)
		list = ft_export(argv, list, status->pi);
	else if (com == 6)
		ft_env(argv, list, status->pi);
	else if (com == 7)
		ft_pwd(status->pi);
	status->status = st;
	return (list);
}
