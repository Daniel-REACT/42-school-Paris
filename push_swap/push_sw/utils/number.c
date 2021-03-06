/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:45:27 by daziza            #+#    #+#             */
/*   Updated: 2021/04/19 19:45:28 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

size_t	getlen(t_item *item)
{
	int	len;

	len = 0;
	while (item)
	{
		len++;
		item = item->next;
	}
	return (len);
}

int		getmin(t_item *item)
{
	int	min;

	if (!item)
		return (0);
	min = item->data;
	while (item->next)
	{
		item = item->next;
		if (item->data < min)
			min = item->data;
	}
	return (min);
}

int		getmax(t_item *item)
{
	int	max;

	if (!item)
		return (0);
	max = item->data;
	while (item->next)
	{
		item = item->next;
		if (item->data > max)
			max = item->data;
	}
	return (max);
}

size_t	getindex(t_item *item, int nbr)
{
	size_t	index;

	index = 0;
	while (item)
	{
		if (item->data == nbr)
			return (index);
		index++;
		item = item->next;
	}
	return (0);
}

ssize_t	getpivot(t_number number, size_t index, size_t division)
{
	ssize_t	max;
	ssize_t	min;

	max = getmax(number.a);
	min = getmin(number.a);
	if (index < division)
		return ((max - min) * index / division + min);
	return (max);
}
