/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:32:31 by daziza            #+#    #+#             */
/*   Updated: 2021/05/16 20:32:33 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void
	insert_char(t_line *line, char c)
{
	t_point	tmp;

	if (line->len >= line->max_len - 1)
		realloc_line(line);
	ft_memmove(line->line + line->r_cur_pos + 1, line->line + line->r_cur_pos,
			(line->max_len - line->r_cur_pos) - 1);
	line->line[line->r_cur_pos] = c;
	line->r_cur_pos++;
	line->len++;
	line->cursor_pos.x++;
	wrap_line(line);
	tmp = line->cursor_pos;
	clear_line(line);
	cap("im");
	write(0, line->line, line->len);
	cap("ei");
	line->cursor_pos = tmp;
	update_cursor(line);
}
