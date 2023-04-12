/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:05:46 by abeaudet          #+#    #+#             */
/*   Updated: 2023/04/12 04:44:34 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Verify that the map is a rectangle
static void	ft_squaremap(t_map *map)
{
	if (map->height * map->width != ((int)ft_strlen(map->sm))
		&& (map->height * map->width) != ((int)(ft_strlen(map->sm) + 1)))
		ft_error("2Map not rectangle or square \n");
	map->sm[ft_strlen(map->sm)] = '1';
}

//Verify file extension
void	ft_check_ext(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (ft_strncmp(file + len -4, ".ber", len) != 0)
		ft_error(WRONG_EXT);
}

//Verify that map is surrounded by wall
static void	ft_wallcheck(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(map->sm))
	{
		if (i < (size_t)map->width)
		{
			if (map->sm[i] != '1')
				ft_error("Map contour must be wall only. \n");
		}
		else if (i % map->width == 0 || i % map->width == map->width - 1)
		{
			if (map->sm[i] != '1')
				ft_error("Map contour must be wall only.\n");
		}
		else if (i > ft_strlen(map->sm) - map->width)
		{
			if (map->sm[i] != '1')
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
	while (i < ft_strlen(map->sm))
	{
		if (map->sm[i] == 'E')
			map->exit += 1;
		else if (map->sm[i] == 'C')
			map->collectible += 1;
		else if (map->sm[i] == 'P')
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
	int	x;
	int	y;
	int	i;

	i = -1;
	y = -1;
	map->img = ft_malloc(sizeof(t_img), 1);
	map->player = ft_malloc(sizeof(t_tp), 1);
	read_map(file, map);
	ft_wallcheck(map);
	ft_squaremap(map);
	ft_checkchar(map);
	ft_check_required(map);
	map->step = 0;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->sm[++i] == 'P')
			{
				map->player->x = x;
				map->player->y = y;
			}
		}
	}
}
