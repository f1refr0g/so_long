/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:13:29 by abeaudet          #+#    #+#             */
/*   Updated: 2023/03/14 19:53:28 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_import_img(t_map *map)
{


	map->img->t_wall = mlx_load_png(WALL_IMG);
	if (map->img->t_wall == NULL)
		ft_error(IMG_ERR);
	map->img->t_background = mlx_load_png(BG_IMG);
	if (map->img->t_background == NULL)
		ft_error(IMG_ERR);
	map->img->t_player = mlx_load_png(PLAYER_IMG);
	if (map->img->t_player == NULL)
		ft_error(IMG_ERR);
	map->img->t_collectible = mlx_load_png(COL_IMG);
	if (map->img->t_collectible == NULL)
		ft_error(IMG_ERR);
	map->img->t_exit = mlx_load_png(EXIT_IMG);
	if (map->img->t_exit)
		ft_error(IMG_ERR);


}

void	ft_load_img(t_map *map, mlx_texture_t **img)
{
	map->img->wall = mlx_texture_to_image(map->mlx,img[WALL]);
	if (!map->img->wall)
		ft_error(IMG_ERR);
	map->img->background = mlx_texture_to_image(map->mlx, img[BG]);
	if (!map->img->background) 
		ft_error(IMG_ERR);
	map->img->collectible = mlx_texture_to_image(map->mlx, img[TACOS]);
	if (!map->img->collectible)
		ft_error(IMG_ERR);
	map->img->player = mlx_texture_to_image(map->mlx, img[PLAYER]);
	if (!map->img->player)
		ft_error(IMG_ERR);
	map->img->exit = mlx_texture_to_image(map->mlx, img[EXIT]);
	if (!map->img->exit)
		ft_error(IMG_ERR);
}

void	print_img(t_map *map)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			mlx_image_to_window(map->mlx, map->img->background, x * 50, y * 50);
			x++;
		}
	y++;
	}
}