/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:33:36 by mouarsas          #+#    #+#             */
/*   Updated: 2022/11/09 21:30:35 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_newline(char *s)
{
	int	i;

	i = 0;
	while (s[++i])
		if (s[i] != 'n')
			return (0);
	return (1);
}

int	laarebi_help_us_please(int sig, t_pi pi, char *str)
{
	ft_putstr_fd(str, pi.pipe[1][1]);
	return (sig);
}

int	check_n(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
	{
		i = 1;
		while (str[i])
		{
			if (str[i] != 'n')
				return (1);
			i++;
		}
		return (-2);
	}
	return (1);
}

char	*switch_to_old_status(char *str)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if (str[i] == '$')
		{
			if (str[i + 1] == '?')
				str = boyka_help_us_echo(len, str, i);
		}
		i++;
	}
	return (str);
}

int	ft_echo(char **av, t_pi pi, int i)
{
	int	sig;
	int	check;

	while (av[i])
	{
		check = check_n(av[i]);
		if (check == -2)
		{
			i++;
			sig = -2;
		}
		else
			break ;
	}
	while (av[i])
	{
		av[i] = switch_to_old_status(av[i]);
		ft_putstr_fd(av[i], pi.pipe[1][1]);
		if (av[i + 1])
			ft_putstr_fd(" ", pi.pipe[1][1]);
		i++;
	}
	if (sig != -2)
		ft_putstr_fd("\n", pi.pipe[1][1]);
	return (1);
}
