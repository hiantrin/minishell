/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_job.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:36:53 by hiantrin          #+#    #+#             */
/*   Updated: 2020/10/23 05:43:38 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	set_process_status(pid_t pid, int status)
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
					process->status = status;
					return ;
				}
				process = process->next;
			}
		}
		i++;
	}
}

void	print_job_status(int id)
{
	t_process	*process;

	process = shell->job[id]->process;
	ft_putchar('[');
	ft_putnbr(id);
	ft_putchar(']');
	while (process)
	{
		ft_putchar('\t');
		ft_putnbr(process->pid);
		ft_putchar('\t');
		if (shell->job[id]->process->signal == NULL)
			ft_putstr(STATUS_STRING[process->status]);
		else
			ft_putstr(process->signal);
		ft_putchar('\t');
		ft_putstr(process->command);
		if (process->next != NULL)
			ft_putstr(" | ");
		else
			ft_putchar('\n');
		process = process->next;
	}
}

int		process_counter(int id)
{
	t_process	*p;
	int			count;

	count = 0;
	p = shell->job[id]->process;
	while (p)
	{
		count++;
		p = p->next;
	}
	return (count);
}

int		wait_for_job(int id, int wait_count)
{
	int		process_count;
	pid_t	wait_pid;
	int		status;

	status = 0;
	process_count = process_counter(id);
	while (wait_count < process_count)
	{
		wait_pid = waitpid(-shell->job[id]->pgid, &status, WUNTRACED);
		if (WIFEXITED(status))
			set_process_status(wait_pid, STATUS_DONE);
		else if (WIFSIGNALED(status))
			help_wait_for_job(wait_pid, status);
		else if (WSTOPSIG(status))
		{
			status = -1;
			the_status = status;
			set_process_status(wait_pid, STATUS_SUSPENDED);
			if (wait_count == (process_count - 1))
				print_job_status(id);
		}
		wait_count++;
	}
	return (status);
}

void	remove_job(int id)
{
	t_job		*job;
	t_process	*process;
	t_process	*tmp;

	job = shell->job[id];
	process = job->process;
	while (process)
	{
		tmp = process->next;
		free(process->command);
		free_2d(process->argv);
		free(process);
		process = tmp;
	}
	free(job->command);
	free(job);
	shell->job[id] = NULL;
}
