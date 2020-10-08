#include "sh.h"

int		check_set(char *new)
{
	int		i;
	char	*str;

	i = 0;
	str = get_name(new);
	if (str[0] == '\0' || (str[0] >= '0' && str[0] <= '9') || str[0] == '=')
	{
		free(str);
		return (0);
	}
	while (str[i])
	{
		if (str[i] == '_' || (str[i] >= 'a' && str[i] <= 'z') ||
				str[i] == '=' || (str[i] >= 'A' && str[i] <= 'Z') ||
				(str[i] >= '0' && str[i] <= '9'))
			i++;
		else
		{
			free(str);
			return (0);
		}
	}
	free(str);
	return (1);
}

void	help_setenv(char *command)
{
	t_env	*next;
	char	*str;
	t_env	*head;

	head = shell->env;
	str = get_name(command);
	while (head && head->next != NULL && ft_strcmp(head->name, str) != 0)
		head = head->next;
	if (head == NULL)
		shell->env = create_next(command);
	else if (head && ft_strcmp(head->name, str) != 0)
	{
		next = create_next(command);
		head->next = next;
	}
	else if (head)
	{
		free(head->environ);
		head->environ = get_environ(command);
	}
	free(str);
}

void	to_export(t_process *process, t_job *job, char **argv)
{
	int			i;

	i = 1;
	while (argv[i])
	{
		if (check_set(argv[i]) == 0)
		{
			ft_putstr_fd("minishell: setenv: `", process->errorput);
			ft_putstr_fd(argv[i], process->errorput);
			ft_putendl_fd("': not a valid identifier", process->errorput);
			the_status = -1;
		}
		else if (job->mode == FORE &&
			ft_strchr(argv[i], '=') != NULL)
			help_setenv(argv[i]);
		i++;
	}
}
