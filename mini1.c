/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:57:08 by mouarsas          #+#    #+#             */
/*   Updated: 2022/11/09 01:53:32 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_trait0v2(t_list *list, char *line)
{
	char		**new;
	int			i;
	t_norme3	norme;

	i = 0;
	new = split_command(line, ';');
	free(line);
	while (new[i])
	{
		norme.str = new;
		norme.p0 = 0;
		if (check_line(new[i]) != 0)
		{
			list = and_and(list, new[i], norme);
			if (list == NULL)
				return (NULL);
		}
		i++;
	}
	free_2d(new);
	return (list);
}

t_list	*ft_trait0(t_list *list, char *line, t_norme3 *norme3, int i)
{
	char		**str;
	t_pi		*pi;
	t_norme2	norme;

	list = help_to_norme_ft_trait0(list, line, &norme3[0], &str);
	if (str == NULL)
		return (list);
	while (str[++i])
	{
		free_of_trait0v2(pi, i);
		pi = (t_pi *)malloc(sizeof(t_pi));
		pi->pipe = alloc_for_int();
		norme3->p0 = trait_the_pi(str[i + 1], &pi[0], norme3->p0);
		pi->new = NULL;
		if (str[i + 1])
			pi->new = ft_strdup(str[i + 1]);
		anathor_help_for_mini1(str[i], norme3, &norme);
		list = ft_trait1(&norme, list, pi, str);
		if (list == NULL)
			return (NULL);
	}
	free_of_trait0(pi, i, str, &norme.status);
	norme3->status = norme.status;
	return (list);
}

void	wait_null(int p2, int i, int *status)
{
	int	j;
	int	n;

	j = 0;
	if (p2 != 0)
		close(p2);
	while (j < i)
	{
		if (j == (i - 1))
			wait(&n);
		else
			wait(NULL);
		j++;
	}
	if (WEXITSTATUS(n) && status[0] == 2)
		status[0] = 0;
}

int	**alloc_for_int(void)
{
	int	i;
	int	**pipe;

	i = 0;
	pipe = (int **)malloc(sizeof(int *) * 3);
	pipe[0] = (int *)malloc(sizeof(int) * 2);
	pipe[0][0] = 0;
	pipe[0][1] = -1;
	pipe[1] = (int *)malloc(sizeof(int) * 2);
	pipe[1][0] = 1;
	pipe[1][1] = 1;
	pipe[2] = (int *)malloc(sizeof(int) * 2);
	pipe[2][0] = 2;
	pipe[2][1] = 2;
	return (pipe);
}

void	close_pi(t_pi *pi)
{
	if (pi->pipe[0][1] != 0 && pi->pipe[0][1] != -1)
		close(pi->pipe[0][1]);
	if (pi->pipe[1][1] != 1 && pi->pipe[1][1] != -1)
		close(pi->pipe[1][1]);
	if (pi->pipe[2][1] != 2 && pi->pipe[2][1] != -1)
		close(pi->pipe[2][1]);
}
