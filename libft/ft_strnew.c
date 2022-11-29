/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:20:15 by mouarsas          #+#    #+#             */
/*   Updated: 2022/11/05 21:29:08 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*r;
	size_t	j;

	j = 0;
	r = (char *)malloc(size + 1 * sizeof(*r));
	if (!r)
		return (NULL);
	while (j <= size)
		r[j++] = '\0';
	return (r);
}
