#include "sh.h"

void	free_2d(char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	free_job(t_job *job)
{
	t_process	*process;
	t_process	*tmp;

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
}

int		help_trait(t_job **j, t_env *list, int *count, int *status)
{
	int		job_id;

	count[0]++;
	exec_command(&j[0], list);
	job_id = insert_job(j[0]);
	if (j[0]->mode == FORE)
	{
		tcsetpgrp(0, j[0]->pgid);
		status[0] = wait_for_job(j[0]->id, 0);
		signal(SIGTTOU, SIG_IGN);
		tcsetpgrp(0, getpid());
		signal(SIGTTOU, SIG_DFL);
	}
	return (job_id);
}
