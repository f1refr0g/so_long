/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:52:32 by abeaudet          #+#    #+#             */
/*   Updated: 2023/03/31 02:20:30 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Floodfill recrusive function to check if collectible are accessible
void	flood(char *sm, t_vector2 size, t_vector2 pos)
{
	if (sm[pos.y * size.x + pos.x - 1] != '1'
		&& sm[pos.y * size.x + pos.x - 1] != 'F')
	{
		sm[pos.y * size.x + pos.x - 1] = 'F';
		pos.x -= 1;
		flood(sm, size, pos);
	}
	if (sm[(pos.y -1) * size.x + pos.x] != '1'
		&& sm[(pos.y -1) * size.x + pos.x] != 'F')
	{
		sm[(pos.y -1) * size.x + pos.x] = 'F';
		pos.y -= 1;
		flood(sm, size, pos);
	}
	flood2(sm, size, pos);
}

//Second function to floodfill.
void	flood2(char *sm, t_vector2 size, t_vector2 pos)
{
	if (sm[pos.y * size.x + pos.x + 1] != '1'
		&& sm[pos.y * size.x + pos.x + 1] != 'F')
	{
		sm[pos.y * size.x + pos.x + 1] = 'F';
		pos.x += 1;
		flood(sm, size, pos);
	}
	if (sm[(pos.y + 1) * size.x + pos.x] != '1'
		&& sm[(pos.y + 1) * size.x + pos.x] != 'F')
	{
		sm[(pos.y + 1) * size.x + pos.x] = 'F';
		pos.y += 1;
		flood(sm, size, pos);
	}
}

//Verify the flooded string to see if there is any E or C left.
//If not then map is valid.
void	lookstring(char	*sm)
{
	size_t	i;

	i = 0;
	while (sm && i < ft_strlen(sm))
	{
		if (sm[i] == 'C' || sm[i] == 'E')
			ft_error("Error : Collectible / exit not reachable.\n");
		i++;
	}
}

//Function to create a temp stringmap for the flood function.
void	simulate_map(t_map *map)
{
	char		*temp_map;
	t_vector2	pos;
	t_vector2	mapsize;

	pos.y = map->player->y;
	pos.x = map->player->x;
	mapsize.x = map->width;
	mapsize.y = map->height;
	temp_map = ft_strdup(map->sm);
	flood(temp_map, mapsize, pos);
	lookstring(temp_map);
	free(temp_map);
}
