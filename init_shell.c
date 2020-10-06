#include "sh.h"

void	init_shell(void)
{
	pid_t	pid;
	int		i;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	pid = getpid();
	setpgid(pid, pid);
	tcsetpgrp(0, pid);
	shell = (t_shell *)malloc(sizeof(t_shell));
	i = 0;
	while (i < NR_J)
		shell->job[i++] = NULL;
	STATUS_STRING = (char **)malloc(sizeof(char *) * 6);
	STATUS_STRING[5] = NULL;
	STATUS_STRING[0] = ft_strdup("running");
	STATUS_STRING[1] = ft_strdup("done");
	STATUS_STRING[2] = ft_strdup("suspended");
	STATUS_STRING[3] = ft_strdup("continued");
	STATUS_STRING[4] = ft_strdup("terminated");
}
