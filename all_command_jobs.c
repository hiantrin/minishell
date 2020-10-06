#include "sh.h"

int		to_jobs(t_job *j, int type)
{
	int		i;

	i = 1;
	if (j->mode == FORE)
	{
		while (i < NR_J)
		{
			if (shell->job[i] != NULL)
				print_job_status(i);
			i++;
		}
	}
	else if (j->mode == BACK)
		return (background_of_built(type, j));
	return (-1);
}

int		background_of_built(int type, t_job *j)
{
	pid_t	pid;

	pid = 0;
	pid = fork();
	if (pid == 0)
		help_back_of_built(type, j);
	else
	{
		j->process->pid = pid;
		if (j->pgid > 0)
			setpgid(pid, j->pgid);
		else
		{
			j->pgid = pid;
			setpgid(pid, j->pgid);
		}
	}
	return (insert_job(j));
}

int		to_fg(t_process *process, t_job *j)
{
	int		i;
	pid_t	pid;

	i = 0;
	if (j->mode == FORE)
	{
		while (process->argv[i])
			i++;
		if (i > 2)
			return (put_error_fg(COMMAND_FG));
		if (i > 29 || shell->job[i] == NULL || (i == 1 && search_last() == 0))
			return (put_error_no_such(COMMAND_FG));
		if (i == 1)
			i = search_last();
		pid = shell->job[i]->pgid;
		if (kill(-pid, SIGCONT) < 0)
			return (put_error_not_found(COMMAND_FG));
		help_to_fg(pid, i);
	}
	else if (j->mode == BACK)
		return (background_of_built(COMMAND_FG, j));
	return (-1);
}

int		to_bg(t_process *process, t_job *j)
{
	int		i;
	pid_t	pid;

	i = 0;
	if (j->mode == FORE)
	{
		while (process->argv[i])
			i++;
		if (i > 2)
			return (put_error_fg(COMMAND_BG));
		if (i > 29 || shell->job[i] == NULL || (i == 1 && search_last() == 0))
			return (put_error_no_such(COMMAND_BG));
		if (i == 1)
			i = search_last();
		pid = shell->job[i]->pgid;
		if (kill(-pid, SIGCONT) < 0)
			return (put_error_not_found(COMMAND_BG));
		set_job_status(i, STATUS_CONTINUED);
		print_job_status(i);
	}
	else if (j->mode == BACK)
		return (background_of_built(COMMAND_BG, j));
	return (-1);
}
