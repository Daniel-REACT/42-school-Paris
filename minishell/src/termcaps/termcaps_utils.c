/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:33:18 by daziza            #+#    #+#             */
/*   Updated: 2021/05/16 20:33:20 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

int		ft_putchar(int c)
{
	return (write(1, &c, 1));
}

void	cap(char *tc)
{
	char *tstr;

	tstr = tgetstr(tc, NULL);
	tputs(tstr, 1, ft_putchar);
}

void	realloc_line(t_line *line)
{
	char *cpy;

	cpy = ft_calloc(line->max_len + BUFF_SIZE, 1);
	if (!cpy)
	{
		free(line);
		exit(1);
	}
	ft_memmove(cpy, line->line, line->max_len);
	free(line->line);
	line->line = cpy;
	line->max_len += BUFF_SIZE;
}

int		key_is(char *key, char *cap)
{
	if (ft_strncmp(key, tgetstr(cap, NULL), ESC_LEN))
		return (0);
	return (1);
}
