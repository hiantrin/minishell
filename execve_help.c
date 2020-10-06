#include "sh.h"

char	*help_search_join(char *str, DIR *dir, char **print)
{
	if (access(str, X_OK) == 0 &&
		(dir = opendir(str)) == NULL)
		return (ft_strdup(str));
	else
	{
		if (dir != NULL)
			closedir(dir);
		print[0] = ft_strjoin("42sh : permission denied: ", str);
		return (NULL);
	}
}

void	help_execve_help(t_job **job)
{
	job[0]->process->pid = getpid();
	if (job[0]->pgid > 0)
		setpgid(0, job[0]->pgid);
	else
	{
		job[0]->pgid = job[0]->process->pid;
		setpgid(0, job[0]->pgid);
	}
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGTSTP, SIG_DFL);
	signal(SIGTTIN, SIG_DFL);
	signal(SIGTTOU, SIG_DFL);
	signal(SIGCHLD, SIG_DFL);
}

void	execve_help(t_env *list, t_job **job, char *command, char *print)
{
	pid_t	pid;
	char	**tab;

	tab = list_to_tab(list);
	pid = fork();
	if (pid == 0)
	{
		help_execve_help(&job[0]);
		execve(command, job[0]->process->argv, tab);
		ft_putendl(print);
		exit(0);
	}
	else
	{
		job[0]->process->pid = pid;
		if (job[0]->pgid > 0)
			setpgid(pid, job[0]->pgid);
		else
		{
			job[0]->pgid = pid;
			setpgid(pid, job[0]->pgid);
		}
	}
	free_2d(tab);
}
