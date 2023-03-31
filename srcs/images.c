/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:13:29 by abeaudet          #+#    #+#             */
/*   Updated: 2023/03/31 02:36:40 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// load texture to the struct.
void	ft_import_img(t_map *map)
{
	map->img->t_wall = mlx_load_xpm42(WALL_IMG);
	if (map->img->t_wall == NULL)
		ft_error(IMG_ERR);
	map->img->t_bg = mlx_load_xpm42(BG_IMG);
	if (map->img->t_bg == NULL)
		ft_error(IMG_ERR);
	map->player->tp = mlx_load_xpm42(PLAYER_IMG);
	if (map->player->tp == NULL)
		ft_error(IMG_ERR);
	map->img->t_collectible = mlx_load_xpm42(COL_IMG);
	if (map->img->t_collectible == NULL)
		ft_error(IMG_ERR);
	map->img->t_exit = mlx_load_xpm42(EXIT_IMG);
	if (map->img->t_exit == NULL)
		ft_error(IMG_ERR);
}

// convert texture to mlx img.
void	ft_load_img(t_map *map)
{
	map->img->wall = mlx_texture_to_image(map->mlx, &map->img->t_wall->texture);
	if (!map->img->wall)
		ft_error(IMG_ERR);
	map->img->bg = mlx_texture_to_image(map->mlx,
			&map->img->t_bg->texture);
	if (!map->img->bg)
		ft_error(IMG_ERR);
	map->img->collectible = mlx_texture_to_image(map->mlx,
			&map->img->t_collectible->texture);
	if (!map->img->collectible)
		ft_error(IMG_ERR);
	map->player->player = mlx_texture_to_image(map->mlx,
			&map->player->tp->texture);
	if (!map->player->player)
		ft_error(IMG_ERR);
	map->img->exit = mlx_texture_to_image(map->mlx, &map->img->t_exit->texture);
	if (!map->img->exit)
		ft_error(IMG_ERR);
}

//Print the map layout then the player.
void	print_img(t_map *map)
{
	int	x;
	int	y;
	int	i;

	y = -1;
	i = 0;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->sm[i])
				mlx_image_to_window(map->mlx, map->img->bg, x * 50, y * 50);
			if (map->sm[i] == '1')
				mlx_image_to_window(map->mlx, map->img->wall, x * 50, y * 50);
			if (map->sm[i] == 'C')
				mlx_image_to_window(map->mlx, \
				map->img->collectible, x * 50, y * 50);
			if (map->sm[i] == 'E')
				mlx_image_to_window(map->mlx, map->img->exit, x * 50, y * 50);
			i++;
		}
	}
	mlx_image_to_window(map->mlx, map->player->player, \
	map->player->x * 50, map->player->y * 50);
}
