#include "sh.h"

int		jump_quote(char *s, int end)
{
	char	c;

	c = s[end];
	if (c == 92)
		end++;
	else if (c == 34 || c == 39)
	{
		end++;
		while (s[end] && s[end] != c)
		{
			if (s[end] == 92 && c == 34)
				end = end + 2;
			else
				end++;
		}
	}
	if (s[end] != '\0')
		end++;
	return (end);
}

int		leno(char *s)
{
	int	start;
	int end;
	int i;

	i = 0;
	end = 0;
	start = 0;
	while (s[start] != '\0')
	{
		while (s[start] != '\0' && (s[start] == ' ' || s[start] == '\t'))
			start++;
		if (s[start] == '\0')
			break ;
		end = start;
		while (s[end] != ' ' && s[end] != '\0' && s[start] != '\t')
			end = jump_quote(s, end);
		start = end;
		i++;
	}
	return (i);
}

char	*help_move_s_q(char *str)
{
	int		start;
	char	c;
	int		end;
	int		type;

	type = 0;
	start = 0;
	end = 0;
	while (str[start])
	{
		c = str[start];
		if (c == 34 || c == 39)
		{
			if (type == 0)
				str = replace_by_s_q(str, &start, &end, 0);
			start++;
			while (str[start] && str[start] != c)
			{
				if (str[start] == 92 && c == 34)
					start = start + 2;
				else
					start++;
			}
			start++;
			str = replace_by_s_q(str, &start, &end, 1);
			type = 1;
		}
		else if (c == 92)
		{
			start = start + 2;
			type = 0;
		}
		else
		{
			start++;
			type = 0;
		}
	}
	if (type == 0)
		str = replace_by_s_q(str, &start, &end, 0);
	return (str);
}

char	**ft_strsplito(char *s)
{
	int		start;
	int		end;
	char	**str;
	int		i;

	i = 0;
	start = 0;
	end = 0;
	str = (char **)malloc(sizeof(char *) * (leno(s) + 1));
	while (i < leno(s))
	{
		while (s[start] != '\0' && (s[start] == ' ' || s[start] == '\t'))
			start++;
		end = start;
		while (s[end] != ' ' && s[end] != '\0' && s[start] != '\t')
			end = jump_quote(s, end);
		str[i] = ft_strsub(s, start, (end - start));
		str[i] = help_move_s_q(str[i]);
		start = end;
		i++;
	}
	str[i] = NULL;
	return (str);
}

char	**mini_filter_h(char **str, t_env *env)
{
	int			i;
	char		**tab;

	i = 0;
	str[0] = replace_with_env(str[0], env, i);
	str[0] = replace_home(str[0], env);
	if (search_no_espace(str[0]) == 0)
		return (NULL);
	tab = ft_strsplito(str[0]);
	return (tab);
}
