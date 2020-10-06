#include "sh.h"

int		get_command_type(char *command)
{
	if (ft_strcmp(command, "exit") == 0)
		return (COMMAND_EXIT);
	else if (strcmp(command, "cd") == 0)
		return (COMMAND_CD);
	else if (strcmp(command, "jobs") == 0)
		return (COMMAND_JOBS);
	else if (strcmp(command, "fg") == 0)
		return (COMMAND_FG);
	else if (strcmp(command, "bg") == 0)
		return (COMMAND_BG);
	else if (strcmp(command, "export") == 0)
		return (COMMAND_EXPORT);
	else if (strcmp(command, "unset") == 0)
		return (COMMAND_UNSET);
	else
		return (COMMAND_EXTERNAL);
}

void	free_jobs(void)
{
	t_job	*j;
	int		i;

	i = 1;
	while (i < NR_J)
	{
		j = shell->job[i];
		if (j != NULL)
			remove_job(i);
		i++;
	}
}

void	free_env_list(void)
{
	t_env	*next;
	t_env	*list;

	list = shell->env;
	while (list != NULL)
	{
		free(list->name);
		free(list->environ);
		next = list->next;
		free(list);
		list = next;
	}
}

int		to_exit(char **str, t_job *j)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (j->mode == FORE)
	{
		if (i == 1)
		{
			free_job(j);
			free_jobs();
			free_env_list();
			free(shell);
			exit(0);
		}
		else
			ft_putendl("exit: too many arguments");
	}
	else if (j->mode == BACK)
		return (background_of_exit(j, i));
	return (-1);
}

int		trait_built(t_job *j)
{
	int job_id;

	job_id = -1;
	if (j->process->type == COMMAND_EXIT)
		job_id = to_exit(j->process->argv, j);
	else if (j->process->type == COMMAND_JOBS)
		job_id = to_jobs(j, j->process->type);
	else if (j->process->type == COMMAND_FG)
		job_id = to_fg(j->process, j);
	else if (j->process->type == COMMAND_BG)
		job_id = to_bg(j->process, j);
	return (job_id);
}
