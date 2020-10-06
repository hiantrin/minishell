#include "sh.h"

int		check_espace(char *str)
{
	int i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (0);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int		main(int argc, char **argv, char **env)
{
	char	*line;
	t_env	*list;

	argc = 0;
	argv = NULL;
	if (!env[0])
	{
		ft_putstr(" ⛔️ \x1b[31m \x1b[1m We need The Linux ");
		ft_putendl("Environment to run this programme ! \033[0m");
		return (0);
	}
	list = create_env(env);
	init_shell();
	shell->env = list;
	while (1)
	{
		ft_putstr("42sh> ");
		get_next_line(0, &line);
		check_zombie();
		if (check_espace(line) != 0)
			trait(line, list);
		else
			free(line);
	}
	return (0);
}
