/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:58:23 by mouarsas          #+#    #+#             */
/*   Updated: 2022/11/07 20:44:35 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	help_the_systeme(t_norme norme)
{
	if (norme.pi.p != 0)
		close(norme.pi.p);
	if (norme.pi.pipe[1][1] == -1)
		close(1);
	else
		dup2(norme.pi.pipe[1][1], 1);
	if (norme.pi.pipe[0][1] == -1)
		close(0);
	else
		dup2(norme.pi.pipe[0][1], 0);
	if (norme.pi.pipe[2][1] == -1)
		close(2);
	else
		dup2(norme.pi.pipe[2][1], 2);
}

t_list	*ft_trait1(t_norme2 *norme, t_list *list, t_pi *pi,
			char **tab)
{
	int			h;
	char		**newargv;
	t_status	status;

	h = 1;
	newargv = NULL;
	if (ft_strchr(norme->str, '>') != NULL || \
		ft_strchr(norme->str, '<') != NULL)
		h = redirect(&pi[0], &(norme->str), &(norme->status));
	newargv = mini_filter_h(&(norme->str), my_magic(list));
	status.status = norme->status;
	if (newargv != NULL)
	{
		status.pi = pi[0];
		if (newargv[0] && ft_strcmp(newargv[0], "exit") == 0 && pi->new == NULL)
		{
			if (newargv[1] == NULL)
				free_2d(tab);
			return (ft_my_exit(newargv, list, pi, &norme[0]));
		}
		if (h == 1 && ft_strcmp(newargv[0], "exit") != 0)
			list = ft_trait(newargv[0], list, newargv, &status);
	}
	return (last_help_for_ft_trait0(list, &norme[0], status));
}

int	trait_the_pi(char *str, t_pi *pi, int p0)
{
	int	p[2];

	if (str != NULL)
		pipe(p);
	else
	{
		p[1] = 1;
		p[0] = 0;
	}
	pi->p = p[0];
	pi->pipe[0][1] = p0;
	pi->pipe[1][1] = p[1];
	return (p[0]);
}

int	error_type_three(char *file, int *error)
{
	struct stat	l;

	if (lstat(file, &l) == -1)
		return (print_n_x(file, error));
	if (S_ISDIR(l.st_mode))
		return (print_i_d(file, error));
	return (1);
}

void	free_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
