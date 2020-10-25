/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 04:50:28 by hiantrin          #+#    #+#             */
/*   Updated: 2020/10/25 11:28:28 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	**my_tab_signalmsg(void)
{
	static char *signalmsg[] = {
		"Done", "Hangup", "Interrupt", "Quit", "Illegal instruction",
		"Trace/breakpoint trap", "Aborted", "Bus error",
		"Floating point exception", "Killed", "User defined signal 1",
		"Segmentation fault", "User defined signal 2", "Broken pipe",
		"Alarm clock", "Terminated", "Stack fault", "Child exited", "suspended",
		"Stopped (signal)", "Stopped", "Stopped (tty input)",
		"Stopped (tty output)", "Urgent I/O condition",
		"CPU time limit exceeded", "File size limit exceeded",
		"Virtual timer expired", "Profiling timer expired", "Window changed",
		"I/O possible", "Power failure"
	};

	return (signalmsg);
}

int		search_no_espace(char *str)
{
	int i;

	if (!str)
		return (1);
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int		help_main(int argc, char **argv, char **env)
{
	t_env	*list;

	argc = 0;
	argv = NULL;
	if (!env[0])
	{
		ft_putstr(" ⛔️ \x1b[31m \x1b[1m We need The Linux ");
		ft_putendl("Environment to run this programme ! \033[0m");
		return (0);
	}
	list = create_env(env);
	init_shell();
	g_shell->env = list;
	return (1);
}

int		main(int argc, char **argv, char **env)
{
	char	*line;

	if (help_main(argc, argv, env) == 0)
		return (0);
	while (1)
	{
		ft_putstr("42sh> ");
		get_next_line(0, &line);
		check_zombie();
		if (line && (search_no_espace(line) == 0 ||
			check_if_and_and(&line, 0) == 0))
		{
			free(line);
			continue;
		}
		if (!line || ft_strlen(line) == 0)
			free(line);
		else
			semicolon_parse(line);
	}
	return (0);
}
