/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 04:38:42 by hiantrin          #+#    #+#             */
/*   Updated: 2020/10/23 04:49:48 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	print_pgid_of_job(int id)
{
	ft_putchar('[');
	ft_putnbr(id);
	ft_putstr("] ");
	ft_putnbr(shell->job[id]->pgid);
	ft_putchar('\n');
}

int		is_job_completed(int id)
{
	t_process	*process;

	process = shell->job[id]->process;
	while (process)
	{
		if (process->status != STATUS_DONE)
			return (0);
		process = process->next;
	}
	return (1);
}

int		get_job_id_by_pid(int pid)
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
					return (i);
				process = process->next;
			}
		}
		i++;
	}
	return (-1);
}

void	help_check_zombie(pid_t pid)
{
	int	job_id;

	job_id = get_job_id_by_pid(pid);
	if (job_id > 0 && is_job_completed(job_id) == 1)
	{
		print_job_status(job_id);
		remove_job(job_id);
	}
}

void	check_zombie(void)
{
	int status;
	int pid;
	int job_id;

	while ((pid = waitpid(-1, &status, WNOHANG | WUNTRACED | WCONTINUED)) > 0)
	{
		if (WIFEXITED(status))
			set_process_status(pid, STATUS_DONE);
		else if (WIFSTOPPED(status))
		{
			set_process_status(pid, STATUS_SUSPENDED);
			job_id = get_job_id_by_pid(pid);
			print_job_status(job_id);
		}
		else if (WIFSIGNALED(status))
		{
			set_process_status(pid, STATUS_DONE);
			set_signal(pid, status);
		}
		else if (WIFCONTINUED(status))
			set_process_status(pid, STATUS_CONTINUED);
		help_check_zombie(pid);
	}
}
