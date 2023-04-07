/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:27:56 by abeaudet          #+#    #+#             */
/*   Updated: 2023/04/07 18:52:54 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Function called in the hook every move to refresh the map
void	refresh_map(t_map *map)
{
	if (map->sm[map->player->y * map->width + map->player->x] != 'E')
		map->sm[map->player->y * map->width + map->player->x] = '0';
	clear_img(map);
	ft_destroy(map);
	ft_import_img(map);
	ft_load_img(map);
	print_img(map);
}

//Clear the image to allow for refresh function
void	clear_img(t_map *map)
{
	mlx_delete_image(map->mlx, map->player->player);
	mlx_delete_image(map->mlx, map->img->bg);
	mlx_delete_image(map->mlx, map->img->collectible);
	mlx_delete_image(map->mlx, map->img->exit);
	mlx_delete_image(map->mlx, map->img->wall);
}
