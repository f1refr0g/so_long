/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:13:29 by abeaudet          #+#    #+#             */
/*   Updated: 2023/03/22 03:10:47 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_import_img(t_map *map)
{
	printf("import 2\n");
	map->img = ft_malloc(sizeof(t_img), 1);
	map->player = ft_malloc(sizeof(t_player), 1);
	map->img->t_wall = mlx_load_xpm42(WALL_IMG);
	if (map->img->t_wall == NULL)
		ft_error("1\n");
	map->img->t_background = mlx_load_xpm42(BG_IMG);
	if (map->img->t_background == NULL)
		ft_error("2\n");
	map->player->t_player = mlx_load_xpm42(PLAYER_IMG);
	if (map->player->t_player == NULL)
		ft_error("3\n");
	map->img->t_collectible = mlx_load_xpm42(COL_IMG);
	if (map->img->t_collectible == NULL)
		ft_error("4\n");
	map->img->t_exit = mlx_load_xpm42(EXIT_IMG);
	if (map->img->t_exit == NULL)
		ft_error("5\n");
}

void	ft_load_img(t_map *map)
{
	printf("test load 1\n");
	map->img->wall = mlx_texture_to_image(map->mlx, &map->img->t_wall->texture);
	if (!map->img->wall)
		ft_error("t1");
	printf("test laod 2\n");
	map->img->background = mlx_texture_to_image(map->mlx, &map->img->t_background->texture);
	if (!map->img->background)
		ft_error("t2");
	map->img->collectible = mlx_texture_to_image(map->mlx, &map->img->t_collectible->texture);
	if (!map->img->collectible)
		ft_error("t3");
	map->player->player = mlx_texture_to_image(map->mlx, &map->player->t_player->texture);
	if (!map->img->player)
		ft_error("t4");
	map->img->exit = mlx_texture_to_image(map->mlx, &map->img->t_exit->texture);
	if (!map->img->exit)
		ft_error("t5");
}

void	print_img(t_map *map)
{
	int	x;
	int	y;
	int	i;

	printf("p1\n");
	y = 0;
	i = 0;
	printf("%d\n", map->height);
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->stringmap[i] == '0' || map->stringmap[i] == 'P' || map->stringmap[i] == 'C' || map->stringmap[i] == 'E')
				mlx_image_to_window(map->mlx, map->img->background, x * 50, y * 50);
			if (map->stringmap[i] == '1')
				mlx_image_to_window(map->mlx, map->img->wall, x * 50, y * 50);
			if (map->stringmap[i] == 'C')
				mlx_image_to_window(map->mlx, map->img->collectible, x * 50, y * 50);
			if (map->stringmap[i] == 'E')
				mlx_image_to_window(map->mlx, map->img->exit, x * 50, y * 50);
			if (map->stringmap[i] == 'P')
			{
				map->player->x = x;
				map->player->y = y;
			}
			x++;
			i++;
		}
	y++;
	}
	mlx_image_to_window(map->mlx, map->player->player, map->player->x * 50, map->player->y * 50);
}
