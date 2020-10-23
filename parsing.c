/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 04:51:12 by hiantrin          #+#    #+#             */
/*   Updated: 2020/10/23 04:51:13 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	jobs_parse(char *line)
{
	int i;

	i = 0;
	the_jobs = split_job(line);
	while (the_jobs[i])
	{
		if (check_line(the_jobs[i]))
		{
			if (the_jobs[i + 1] != NULL)
				trait(the_jobs[i], BACK);
			else
				trait(the_jobs[i], FORE);
		}
		i++;
	}
	free_2d(the_jobs);
	the_jobs = NULL;
}

void	or_or_parse(char *line, int fo)
{
	int i;

	i = 0;
	or_or = split_and_and(line, '|');
	while (or_or[i])
	{
		if (check_line(or_or[i]))
		{
			if (fo == 0 || (i == 0 && the_status == 0)
				|| (i != 0 && the_status != 0))
				jobs_parse(or_or[i]);
			if (the_status == 0)
				break ;
		}
		i++;
	}
	free_2d(or_or);
	or_or = NULL;
}

void	and_and_parse(char *line)
{
	int i;

	i = 0;
	and_and = split_and_and(line, '&');
	while (and_and[i])
	{
		if (check_line(and_and[i]))
			or_or_parse(and_and[i], i);
		i++;
	}
	free_2d(and_and);
	and_and = NULL;
}

void	semicolon_parse(char *line)
{
	int	i;

	i = 0;
	semicolon = split_command(line, ';');
	free(line);
	while (semicolon[i])
	{
		if_exit = semicolon[i + 1];
		if (check_line(semicolon[i]))
			and_and_parse(semicolon[i]);
		i++;
	}
	free_2d(semicolon);
	semicolon = NULL;
}
