/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:51:01 by mouarsas          #+#    #+#             */
/*   Updated: 2022/11/09 20:25:47 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*read_trait_commande(char *commande, t_list *list, char **argv)
{
	argv = NULL;
	commande = readline("Minishell>$ ");
	if (commande != NULL)
	{
		g_isexecuting.status = 1;
		commande = ft_filter_quote(commande);
		if (commande && (search_no_espace(commande) == 0 || \
			check_if_and_and(&commande, 0) == 0))
		{
			ft_memdel(&commande);
			return (list);
		}
		if (!commande || ft_strlen(commande) == 0)
		{
			ft_memdel(&commande);
			return (list);
		}
		add_history(commande);
		list = ft_trait0v2(list, commande);
		if (list == NULL)
			return (NULL);
	}
	else
		exit (10);
	return (list);
}

t_list	*stock_list(char **env)
{
	t_list	*list;
	t_list	*tmp;
	int		i;

	i = 0;
	while (env[i])
	{
		if (i == 0)
		{
			list = new_list(env[i]);
			tmp = list;
		}
		else
		{
			tmp->next = new_list(env[i]);
			tmp = tmp->next;
		}
		i++;
	}
	return (list);
}

void	handle(int sig)
{
	if (sig == SIGINT && !g_isexecuting.status)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	ft_signal(void)
{
	if (signal(SIGINT, handle) == SIG_ERR || \
	signal(SIGQUIT, handle) == SIG_ERR)
	{
		write(2, "sig error\n", 10);
		exit (1);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_list		*list;
	char		*commande;

	argc = 0;
	if (!env[0])
		return (0);
	list = stock_list(env);
	list->first = list;
	commande = ft_strnew(0);
	rl_catch_signals = 0;
	ft_signal();
	while (1)
	{
		g_isexecuting.status = 0;
		list = read_trait_commande(commande, list, argv);
		if (list)
			continue ;
		else
			exit(0);
	}
	free_mylist(list->first);
	return (0);
}
