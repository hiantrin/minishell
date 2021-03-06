/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_help_v2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 04:52:57 by hiantrin          #+#    #+#             */
/*   Updated: 2020/10/23 04:52:58 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		print_n_x(char *file, int pipe)
{
	ft_putstr_fd("42sh: ", pipe);
	ft_putstr_fd(file, pipe);
	ft_putendl_fd(": no such file or directory", pipe);
	return (0);
}

int		help_redirect(char *file, char *line)
{
	int		p[2];

	pipe(p);
	while (1)
	{
		line = NULL;
		while (line == NULL || search_no_espace(line) == 0)
		{
			ft_memdel(&line);
			ft_putstr("herdoc> ");
			get_next_line(0, &line);
			if (!line)
			{
				ft_memdel(&line);
				line = ft_strdup(file);
			}
		}
		if (ft_strcmp(line, file) == 0)
			break ;
		ft_putendl_fd(line, p[1]);
		ft_memdel(&line);
	}
	ft_memdel(&line);
	close(p[1]);
	return (p[0]);
}
