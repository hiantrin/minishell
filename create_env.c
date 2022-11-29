/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:19:39 by mouarsas          #+#    #+#             */
/*   Updated: 2022/11/09 19:03:43 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_list	*create_env(char **environ)
{
	t_env_list	*head;
	t_env_list	*env;
	t_env_list	*next;
	int			i;

	i = 0;
	env = create_next(environ[i]);
	head = env;
	if (environ[i])
		i++;
	while (environ[i])
	{
		next = create_next(environ[i]);
		env->next = next;
		env = env->next;
		i++;
	}
	return (head);
}

t_env_list	*create_next(char *environ)
{
	t_env_list	*env;

	if (environ == NULL)
		env = NULL;
	else
	{
		env = (t_env_list *)malloc(sizeof(t_env_list));
		env->name = get_name(environ);
		env->environ = get_environ(environ);
		env->next = NULL;
	}
	return (env);
}

char	*get_name(char *environ)
{
	char	*str;
	int		i;

	i = 0;
	while (environ[i] && environ[i] != '=')
		i++;
	str = ft_substr(environ, 0, i);
	return (str);
}

char	*get_environ(char *environ)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	while (environ[j] && environ[j] != '=')
		j++;
	j++;
	i = j;
	while (environ[i])
		i++;
	str = ft_substr(environ, j, i - j);
	return (str);
}

char	*concate(char *path, char *str)
{
	char	*new;
	char	*ptr;

	new = ft_strjoin(path, "/");
	ptr = new;
	new = ft_strjoin(new, str);
	free(ptr);
	return (new);
}
