/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:59:14 by mouarsas          #+#    #+#             */
/*   Updated: 2022/11/09 20:02:57 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_mylist(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		ft_memdel(&tmp->str);
		tmp->str = NULL;
		free(tmp);
		tmp = tmp->next;
	}
}

void	ft_print(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putstr(str[i++]);
}

int	ok_x_pathv2(t_list *list, DIR *dir, char **env, t_norme norme)
{
	int	pid;

	pid = 0;
	dir = opendir(norme.env[0]);
	if (access(norme.env[0], X_OK) == 0 && dir == NULL)
	{
		env = my_magic(list);
		pid = fork();
		if (pid == 0)
		{
			signal(SIGQUIT, SIG_DFL);
			help_the_systeme(norme);
			execve(norme.env[0], norme.env, env);
		}
		free(env);
	}
	else
	{
		if (dir != NULL)
			closedir(dir);
		ft_putstr_fd("minishell: permission denied:", norme.pi.pipe[2][1]);
		ft_putendl_fd(norme.env[0], 2);
		return (0);
	}
	return (1);
}

void	ok_x_path(char **argv, t_list *list, t_pi pi, int *status)
{
	struct stat	sb;
	char		**env;
	DIR			*dir;
	t_norme		norme;

	env = NULL;
	dir = NULL;
	if (argv[0] && lstat(argv[0], &sb) > -1)
	{
		norme.env = argv;
		norme.pi = pi;
		status[0] = ok_x_pathv2(list, dir, env, norme);
	}
	else
	{
		ft_putstr_fd("minishell: no such file or directory: ", pi.pipe[2][1]);
		ft_putendl_fd(argv[0], pi.pipe[2][1]);
		status[0] = 0;
	}
}

t_list	*ft_trait(char *commande, t_list *list, char **argv, t_status *status)
{
	if (!commande)
		return (list);
	if (!ft_strcmp(commande, "echo"))
		list = ft_myshell(argv, 1, list, &status[0]);
	else if (!ft_strcmp(commande, "cd"))
		list = ft_myshell(argv, 2, list, &status[0]);
	else if (!ft_strcmp(commande, "exit"))
		list = ft_myshell(argv, 3, list, &status[0]);
	else if (!ft_strcmp(commande, "unset"))
		list = ft_myshell(argv, 4, list, &status[0]);
	else if (!ft_strcmp(commande, "export"))
		list = ft_myshell(argv, 5, list, &status[0]);
	else if (!ft_strcmp(commande, "env"))
		list = ft_myshell(argv, 6, list, &status[0]);
	else if (!ft_strcmp(commande, "pwd"))
		list = ft_myshell(argv, 7, list, &status[0]);
	else if (commande[0] && \
		search_commande(list, commande, argv, status->pi) == 0)
		ft_mini_help_ft_trait(argv, list, &status[0], commande);
	ft_fresh(argv);
	return (list);
}
