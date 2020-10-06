#include "sh.h"

int		calculate(char *line)
{
	int count;
	int i;
	int j;

	i = 0;
	j = 0;
	count = 0;
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
			i++;
		j = i;
		while (line[i] != ' ' && line[i] != '\t' && line[i] != '\n'
			&& line[i] != '\0')
			i++;
		if (j != i)
			count++;
	}
	return (count);
}

char	**refil(char **tab, char *line)
{
	int i;
	int j;
	int c;

	i = 0;
	j = 0;
	c = 0;
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
			i++;
		j = i;
		while (line[i] != ' ' && line[i] != '\t' && line[i] != '\n'
			&& line[i] != '\0')
			i++;
		if (j != i)
		{
			tab[c] = ft_strsub(line, j, i - j);
			c++;
		}
	}
	return (tab);
}

char	**make_2d_table(char *line)
{
	int		c;
	char	**tab;
	int		i;

	i = 0;
	c = calculate(line);
	tab = (char **)malloc(sizeof(char *) * (c + 1));
	tab[c] = NULL;
	tab = refil(tab, line);
	return (tab);
}

void	trait(char *line, t_env *list)
{
	t_job	*j;
	int		job_id;
	int		status;
	int		count;

	status = -1;
	count = 0;
	j = make_job(&line);
	if (j->process->type == COMMAND_EXTERNAL)
		job_id = help_trait(&j, list, &count, &status);
	else
		job_id = trait_built(j);
	if (status >= 0 && j->mode == FORE)
		remove_job(j->id);
	else if (j->mode == BACK)
		print_pgid_of_job(job_id);
	if ((status < 0 && j->mode == FORE && count == 0))
		free_job(j);
	free(line);
}
