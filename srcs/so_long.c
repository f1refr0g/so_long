/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:06:10 by abeaudet          #+#    #+#             */
/*   Updated: 2023/04/17 15:29:31 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc == 2)
	{
		ft_memset(&map, 0, sizeof(t_map));
		ft_check_ext(argv[1]);
		ft_map_init(argv[1], &map);
		map.mlx = mlx_init(map.width * 50, map.height * 50, "So_Long", false);
		ft_import_img(&map);
		simulate_map(&map);
		ft_load_img(&map);
		check_size(&map);
		print_img(&map);
		mlx_key_hook(map.mlx, &movement, &map);
		mlx_loop(map.mlx);
		ft_exit(&map);
	}
	else
		ft_error(WRG_ARG);
	return (0);
}
