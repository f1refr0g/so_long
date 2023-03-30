/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:52:32 by abeaudet          #+#    #+#             */
/*   Updated: 2023/03/29 20:30:15 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	simulate_map(t_map *map)
{
	printf("sim1");
	char		*temp_map;
	t_vector2	pos;
	t_vector2	mapsize;

	pos.y = map->player->y;
	pos.x = map->player->x;
	mapsize.x = map->width;
	mapsize.y = map->height;
	temp_map = ft_strdup(map->sm);
	flood(temp_map, mapsize, &pos);
	lookstring(temp_map);
}

void	flood(char *sm, t_vector2 size, t_vector2 *pos)
{
	if (sm[pos->y * size.y + pos->x - 1] != '1')
	{
		sm[pos->y * size.y + pos->x - 1] = 'F';
		pos->x--;
		flood(sm, size, pos);
	}
	if (sm[pos->y * size.y + pos->x + 1] != '1')
	{
		sm[pos->y * size.y + pos->x + 1] = 'F';
		pos->x++;
		flood(sm, size, pos);
	}
	if (sm[(pos->y -1) * size.y + pos->x] != '1')
	{
		sm[(pos->y -1) * size.y + pos->x] = 'F';
		pos->y--;
		flood(sm, size, pos);
	}
	if (sm[(pos->y + 1) * size.y + pos->x] != '1')
	{
		sm[(pos->y + 1) * size.y + pos->x] = 'F';
		pos->y++;
		flood(sm, size, pos);
	}
}

void	lookstring(char	*sm)
{
	int	i;

	i = 0;
	while (sm)
	{
		if (sm[i] == 'C' || sm[i] == 'E')
			ft_error("Error : Collectible / exit not reachable.\n");
		i++;
	}
}
