/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trait.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:14:36 by hiantrin          #+#    #+#             */
/*   Updated: 2020/10/25 12:14:02 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		calculate(char *line)
{
	int count;
	int i;
	int j;

	i = 0;
	j = 0;
	count = 0;
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
			i++;
		j = i;
		while (line[i] != ' ' && line[i] != '\t' && line[i] != '\n'
			&& line[i] != '\0')
			i++;
		if (j != i)
			count++;
	}
	return (count);
}

char	**refil(char **tab, char *line)
{
	int i;
	int j;
	int c;

	i = 0;
	j = 0;
	c = 0;
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
			i++;
		j = i;
		while (line[i] != ' ' && line[i] != '\t' && line[i] != '\n'
			&& line[i] != '\0')
			i++;
		if (j != i)
		{
			tab[c] = ft_strsub(line, j, i - j);
			c++;
		}
	}
	return (tab);
}

char	**make_2d_table(char *line)
{
	int		c;
	char	**tab;
	int		i;

	i = 0;
	c = calculate(line);
	tab = (char **)malloc(sizeof(char *) * (c + 1));
	tab[c] = NULL;
	tab = refil(tab, line);
	return (tab);
}

void	help_trait_v2(t_job *j, int count)
{
	int		job_id;
	int		status;

	status = -1;
	if ((count == 0 && j->mode == BACK) || count != 0)
		job_id = insert_job(j);
	if (j->mode == FORE && count != 0)
		help_to_wait(j, &status);
	if (status >= 0 && j->mode == FORE)
	{
		if (g_the_status != 127)
			g_the_status = status;
		if (g_the_status != 127 && g_the_status > 0)
			g_the_status = 1;
		remove_job(j->id);
	}
	else if (j->mode == BACK)
		print_pgid_of_job(job_id);
	if ((status < 0 && j->mode == FORE && count == 0))
		free_job(j);
}

void	trait(char *line, int mode)
{
	t_job		*j;
	int			count;
	t_process	*process;
	int			h;

	count = 0;
	j = make_job(line, mode);
	process = j->process;
	while (process)
	{
		make_the_put(&process, &j);
		h = redirect(&process);
		if (h == 1 && search_no_espace(process->command) == 1
			&& (process->argv = mini_filter_h(&(process->command),
			g_shell->env)))
			final_help(&process, &j, &count);
		close_pipe(process, j);
		process = process->next;
	}
	help_trait_v2(j, count);
}
