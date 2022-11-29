/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_the_re.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:50:29 by mouarsas          #+#    #+#             */
/*   Updated: 2022/11/09 22:34:33 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	trait_the_type(char *file, int out, int type, int ***pipe)
{
	if (type == 1)
	{
		if (type_one(file, &pipe[0], out) == 0)
			return (0);
	}
	else if (type == 2)
	{
		if (type_two(file, &pipe[0], out) == 0)
			return (0);
	}
	else if (type == 3)
	{
		if (type_three(file, &pipe[0], out) == 0)
			return (0);
	}
	else if (type == 4)
	{
		if (type_four(file, &pipe[0], out) == 0)
			return (0);
	}
	return (1);
}

int	type_one(char *file, int ***pipe, int out)
{
	int	b;

	if (help_type_one(file, pipe[0][2]) == 0)
		return (0);
	b = open(file, O_WRONLY | O_TRUNC);
	if (b == -1)
		return (print_p_d(file, pipe[0][2]));
	if (out == -1 || out == 1)
		if (pipe[0][1][1] != 1 && pipe[0][1][1] != -1)
			close(pipe[0][1][1]);
		pipe[0][1][1] = b;
	if (out == 2)
	{
		if (pipe[0][2][1] != 2 && pipe[0][2][1] != -1)
			close(pipe[0][2][1]);
		pipe[0][2][1] = b;
	}
	if (out == 0)
	{
		if (pipe[0][0][1] != 0 && pipe[0][0][1] != -1)
			close(pipe[0][0][1]);
		pipe[0][0][1] = b;
	}
	return (1);
}

int	type_two(char *file, int ***pipe, int out)
{
	int	b;

	close(open(file, O_CREAT, 0644));
	b = open(file, O_WRONLY | O_APPEND);
	if (b == -1)
		return (print_p_d(file, pipe[0][2]));
	if (out == -1 || out == 1)
	{
		if (pipe[0][1][1] != 1 && pipe[0][1][1] != -1)
			close(pipe[0][1][1]);
		pipe[0][1][1] = b;
	}
	if (out == 2)
	{
		if (pipe[0][2][1] != 2 && pipe[0][2][1] != -1)
			close(pipe[0][2][1]);
		pipe[0][2][1] = b;
	}
	if (out == 0)
	{
		if (pipe[0][0][1] != 0 && pipe[0][0][1] != -1)
			close(pipe[0][0][1]);
		pipe[0][0][1] = b;
	}
	return (1);
}

int	type_three(char *file, int ***pipe, int out)
{
	int	b;

	if (error_type_three(file, pipe[0][2]) == 0)
		return (0);
	b = open(file, O_RDONLY);
	if (b == -1)
		return (print_p_d(file, pipe[0][2]));
	if (out == -1 || out == 0)
		if (pipe[0][0][1] != 0 && pipe[0][0][1] != -1)
			close(pipe[0][0][1]);
		pipe[0][0][1] = b;
	if (out == 2)
	{
		if (pipe[0][2][1] != 2 && pipe[0][2][1] != -1)
			close(pipe[0][2][1]);
		pipe[0][2][1] = b;
	}
	if (out == 1)
	{
		if (pipe[0][1][1] != 1 && pipe[0][1][1] != -1)
			close(pipe[0][1][1]);
		pipe[0][1][1] = b;
	}
	return (1);
}

int	type_four(char *file, int ***pipe, int out)
{
	int	b;

	b = help_redirect(file);
	if (out == -1 || out == 0)
	{
		if (pipe[0][0][1] != 0 && pipe[0][0][1] != -1)
			close(pipe[0][0][1]);
		pipe[0][0][1] = b;
	}
	if (out == 2)
	{
		if (pipe[0][2][1] != 2 && pipe[0][2][1] != -1)
			close(pipe[0][2][1]);
		pipe[0][2][1] = b;
	}
	if (out == 1)
	{
		if (pipe[0][1][1] != 1 && pipe[0][1][1] != -1)
			close(pipe[0][1][1]);
		pipe[0][1][1] = b;
	}
	return (1);
}
