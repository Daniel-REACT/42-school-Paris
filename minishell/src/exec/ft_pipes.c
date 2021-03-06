/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:26:15 by daziza            #+#    #+#             */
/*   Updated: 2021/05/16 20:26:17 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int
	link_commands(t_command *src, t_command *dst)
{
	int	pipes[2];
	int	ret;

	if (!src || !dst)
		return (0);
	ret = pipe(pipes);
	src->fd_output = pipes[1];
	dst->fd_input = pipes[0];
	return (ret);
}

int
	pipe_nodes(t_list *commands)
{
	t_list	*current;
	int		ret;

	current = commands;
	ret = 0;
	while (current && current->next && ret == 0)
	{
		ret = link_commands(current->content, current->next->content);
		current = current->next;
	}
	return (ret);
}
