/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soukamar <soukamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:12:12 by soukamar          #+#    #+#             */
/*   Updated: 2021/05/16 20:12:15 by soukamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void
	*vect_ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)b)[i] = (char)c;
		i++;
	}
	return (b);
}

void
	*vect_ft_memcpy(void *dst, void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

void
	*vect_ft_calloc(size_t count, size_t size)
{
	void	*buff;

	buff = malloc(count * size);
	return (vect_ft_memset(buff, 0, count * size));
}
