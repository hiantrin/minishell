#include "sh.h"

void	help_to_wait(t_job *j, int *status)
{
	tcsetpgrp(0, j->pgid);
	status[0] = wait_for_job(j->id, 0);
	signal(SIGTTOU, SIG_IGN);
	tcsetpgrp(0, getpid());
	signal(SIGTTOU, SIG_DFL);
}

void	final_help(t_process **process, t_job **j, int *count)
{
	t_env	*save;

	process[0]->argv = manage_variables(process[0]->argv, &save);
	if (process[0]->argv)
	{
		process[0]->type = get_command_type(process[0]->argv[0]);
		if (process[0]->type == COMMAND_EXTERNAL)
			help_trait(&j[0], &process[0], &count[0]);
		else
			back_or_fore(&j[0], &process[0]);
	}
	manage_variables2(save);
}

int		print_exit_error(char *str)
{
	if (check_if_is_num(str) == 0)
	{
		ft_putstr("42sh: exit: ");
		ft_putstr(str);
		ft_putendl(" : numeric argument required");
		return (-1);
	}
	else
		return (atoi(str));
}

int		if_numeric_or_percent(char *str)
{
	int i;
	int id;

	i = 0;
	while (str[i] == '%')
		i++;
	if (str[i] == '\0' && search_last() == 0)
		return (0);
	if (str[i] == '\0' && search_last() != 0)
		return (search_last());
	if (if_numeric(&str[i]) == 0 || (id = atoi(&str[i])) > 29 || shell->job[id] == NULL)
		return (0);
	else
		return (id);
}

// (if_numeric(process->argv[1]) == 0 ||
// 		(id = atoi(process->argv[1])) > 29 ||
// 		shell->job[id] == NULL)))