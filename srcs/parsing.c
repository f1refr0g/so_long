/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:05:46 by abeaudet          #+#    #+#             */
/*   Updated: 2023/03/21 19:24:13 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Verify that the map is a rectangle
static void	ft_squaremap(t_map *map)
{
	if (map->height * map->width != ((int)ft_strlen(map->stringmap)))
		ft_error("Map not rectangle or square \n");
}

//Verify file extension
void	ft_check_ext(char *file)
{
	size_t len;

	len = ft_strlen(file);
	if (ft_strncmp(file + len -4, ".ber", len) != 0)
		ft_error(WRONG_EXT);
}

//Verify that map is surrounded by wall
static void	ft_wallcheck(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(map->stringmap))
	{
		if (i < (size_t)map->width)
		{
			if (map->stringmap[i] != '1')
				ft_error("Map contour must be wall only. \n");
		}
		else if (i % map->width == 0 || i % map->width == map->width - 1)
		{
			if (map->stringmap[i] != '1')
				ft_error("Map contour must be wall only.\n");
		}
		else if (i > ft_strlen(map->stringmap) - map->width)
		{
			if (map->stringmap[i] != '1')
				ft_error("Map contour must be wall only.\n");
		}
		i++;
	}
}

// Check if the map requirement are met 
static void	ft_check_required(t_map *map)
{
	size_t		i;

	i = 0;
	while (i < ft_strlen(map->stringmap))
	{
		if (map->stringmap[i] == 'E')
			map->exit += 1;
		else if (map->stringmap[i] == 'C')
			map->collectible += 1;
		else if (map->stringmap[i] == 'P')
			map->playercount += 1;
		i++;
	}
	if (map->exit != 1)
		ft_error("Map must have one exit.\n");
	if (map->collectible <= 0)
		ft_error("Map must have at least one collectible.\n");
	if (map->playercount != 1)
		ft_error("Map must have one player.\n");
}

//Initiate map then validate it's okay
void	ft_map_init(char *file, t_map *map)
{
	// map->collectible = 0;
	// map->player = 0;
	// map->exit = 0;
	// map->x = 0;
	// map->y = 0;
	// map->height = 0;
	// map->width = 0;
	// map->step = 0;
	read_map(file, map);
	ft_squaremap(map);
	ft_wallcheck(map);
	ft_check_required(map);
}
