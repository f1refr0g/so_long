/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:06:10 by abeaudet          #+#    #+#             */
/*   Updated: 2023/03/29 20:37:57 by abeaudet         ###   ########.fr       */
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
		ft_import_img(&map);
		ft_load_img(&map);
		printf("main1\n");
		simulate_map(&map);
		printf("main2\n");
		print_img(&map);
		mlx_key_hook(map.mlx, &movement, &map);
		mlx_loop(map.mlx);
		ft_freeptr(map.img);
		ft_freeptr(map.player);
		if (map.sm)
			ft_freeptr(map.sm);
		printf("\nstep : %d", map.step);
		mlx_terminate(map.mlx);
	}
	else
		ft_error(WRG_ARG);
}
