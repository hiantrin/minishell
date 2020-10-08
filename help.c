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
	else if (strcmp(command, "set") == 0)
		return (COMMAND_SET);
	else if (strcmp(command, "echo") == 0)
		return (COMMAND_ECHO);
	else if (strcmp(command, "type") == 0)
		return (COMMAND_TYPE);
	else if (strcmp(command, "env") == 0)
		return (COMMAND_ENV);
	else
		return (COMMAND_EXTERNAL);
}

int		to_exit(t_process **process, t_job **j)
{
	int		i;

	i = 0;
	while (process[0]->argv[i])
		i++;
	if (i == 1 && j[0]->mode == FORE)
	{
		help_to_exit(j[0]);
		exit(0);
	}
	else if (i != 1)
		ft_putendl_fd("exit: too many arguments", process[0]->errorput);
	the_status = -1;
	return (-1);
}

int		trait_built(t_job **j, t_process **process)
{
	if (process[0]->type == COMMAND_EXIT)
		to_exit(&process[0], j);
	else if (process[0]->type == COMMAND_JOBS)
		to_jobs(j[0]);
	else if (process[0]->type == COMMAND_FG)
		to_fg(&process[0], &j[0]);
	else if (process[0]->type == COMMAND_BG)
		to_bg(&process[0], &j[0]);
	else if (process[0]->type == COMMAND_ENV)
		to_env(process[0]);
	else if (process[0]->type == COMMAND_TYPE)
		to_type(process[0]);
	else if (process[0]->type == COMMAND_ECHO)
		to_echo(process[0]);
	else if (process[0]->type == COMMAND_SET)
		to_set(process[0]);
	return (0);
}

int		count_replace_env(char *line, int i, char c)
{
	i++;
	while (line[i] && line[i] != c)
		i++;
	return (i);
}

void	mini_mini_norme(char **line, char *str, int a, int i)
{
	if (str != NULL)
		join_with_something(&line[0], str, a, i);
	else
		join_with_anything2(&line[0], str, a, i);
}
