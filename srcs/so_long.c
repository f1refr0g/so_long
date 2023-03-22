/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:06:10 by abeaudet          #+#    #+#             */
/*   Updated: 2023/03/22 03:20:02 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_map	map;

	printf("%d\n", argc);
	if (argc == 2)
	{
		ft_memset(&map, 0, sizeof(t_map));
		ft_check_ext(argv[1]);
		ft_map_init(argv[1], &map);
		map.mlx = mlx_init(map.width * 50, map.height * 50, "So_Long", false);
		printf("%d\n%d URHRU\n", map.height, map.width);
		ft_import_img(&map);
		ft_load_img(&map);
		print_img(&map);
		mlx_key_hook(map.mlx, &movement, &map);
		mlx_loop(map.mlx);
		printf("free sm \n");
		printf("after free\n");
		free(map.img);
		free(map.player);
		free(map.sm);
	}
	else
		ft_error(WRG_ARG);
}
