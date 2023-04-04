/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:07:28 by abeaudet          #+#    #+#             */
/*   Updated: 2023/04/04 18:31:20 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Function that receive keyn put and call the move function.
void	movement(mlx_key_data_t keydata, void *param)
{
	t_map	*map;

	map = (t_map *) param;
	if (keydata.key == MLX_KEY_W && keydata.action
		== MLX_PRESS && check_pos(map, UP) == 1)
	{
		ft_move(map, 'y', -50);
	}
	if (keydata.key == MLX_KEY_S && keydata.action
		== MLX_PRESS && check_pos(map, DOWN) == 1)
	{
		ft_move(map, 'y', 50);
	}
	if (keydata.key == MLX_KEY_A && keydata.action
		== MLX_PRESS && check_pos(map, LEFT) == 1)
	{
		ft_move(map, 'x', -50);
	}
	if (keydata.key == MLX_KEY_D && keydata.action
		== MLX_PRESS && check_pos(map, RIGHT) == 1)
	{
		ft_move(map, 'x', 50);
	}
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(0);
}

//Function that move the player 
void	ft_move(t_map *map, char axis, int dst)
{
	if (axis == 'y')
	{
		map->player->player->instances[0].y += dst;
		map->player->y += dst / 50;
		map->step++;
		collect(map);
	}
	if (axis == 'x')
	{
		map->player->player->instances[0].x += dst;
		map->player->x += dst / 50;
		map->step++;
		collect(map);
	}
	printf("Number of move : %d\n", map->step);
}

//check if player can proceed to next tile
int	check_pos(t_map *map, int direction)
{
	if (direction == LEFT)
	{
		if (map->sm[map->player->y * map->width + map->player->x -1] == '1')
			return (0);
	}
	if (direction == RIGHT)
	{
		if (map->sm[map->player->y * map->width + map->player->x + 1] == '1')
			return (0);
	}
	if (direction == UP)
	{
		if (map->sm[(map->player->y -1) * map->width + map->player->x] == '1')
			return (0);
	}
	if (direction == DOWN)
	{
		if (map->sm[(map->player->y +1) * map->width + map->player->x] == '1')
			return (0);
	}
	return (1);
}

//Function call for everymove to verify if player step on collectible.
void	collect(t_map *map)
{
	int	i;
	int	col_x;
	int	col_y;

	i = -1;
	col_x = 0;
	col_y = 0;
	while (++i < map->collectible)
	{
		// col_y = map->img->collectible->instances[i].y / 50;
		col_y = map->cc->y[i] / 50;
		// printf("coly : %d\n", map->img->collectible->instances[i].y / 50);
		// col_x = map->img->collectible->instances[i].x / 50;
		col_x = map->cc->x[i] / 50;
		// printf("colx : %d\n", map->img->collectible->instances[i].x / 50);
		if (col_y == map->player->y && col_x == map->player->x)
		{
				map->collectible--;
			// map->img->collectible->instances[i].enabled = false;
			map->colindex[i][0].enabled = false;
		}
	}
	if (map->collectible == 0)
	{
		if (map->img->exit->instances[0].y / 50 == map->player->y && \
			map->img->exit->instances[0].x / 50 == map->player->x)
			ft_exit(map);
	}
}

int	check_col_pos(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->img->collectible->count)
	{
		if (map->img->collectible->instances[i].y / 50 == map->player->y
			&& map->img->collectible->instances[i].x / 50 == map->player->x)
			return (i);
	i++;
	}
	return (0);
}
