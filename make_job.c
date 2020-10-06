#include "sh.h"

t_process	*make_process(char *line)
{
	t_process	*p;

	p = (t_process *)malloc(sizeof(t_process));
	p->command = ft_strdup(line);
	p->argv = make_2d_table(line);
	p->next = NULL;
	p->pid = -1;
	p->type = get_command_type(p->argv[0]);
	return (p);
}

t_job		*make_job(char **line, int mode)
{
	t_job	*j;

	j = (t_job *)malloc(sizeof(t_job));
	j->mode = mode;
	j->command = ft_strdup(line[0]);
	j->pgid = -1;
	j->process = make_process(line[0]);
	return (j);
}

int			get_next_job_id(void)
{
	int	i;

	i = 1;
	while (i < NR_J)
	{
		if (shell->job[i] == NULL)
			return (i);
		i++;
	}
	return (-1);
}

int			insert_job(t_job *job)
{
	int id;

	id = get_next_job_id();
	job->id = id;
	shell->job[id] = job;
	return (id);
}
