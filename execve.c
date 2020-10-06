#include "sh.h"

char	**list_to_tab(t_env *env)
{
	int		i;
	char	**tab;
	char	*new;
	t_env	*head;

	head = env;
	i = 0;
	while (env != NULL)
	{
		i++;
		env = env->next;
	}
	tab = (char **)malloc(sizeof(char *) * i + 1);
	tab[i] = NULL;
	i = 0;
	while (head != NULL)
	{
		new = ft_strjoin(head->name, "=");
		tab[i++] = ft_strjoin(new, head->environ);
		free(new);
		head = head->next;
	}
	return (tab);
}

char	*join_path(char *path1, char *path2)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(path1, "/");
	tmp2 = ft_strjoin(tmp, path2);
	free(tmp);
	return (tmp2);
}

char	*search_join(char **path, char *str, char **print)
{
	int			i;
	char		*command;
	struct stat	l;
	DIR			*dir;

	i = 0;
	dir = NULL;
	print[0] = NULL;
	while (path[i])
	{
		command = join_path(path[i], str);
		if (lstat(command, &l) > -1)
			return (command);
		free(command);
		i++;
	}
	if (ft_strchr(str, '/') && (lstat(str, &l) > -1))
		return (help_search_join(str, dir, &print[0]));
	print[0] = ft_strjoin("42sh : command not found: ", str);
	return (NULL);
}

char	*search_env(t_env *list)
{
	t_env	*first;

	first = list;
	while (first)
	{
		if (ft_strcmp(first->name, "PATH") == 0)
			return (first->environ);
		first = first->next;
	}
	return (NULL);
}

void	exec_command(t_job **job, t_env *list)
{
	char	**path;
	char	*command;
	char	*print;

	job[0]->process->status = STATUS_RUNNING;
	print = NULL;
	if (search_env(list))
	{
		path = ft_strsplit(search_env(list), ':');
		command = search_join(path, job[0]->process->argv[0], &print);
		free_2d(path);
		execve_help(list, &job[0], command, print);
		free(command);
		free(print);
	}
}
