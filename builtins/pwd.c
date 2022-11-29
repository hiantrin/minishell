/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:34:23 by mouarsas          #+#    #+#             */
/*   Updated: 2022/11/02 21:54:23 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_pwd(t_pi pi)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd)
	{
		ft_putstr_fd(pwd, pi.pipe[1][1]);
		ft_putstr_fd("\n", pi.pipe[1][1]);
		free(pwd);
	}
	return (0);
}
