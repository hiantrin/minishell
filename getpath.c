/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:24:00 by mouarsas          #+#    #+#             */
/*   Updated: 2022/11/05 22:42:45 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ls(char *path)
{
	char	**str;
	int		i;

	i = n_str(path);
	str = (char **)malloc(sizeof(char *) * (i + 1));
	str[i] = NULL;
	remplir(str, path);
	return (str);
}

int	n_str(char *path)
{
	int				i;
	DIR				*dir;
	struct dirent	*dirent;

	i = 0;
	dir = opendir(path);
	if (dir == NULL)
	{
		perror("Error: ");
		exit(1);
	}
	dirent = readdir(dir);
	while (dirent)
	{
		if (dirent->d_name[0] != '.')
			i++;
	}
	closedir(dir);
	return (i);
}

void	remplir(char **str, char *path)
{
	int				i;
	struct dirent	*dirent;
	DIR				*dir;

	i = 0;
	dir = opendir(path);
	if (dir == NULL)
	{
		write(1, "Error! Unable to open directory.", 32);
		exit(1);
	}
	dirent = readdir(dir);
	while (dirent)
	{
		if (dirent->d_name[0] != '.')
		{
			str[i] = ft_strdup(dirent->d_name);
			i++;
		}
	}
	closedir(dir);
}
