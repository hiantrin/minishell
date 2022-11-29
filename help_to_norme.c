/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_to_norme.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:14:01 by mouarsas          #+#    #+#             */
/*   Updated: 2022/11/09 19:57:02 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*help_mini_or_or(t_list *list, char **new)
{
	free_2d(new);
	return (list);
}

int	help_to_redirect_with_fd(char *str, int *i, int j)
{
	i[0] = j;
	j = atoi(str);
	free(str);
	return (j);
}

void	ft_mini_help_ft_trait(char **argv, t_list *list, \
		t_status *status, char *commande)
{
	if (ft_strchr(argv[0], '/'))
		ok_x_path(argv, list, status->pi, &(status->status));
	else
		another_mini_help_for_mini2(&status[0], commande);
}

t_list	*help_to_norme_ft_trait0(t_list *list, char *line, \
		t_norme3 *norme3, char ***str)
{
	norme3->status = complete_the_pipe(&line);
	if (norme3->status != 1)
	{
		str[0] = NULL;
		return (list);
	}
	str[0] = split_command(line, '|');
	norme3->status = check_redirections(str[0]);
	if (norme3->status == 0)
	{
		str[0] = NULL;
		return (list);
	}
	return (list);
}

t_list	*last_help_for_ft_trait0(t_list *list, t_norme2 *norme, t_status status)
{
	norme->status = status.status;
	free(norme->str);
	return (list);
}
