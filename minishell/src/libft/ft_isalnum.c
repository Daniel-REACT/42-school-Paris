/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:15:11 by daziza            #+#    #+#             */
/*   Updated: 2021/05/16 20:15:13 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	return (('0' <= c && c <= '9') || ('A' <= c && c <= 'Z')
			|| ('a' <= c && c <= 'z'));
}