/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:28:38 by mouarsas          #+#    #+#             */
/*   Updated: 2022/11/09 01:51:01 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	help_type_one(char *file, int *error)
{
	struct stat	l;

	close(open(file, O_CREAT, 0644));
	lstat(file, &l);
	if (S_ISDIR(l.st_mode))
		return (print_i_d(file, error));
	return (1);
}

void	free_of_trait0(t_pi *pi, int i, char **str, int *status)
{
	wait_null(pi->pipe[0][1], i, &status[0]);
	free_my_pi(pi);
	free_2d(str);
	g_isexecuting.old_status = status[0];
}

void	free_of_trait0v2(t_pi *pi, int i)
{
	if (i != 0)
		close_pi(pi);
	if (i != 0)
		free_my_pi(pi);
}

int	parse_to_two(char *file, int out, int type, int ***pipe)
{
	if (file[0] == '&')
	{
		if (trait_the_and(file, out, type, &pipe[0]) == 0)
		{
			free(file);
			return (0);
		}
	}
	else
	{
		if (trait_the_type(file, out, type, &pipe[0]) == 0)
		{
			free(file);
			return (0);
		}
	}
	return (2);
}

int	check_if_is_num(char *file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (file[i] < 48 || file[i] > 57)
			return (0);
		i++;
	}
	return (1);
}
