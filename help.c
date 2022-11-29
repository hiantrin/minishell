/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:30:13 by mouarsas          #+#    #+#             */
/*   Updated: 2022/11/02 22:43:42 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

char	**split_command(char *line, char s)
{
	char	**command;
	int		count;

	count = count_command(line, s);
	command = (char **)malloc(sizeof(char *) * count + 1);
	command[count] = NULL;
	help_bonus(line, command, s, count);
	return (command);
}

void	help_bonus(char *line, char **command, char s, int i)
{
	char	c;
	int		j;
	int		a;

	i = 0;
	a = 0;
	j = 0;
	while (line[i])
	{
		c = line[i];
		if (c == 34 || c == 39)
		{
			i++;
			while (line[i] && line[i] != c)
				i++;
		}
		else if (c == s)
		{
			command[a++] = ft_substr(line, j, i - j);
			j = i + 1;
		}
		if (line[i] != '\0')
			i++;
	}
	command[a] = ft_substr(line, j, i - j);
}

int	count_command(char *line, char s)
{
	int		i;
	int		count;
	char	c;

	count = 1;
	i = 0;
	while (line[i])
	{
		c = line[i];
		if (c == 34 || c == 39)
		{
			i++;
			while (line[i] != c)
				i++;
		}
		else if (c == s)
			count++;
		if (line[i] != '\0')
			i++;
	}
	return (count);
}

char	**mini_filter_h(char **str, char **command)
{
	int			i;
	t_env_list	*env;
	char		**tab;
	t_env_list	*next;

	i = 0;
	env = create_env(command);
	free(command);
	str[0] = replace_with_env(str[0], env, i);
	str[0] = replace_home(str[0], env);
	while (env != NULL)
	{
		free(env->name);
		free(env->environ);
		next = env->next;
		free(env);
		env = next;
	}
	if (search_no_espace(str[0]) == 0)
		return (NULL);
	tab = ft_strsplito(str[0]);
	return (tab);
}
