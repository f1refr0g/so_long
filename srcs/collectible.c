/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:27:56 by abeaudet          #+#    #+#             */
/*   Updated: 2023/04/04 18:43:32 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//create a pointer to every instance of the collectible on the map
// void	create_index(t_map *map)
// {
// 	int	i;

// 	i = 0;
// 	map->colindex = malloc(sizeof(mlx_instance_t *) * 1);
// 	if (!map->colindex)
// 		ft_error(MALLOCERR);
// 	while (i < map->collectible)
// 	{
// 	map->colindex[i] = malloc(sizeof(mlx_instance_t));
// 		if (!map->colindex[i])
// 			ft_error(MALLOCERR);
// 	map->colindex[i][0] = map->img->collectible->instances[i];
// 	i++;
// 	}
// }

// void	create_index_nm(t_map *map)
// {
// 	int	i;

// 	i = 0;
// 	printf("baba");
// 	map->cc = ft_malloc(sizeof(t_colcoord),map->collectible);
// 	// if (map->cc)
// 	// 	ft_error(MALLOCERR);
// 	while (i < map->collectible)
// 	{
// 		printf("totue");
// 		map->colindex[i][0] = map->img->collectible->instances[i];
// 		map->cc->x[i] = map->img->collectible->instances[i].x;
// 		map->cc->y[i] = map->img->collectible->instances[i].y;
// 		i++;
// 	}
// }