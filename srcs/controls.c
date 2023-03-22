/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:07:28 by abeaudet          #+#    #+#             */
/*   Updated: 2023/03/22 03:11:12 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement(mlx_key_data_t keydata, void *param)
{
	t_map	*map;

	map = (t_map *) param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS && check_pos(map, UP) == 1)
	{
		map->player->player->instances[0].y -= 50;
		map->player->y -= 1;
		collect(map);
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS && check_pos(map, DOWN) == 1)
	{
		map->player->player->instances[0].y += 50;
		map->player->y += 1;
		collect(map);
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS && check_pos(map, LEFT) == 1)
	{
		map->player->player->instances[0].x -= 50;
		map->player->x -= 1;
		collect(map);
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS && check_pos(map, RIGHT) == 1)
	{
		map->player->player->instances[0].x += 50;
		map->player->x += 1;
		collect(map);
	}
}

int	check_pos(t_map *map, int direction)
{
	if (direction == LEFT)
	{
		if (map->stringmap[map->player->y * map->width + map->player->x -1] == '1')
			return (0);
	}
	if (direction == RIGHT)
	{
		if (map->stringmap[map->player->y * map->width + map->player->x + 1] == '1')
			return (0);
	}
	if (direction == UP)
	{
		if (map->stringmap[(map->player->y -1) * map->width + map->player->x] == '1')
			return (0);
	}
	if (direction == DOWN)
	{
		if (map->stringmap[(map->player->y +1) * map->width + map->player->x] == '1')
			return (0);
	}
	return (1);
}

void	collect(t_map *map)
{
	int	i;
	int	col_x;
	int	col_y;

	i = 0;
	col_x = 0;
	col_y = 0;
	while (i <= map->collectible)
	{
		col_y = map->img->collectible->instances[i].y / 50;
		col_x = map->img->collectible->instances[i].x / 50;
		if (col_y == map->player->y && col_x == map->player->x)
		{
				map->collectible--;
				map->img->collectible->instances[i].enabled = false;
		}
		i++;
	}
	printf("%d", map->collectible);
	if (map->collectible == 0)
	{
		if (map->img->exit->instances[0].y / 50 == map->player->y && map->img->exit->instances[0].x / 50 == map->player->x)
		{
			printf("\nBRAVO VOUS AVEZ GAGNEZ\n");
			mlx_close_window(map->mlx);
		}
	}
}
