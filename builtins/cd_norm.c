/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_norm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:29:46 by mouarsas          #+#    #+#             */
/*   Updated: 2022/11/09 21:31:46 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*cd_norm(t_list *list, t_pi pi, int *st)
{
	char	path[255];
	char	*home;
	t_cd	ci;
	char	**tab;
	char	*old_cur;

	ci.st = &st[0];
	getcwd(path, 255);
	old_cur = ft_strdup(path);
	home = env_value("HOME", list);
	tab = (char **)malloc(sizeof(char *) * 3);
	tab[0] = "cd";
	tab[1] = home;
	tab[2] = NULL;
	ci.i = chdir((const char *)home);
	ci.old_cur = old_cur;
	list = change_dir(tab, ci, list, pi);
	free(home);
	free(tab);
	free(old_cur);
	return (list);
}

void	change_dir_norm(t_cd ci, t_list *list, t_pi pi)
{
	char	path[255];
	char	*current;
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * 3);
	current = ft_strjoin("OLDPWD=", ci.old_cur);
	tab[0] = "export";
	tab[1] = current;
	tab[2] = NULL;
	list = ft_export(tab, list, pi);
	free(current);
	getcwd(path, 255);
	current = ft_strjoin("PWD=", path);
	tab[0] = "export";
	tab[1] = current;
	tab[2] = NULL;
	list = ft_export(tab, list, pi);
	free(current);
	free(tab);
}

char	*get_key_env(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (ft_substr(str, 0, i));
		i++;
	}
	return (NULL);
}

t_list	*help_hamza_mustafa_cd(t_pi pi, char *old_cur, int *st, t_list *list)
{
	ft_putstr_fd("minishell: cd: HOME not set\n", pi.pipe[2][1]);
	st[0] = 1;
	free(old_cur);
	return (list);
}

char	*boyka_help_us_echo(int len, char *str, int i)
{
	char	*join;
	char	*tmp;
	char	*temp;
	char	*boyka;

	temp = ft_substr(str, 0, i);
	boyka = ft_itoa(g_isexecuting.old_status);
	tmp = ft_strjoin(temp, boyka);
	free(temp);
	free(boyka);
	boyka = ft_substr(str, i + 2, len - (i + 2));
	join = ft_strjoin(tmp, boyka);
	free(boyka);
	free(tmp);
	free(str);
	return (join);
}
