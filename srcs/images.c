/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:13:29 by abeaudet          #+#    #+#             */
/*   Updated: 2023/03/14 17:43:02 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_texture_t	**ft_import_img(void)
{
	mlx_texture_t **img;

	ft_memset(&img, 0, sizeof(mlx_texture_t));
	img[WALL] = mlx_load_png(WALL_IMG);
	if (!img[WALL])
		ft_error(IMG_ERR);
	img[BG] = mlx_load_png(BG_IMG);
	if (!BG)
		ft_error(IMG_ERR);
	img[PLAYER] = mlx_load_png(PLAYER_IMG);
	if (img[PLAYER])
		ft_error(IMG_ERR);
	img[TACOS] = mlx_load_png(COL_IMG);
	if (!img[TACOS])
		ft_error(IMG_ERR);
	img[EXIT] = mlx_load_png(EXIT_IMG);
	if (!img[EXIT])
		ft_error(IMG_ERR);
	return (img);
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