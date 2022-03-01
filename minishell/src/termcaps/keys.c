/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:32:43 by daziza            #+#    #+#             */
/*   Updated: 2021/05/16 20:32:45 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void
	exec_key(t_line *line, char *key)
{
	if (*key == 0x15)
		return (cut_line(line));
	if (*key == 0x19 || *key == -62)
		return (paste_line(line));
	if (*key >= 32 && *key < 127)
		return (insert_char(line, *key));
	if (*key == 127)
		return (delete_char(line));
	if (*key == ESC_CHAR)
		return (exec_cap(key)(line));
}

int
	get_key(char *key, char do_buf)
{
	int			rd;
	static char	bfrd;

	if (bfrd)
	{
		*key = bfrd;
		bfrd = 0;
		return (0);
	}
	rd = read(0, key, 1);
	if (*key == '\4')
		return (0);
	if (*key == do_buf)
		bfrd = *key;
	if (*key == ESC_CHAR)
		rd = read(0, key + 1, 10) + 1;
	key[rd] = '\0';
	return (rd);
}
