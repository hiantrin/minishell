#include "sh.h"

void	help_to_fg(pid_t pid, int id)
{
	tcsetpgrp(0, pid);
	set_job_status(id, STATUS_CONTINUED);
	if (wait_for_job(id) >= 0)
	{
		print_job_status(id);
		remove_job(id);
	}
	else
		print_job_status(id);
	signal(SIGTTOU, SIG_IGN);
	tcsetpgrp(0, getpid());
	signal(SIGTTOU, SIG_DFL);
}

void	help_back_of_built(int type, t_job *j)
{
	int i;

	i = 0;
	j->process->pid = getpid();
	if (j->pgid > 0)
		setpgid(0, j->pgid);
	else
	{
		j->pgid = j->process->pid;
		setpgid(0, j->pgid);
	}
	if (type == COMMAND_FG)
		ft_putendl("42sh: fg: no job control");
	else if (type == COMMAND_BG)
		ft_putendl("42sh: bg: no job control");
	else if (type == COMMAND_JOBS)
	{
		while (i < NR_J)
		{
			if (shell->job[i] != NULL)
				print_job_status(i);
			i++;
		}
	}
	exit(0);
}

void	help_back_of_exit(t_job *j, int i)
{
	j->process->pid = getpid();
	if (j->pgid > 0)
		setpgid(0, j->pgid);
	else
	{
		j->pgid = j->process->pid;
		setpgid(0, j->pgid);
	}
	if (i != 1)
		ft_putendl("exit: too many arguments");
	exit(0);
}

int		background_of_exit(t_job *j, int i)
{
	pid_t	pid;

	pid = 0;
	pid = fork();
	if (pid == 0)
		help_back_of_exit(j, i);
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
