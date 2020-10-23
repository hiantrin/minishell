/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 00:57:10 by hiantrin          #+#    #+#             */
/*   Updated: 2020/10/23 04:55:27 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	set_signal(pid_t pid, int status)
{
	int			i;
	t_process	*process;

	i = 1;
	while (i < NR_J)
	{
		if (shell->job[i])
		{
			process = shell->job[i]->process;
			while (process)
			{
				if (process->pid == pid)
				{
					process->signal = signalmsg[WTERMSIG(status)];
					return ;
				}
				process = process->next;
			}
		}
		i++;
	}
}
