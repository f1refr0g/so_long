/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 02:36:53 by abeaudet          #+#    #+#             */
/*   Updated: 2023/04/12 05:03:37 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood3b5(char *sm, t_vector2 size, t_vector2 pos)
{
	if (sm[pos.y * size.x + pos.x + 1] != '1'
		&& sm[pos.y * size.x + pos.x + 1] != 'F')
	{
		sm[pos.y * size.x + pos.x + 1] = 'F';
		pos.x += 1;
		flood(sm, size, pos);
		flood3b5(sm, size, pos);
	}
	if (sm[(pos.y +1) * size.x + pos.x] != '1'
		&& sm[(pos.y +1) * size.x + pos.x] != 'F')
	{
		sm[(pos.y +1) * size.x + pos.x] = 'F';
		pos.y += 1;
		flood(sm, size, pos);
		flood3b5(sm, size, pos);
	}
	flood2(sm, size, pos);
}

//Second function to floodfill.
void	flood3b52(char *sm, t_vector2 size, t_vector2 pos)
{
	if (sm[pos.y * size.x + pos.x - 1] != '1'
		&& sm[pos.y * size.x + pos.x - 1] != 'F')
	{
		sm[pos.y * size.x + pos.x - 1] = 'F';
		pos.x -= 1;
		flood(sm, size, pos);
		flood3b5(sm, size, pos);
	}
	if (sm[(pos.y - 1) * size.x + pos.x] != '1'
		&& sm[(pos.y - 1) * size.x + pos.x] != 'F')
	{
		sm[(pos.y - 1) * size.x + pos.x] = 'F';
		pos.y -= 1;
		flood(sm, size, pos);
		flood3b5(sm, size, pos);
	}
}
